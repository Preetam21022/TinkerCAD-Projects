#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>

// LCD pin mapping: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

long first = 0;
long second = 0;
double total = 0;
char customKey;

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'c', '0', '=', '/'}
};

// Connect to the row pinouts of the keypad
byte rowPins[ROWS] = {7, 6, 5, 4};

// Connect to the column pinouts of the keypad
byte colPins[COLS] = {3, 2, 1, 0};

// Initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  lcd.begin(16, 2); // Start LCD
  for(int i=0; i<=3;i++);
  lcd.setCursor(0, 0);
    lcd.print("Calculator");
    lcd.setCursor(0, 1);
    lcd.print("Enter Numbers");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
}

void loop() {
  customKey = customKeypad.getKey(); // Read key from keypad

    switch (customKey) {
      case '0' ... '9': //  This keeps collecting the first value until an operator is pressed
        lcd.setCursor(0, 0);
        first = first * 10 + (customKey - '0');
        lcd.print(first);
        break;

      case '+':
        first = (total != 0 ? total : first); 
        //lcd.setCursor(0,1);
        lcd.print("+");
        second = SecondNumber(); // Get the second number from keypad

        total = first + second;
        lcd.setCursor(0, 3);
        lcd.print(total);
        first = 0,second = 0; // Reset values back to zero for next calculation
        break;

      case '-':
        first = (total != 0 ? total : first);
        //lcd.setCursor(0,1);
        lcd.print("-");
        second = SecondNumber();
        total = first - second;
        lcd.setCursor(0, 3);
        lcd.print(total);
        first = 0,second = 0;
        break;

      case '*':
        first = (total != 0 ? total : first);
        //lcd.setCursor(0,1);
        lcd.print("*");
        second = SecondNumber();
        total = first * second;
        lcd.setCursor(0, 3);
        lcd.print(total);
        first = 0,second = 0;
        break;

      case '/':
        first = (total != 0 ? total : first);
        //lcd.setCursor(0,1);
        lcd.print("/");
        second = SecondNumber();
        lcd.setCursor(0, 3);
        second == 0 ? lcd.print("INVALID") : total = (float)first / (float)second;
        lcd.print(total);
        first = 0,second = 0;
        break;

      case 'c': // Clear everything when 'c' is pressed
        total = 0;
        lcd.clear();
        break;
    }
  }


long SecondNumber() {
  while (1) {
    customKey = customKeypad.getKey();
    if (customKey >= '0' && customKey <= '9') {
      second = second * 10 + (customKey - '0');
      lcd.setCursor(7, 0);
      lcd.print(second);
    }
    if (customKey == '=') break; //return seconds
  }
  return second;
}
