#include <LiquidCrystal.h>

LiquidCrystal lcd(0, 1, 2, 3, 4, 5);

void setup() {
  lcd.begin(16, 2);
  lcd.print("I am Preetam");
  lcd.setCursor(0, 1);
  lcd.print("Hello!");
}

void loop() {
  lcd.setCursor(14, 1);
  lcd.print("  "); // Clear previous digits
  lcd.setCursor(14, 1);
  lcd.print(millis() / 1000);
  delay(1000); // Wait 1 second before updating again
}
