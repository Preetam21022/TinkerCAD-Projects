//Arduino Code

#include <LiquidCrystal.h>

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//alert buzz time
int n = 3;

//Intruder Tracking
int calibrationTime = 5;
long unsigned int lowIn;
long unsigned int pause = 2000;
long unsigned int startTime;

boolean lockLow = true;
boolean takeLowTime;
bool normal = true;

#define MAX_LOGS 20
unsigned int motionDetected[MAX_LOGS];
unsigned int motionEnded[MAX_LOGS];
int motionIndex = 0;

// Farm Pins
const int soilPin = A0;
const int lightSensor = A4;
const int tempSensor = A2;
const int humidPin = A1;
const int pumpPin = 9;
const int buzzPin = A5;
const int rpm = A3;
const int heatPumpPin = 8;
const int growLightPin = 13;
const int mistPin = 7;
const int curtainPin = 10;
//Intruder Pins
const int pir = 0;
const int bp = 6; // button pin
int bs = 0; // button state



void setup() {
  //normal farm
  pinMode(pumpPin, OUTPUT);
  pinMode(heatPumpPin, OUTPUT);
  pinMode(growLightPin, OUTPUT);
  pinMode(mistPin, OUTPUT);
  pinMode(curtainPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  //intruder
  pinMode(pir, INPUT);  // Added this line
  pinMode(bp, INPUT);  // Changed to INPUT_PULLUP for better button handling
  lcd.begin(16, 2);

  startTime = millis();
  Starting();
  //display
  
  Serial.begin(9600); 
  
}


void loop() {
    bs = digitalRead(bp);

  if (digitalRead(pir) == HIGH) {
    // Buzzer alert
    for (int i = 0; i < n; i++) {
      tone(buzzPin, 440, 220);
      delay(220);
      noTone(buzzPin);
      delay(150);
    }
    if (lockLow && normal) {
      lockLow = false;
      normal = false;

      unsigned int motionTime = (millis() - startTime) / 1000;
      if (motionIndex < MAX_LOGS) {
        motionDetected[motionIndex] = motionTime;
      }
      lcd.clear();
      lcd.print("Motion Detected");
      lcd.setCursor(0, 1);
      lcd.print("at ");
      lcd.print(motionTime);
      lcd.print(" sec");
      delay(50);
    }
    takeLowTime = true;
  }

  if (digitalRead(pir) == LOW) {
    if (takeLowTime) {
      lowIn = millis() - startTime;
      takeLowTime = false;
    }
    if (!lockLow && (millis() - startTime - lowIn) > pause) {
      lockLow = true;
      unsigned int endTime = (millis() - startTime - pause) / 1000;
      if (motionIndex < MAX_LOGS) {
        motionEnded[motionIndex] = endTime;
        motionIndex++;
      }
      lcd.clear();
      lcd.print("Motion ended at");
      lcd.setCursor(0, 1);
      lcd.print(endTime);
      lcd.print(" sec");
      delay(1000);
      lcd.clear();
      normal = true;
    }
  }

  if (bs == 1) { 
    print();
    startTime = millis();
    lcd.clear();
    lcd.print("Resetting");
    for (int i = 0; i < 4; i++) {
      lcd.print(".");
      delay(1000);
    }
    lcd.clear();
    lcd.print("Done");
    delay(1000);
    lcd.clear();
    lockLow = true;
    motionIndex = 0; // clear stored logs
    return;
  }

  // 🌿 Normal farm operation
  if (normal) {
    int soil = analogRead(soilPin);
    int lightRaw = analogRead(lightSensor);
    int tempRaw = analogRead(tempSensor);
    int humidRaw = analogRead(humidPin);

    int humid = map(humidRaw, 0, 1023, 0, 100);
    humid = constrain(humid, 0, 100);

    int brightness = map(lightRaw, 54, 974, 0, 100);
    brightness = constrain(brightness, 0, 100);

    float vout = analogRead(tempSensor);
    float voltage = (vout * 5.0) / 1024.0;
    float tempC = (voltage - 0.5) * 100.0;

    int speed = analogRead(rpm);
    speed = map(speed, 0, 1023, 0, 255);

    // Farm controls
    analogWrite(pumpPin, (soil < 400) ? speed : 0);
    digitalWrite(heatPumpPin, (tempC < 15 || tempC > 35));
    
    digitalWrite(mistPin, (tempC > 30 || humid < 40));

    if (brightness < 50) {
      digitalWrite(growLightPin, HIGH);
      digitalWrite(curtainPin, LOW);
    } else if (brightness > 70) {
      digitalWrite(growLightPin, LOW);
      digitalWrite(curtainPin, HIGH);
    } else {
      digitalWrite(growLightPin, LOW);
      digitalWrite(curtainPin, LOW);
    }

    if (tempC > 45 || tempC < 5 || humid < 20 || humid > 90) {
      tone(buzzPin, 440);
    } else {
      noTone(buzzPin);
    }

    // LCD Farm Display
    String line1="T:"+String(tempC)+String(char(178))+"C"+" L:"+String(brightness)+"%  ";
    String line2="H:"+String(humid)+"%"+" S:"+String(soil);
    lcd.setCursor(0, 0); lcd.print(line1);
    lcd.setCursor(0, 1); lcd.print(line2);

    Serial.print("Temp: "); Serial.print(tempC); Serial.print(char(176)); Serial.print("C, ");
    Serial.print("Light: "); Serial.print(lightRaw); Serial.print(", ");
    Serial.print("Humidity: "); Serial.print(humidRaw); Serial.print(", ");
    Serial.print("Soil: "); Serial.println(soil);

    delay(1000);
  }
}

void Starting() {
  lcd.setCursor(0, 0);
  lcd.print("Calibrating");
  lcd.setCursor(0, 1);
  lcd.print("System");
  for (int i = 0; i < calibrationTime; i++) {
    lcd.print(".");
    delay(1000);
  }
  lcd.clear();
  lcd.print("Done");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM ACTIVED");
  delay(2000);
  lcd.clear();
  normal = true;
}

void print() {
  Serial.println("Motion Log:");
  for (int i = 0; i < motionIndex; i++) {
    Serial.print("Motion ");
    Serial.print(i+1);
    Serial.print(": Start = ");
    Serial.print(motionDetected[i]);
    Serial.print(" sec, End = ");
    Serial.print(motionEnded[i]);
    Serial.println(" sec");
  }
  if (motionIndex == 0) {
    Serial.println("No motion detected yet.");
  }
}
