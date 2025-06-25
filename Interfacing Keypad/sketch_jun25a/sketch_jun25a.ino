#include <Keypad.h>
//#include <LiquidCrystal.h>

//LiquidCrystal lcd(13,12,11,10,9,8);
const byte ROWS = 4;
const byte COLS = 4;

char Keys[ROWS][COLS]{
  {'1','2','3','A'} , {'4','5','6','B'},
  {'7','8','9','C'} , {'*','0','#','D'}
};
byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};
//In case of lcd display we can use pin 0,1
/*
byte rowPins[ROWS] = {7,6,5,4};
byte colPins[COLS] = {3,2,1,0};
*/


Keypad keypad = Keypad(makeKeymap(Keys), rowPins, colPins, ROWS, COLS); 

void setup()
{
 // lcd.begin(16,2);
 Serial.begin(9600);
}

void loop()
{
  char key = keypad.getKey();

  if(key)
  {
    Serial.print("Key Pressed: ");
    Serial.print(key);
    Serial.println();
    /*
    lcd.setCursor(0,0);
    lcd.print("Key Pressed: ");
    lcd.setCursor(0,1);
    lcd.print(key);
    */
  }
}
