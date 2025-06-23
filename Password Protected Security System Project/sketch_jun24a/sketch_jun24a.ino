#include <Keypad.h>
const byte row=4;
const byte col=4;
const int red=3;
const int green=2;
const int piezo=13;
char numPad[row][col]{
  {'1','2','3'},{'4','5','6'},
  {'7','8','9'},{'*','0','#'}
};

byte rowPin[row]={11,10,9,8};//left to right:row 1 to row 4
byte colPin[col]={7,6,5,4};
String password="6556";
String vstup="";
Keypad cKeypad=Keypad(makeKeymap(numPad), rowPin, colPin, row, col);

void setup()
{
 pinMode(red, OUTPUT);
 pinMode(green,OUTPUT);
 pinMode(piezo,OUTPUT);
 digitalWrite(red,HIGH);
 Serial.begin(9600);
 Serial.print("Enter the password: ");
}

void loop()
{
 char cKey= cKeypad.getKey();

if (cKey) {
if(vstup.length() < 4) {
Serial.print ("*");
vstup += cKey;
}
}
if (vstup.length () == 4) {
delay (800);
  
if (password == vstup) {
Serial.println("\nWelcome");
digitalWrite (red, LOW);
digitalWrite (green, HIGH);
tone (piezo, 500) ;
delay (100);
noTone (piezo) ;
}

else {
Serial.println("\nWrong Passcode");
digitalWrite (red, HIGH);
digitalWrite(green, LOW) ;
tone (piezo, 1000) ;
delay (800) ;
tone (piezo, 1000) ;
delay (100) ;
noTone (piezo) ;
}

delay(800) ;
vstup ="";
Serial.println("Enter Passcode: ");
digitalWrite(red, HIGH);
digitalWrite(green, LOW) ;
}
}