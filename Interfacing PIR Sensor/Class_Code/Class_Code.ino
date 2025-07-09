#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int calibrationTime = 5;  // Set calibration time in seconds

// the time when the sensor outputs a low impulse
long unsigned int lowIn;

// the amount of milliseconds the sensor has to be low
// before we assume all motion has stopped
long unsigned int pause = 5000;

boolean lockLow = true;
boolean takeLowTime;
int pir = 3;
int led = 2;

void setup() {
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  lcd.init();         // Initialize I2C LCD
  lcd.backlight();    // Turn on backlight
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
  lcd.print("SENSOR ACTIVE");
  delay(2000);
}

void loop() {
  if (digitalRead(pir) == HIGH) {
    digitalWrite(led, HIGH);
    if (lockLow) {
      lockLow = false;
      lcd.clear();
      lcd.print("Motion Detected");
      lcd.setCursor(0, 1);
      lcd.print("at ");
      lcd.print((millis() / 1000));
      lcd.print(" sec");
      delay(50);
    }
    takeLowTime = true;
  }

  if (digitalRead(pir) == LOW) {
    digitalWrite(led, LOW);
    if (takeLowTime) {
      lowIn = millis(); // save the time of transition from HIGH to LOW
      takeLowTime = false;
    }
    // if the sensor is low for more than the given pause;
    // we assume that no motion is going to happen
    if (!lockLow && millis() - lowIn > pause) {
      // makes sure this block of code is only executed again after
      // a new motion sequence has been detected
      lockLow = true;
      lcd.clear();
      lcd.print("Motion ended at");
      lcd.setCursor(0, 1);
      lcd.print((millis() - pause) / 1000);
      lcd.print(" sec");
      delay(50);
    }
  }
}
