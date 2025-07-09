#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int calibrationTime = 5;
long unsigned int lowIn;
long unsigned int pause = 5000;
long unsigned int startTime;

boolean lockLow = true;
boolean takeLowTime;
int pir = 3;
int led = 2;
int bp = 4; // button pin
int bs = 0; // button state

#define MAX_LOGS 20
unsigned int motionDetected[MAX_LOGS];
unsigned int motionEnded[MAX_LOGS];
int motionIndex = 0;

void setup() {
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
  pinMode(bp, INPUT); 
  digitalWrite(led, LOW);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  startTime = millis();
  Starting();
}

void loop() {
  bs = digitalRead(bp);

  if (digitalRead(pir) == HIGH) {
    digitalWrite(led, HIGH);
    if (lockLow) {
      lockLow = false;
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
    digitalWrite(led, LOW);
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
      delay(50);
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
}

void Starting() {
  lcd.setCursor(0, 0);
  lcd.print("Calibrating");
  lcd.setCursor(0, 1);
  lcd.print("Sensor");
  for (int i = 0; i < calibrationTime; i++) {
    lcd.print(".");
    delay(1000);
  }
  lcd.clear();
  lcd.print("Done");
  lcd.setCursor(0, 1);
  lcd.print("SENSOR ACTIVED");
  delay(2000);
}

void print() {
    for (int i = 0; i < motionIndex; i++) {
    Serial.print("Motion ");
    Serial.print(i+1);
    Serial.print(": Start = ");
    Serial.print(motionDetected[i]);
    Serial.print(" sec, End = ");
    Serial.print(motionEnded[i]);
    Serial.println(" sec");
  }
}
