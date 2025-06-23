#include <LiquidCrystal.h>
bool alert = false; 


int gasSensor;
int blue=9;
int red=8;
int green=10;
int piezo=2;
int gas=A1;
double temperature;
double vout;//output value of the temperature sensor
double vout1;//when the temperature increases a new voltage will be produced
int t=A0;
LiquidCrystal lcd(13, 12, 4, 5, 6, 7);

/*
LiquidCrystal lcd(RS,E,DB pins from left to right order);
lcd db pins must be order from left to right. 
like for this project order is DB4>DB5>DB6>DB7. 
pin should be written in the bracket following this order.
We can use any digital pins for lcd pinout except 0,1
*/

void setup()
{
  pinMode(gas,INPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(piezo,OUTPUT);
  Serial.begin(9600);
  pinMode(A0,INPUT);
  lcd.begin(16, 2);
  lcd.print("Today's Temperat");
}

void loop()
{
  vout=analogRead(t);
  vout1=(vout/1024)*5;
  temperature=(vout1-.5)*100;
  gasSensor=analogRead(gas);
  /*
  Serial.print(temperature);
  Serial.print("°C");
  Serial.println();
  or we can use string;
  */
  String output1=String(temperature)+String(char(176))+"C";
  Serial.print(output1);
  Serial.print("  ");
  Serial.print(gasSensor);
  Serial.print(" ");
  Serial.println();
  
 lcd.setCursor(0, 1);
  /*
  lcd.print("ure: ");
  lcd.print(temperature);
  lcd.print(char(178));//178 is the code for ptinting degree
  lcd.print("C");
  
  or we can use string
  */

  String output="ure: "+String(temperature)+String(char(178))+"C";
  lcd.print(output);
  
  bool alert = false;
 digitalWrite(green,HIGH); 
if (temperature < 10) {
  digitalWrite(blue, HIGH);
  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("EMERGENCY:");
  lcd.setCursor(0,1);
  String output2="Low Temp: "+String(temperature)+String(char(178))+"C";
  lcd.print(output2);
  alert = true;
}
else if (temperature > 40) {
  digitalWrite(red, HIGH);
  digitalWrite(blue,LOW);
  digitalWrite(green,LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("EMERGENCY:");
  lcd.setCursor(0,1);
  String output3="HIGH Temp: "+String(temperature)+String(char(178))+"C";
  lcd.print(output3);
  alert = true;
} 
 else if (gasSensor>=100) {
  digitalWrite(red, HIGH);
  digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("EMERGENCY: Heavy");
  lcd.setCursor(0,1);
  String output4="Smoke||Temp: "+String(temperature)+String(char(178))+"C";
  lcd.print(output4);
  alert = true;
}

  else if (gasSensor>=100 && temperature > 40) {
  digitalWrite(red, HIGH);
  digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Fire Alert:Smoke");
  lcd.setCursor(0,1);
  String output4="High Temp: "+String(temperature)+String(char(178))+"C";
  lcd.print(output4);
  alert = true;
} else {
  digitalWrite(red, LOW);
    digitalWrite(blue,LOW);
    digitalWrite(green,HIGH);
}
  
  digitalWrite(piezo, alert ? HIGH : LOW);
  delay(1000);
}



 //for gas sensor use 1k resistance






/*
//Complementary Code:
#include <LiquidCrystal.h>
int gasSensor;
int blue=9;
int red=8;
int green=10;
int piezo=2;
int gas=A1;
double temperature;
double vout;//output value of the temperature sensor
double vout1;//when the temperature increases a new voltage will be produced
int t=A0;
LiquidCrystal lcd(13, 12, 4, 5, 6, 7);

void setup() {
  pinMode(gas,INPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(piezo,OUTPUT);
  Serial.begin(9600);
  pinMode(A0,INPUT);
  lcd.begin(16, 2);
  lcd.print("Today's Temperat");
}

void loop() {
  vout = analogRead(t);
  double voltage = (vout / 1024.0) * 5.0;
  temperature = (voltage - 0.5) * 100.0;
  gasSensor=analogRead(gas); 
 
  
  lcd.clear();  // Clear the whole display before printing
  
  if (temperature < -10) {
    // Emergency mode low temp
  digitalWrite(blue, HIGH);
  digitalWrite(green,LOW);
   digitalWrite(red,LOW);
  digitalWrite(piezo,HIGH);
  lcd.setCursor(0, 0);
  lcd.print("EMERGENCY:");
  lcd.setCursor(0,1);
  String output2="Low Temp: "+String(temperature)+String(char(178))+"C";
  lcd.print(output2);
  }
   else if (temperature > 40 && gasSensor<100) {
   //Emergency mode high temp
  digitalWrite(red, HIGH);
  digitalWrite(green,LOW);
     digitalWrite(blue,LOW);
  digitalWrite(piezo,HIGH);
  lcd.setCursor(0, 0);
  lcd.print("EMERGENCY:");
  lcd.setCursor(0,1);
  String output3="HIGH Temp: "+String(temperature)+String(char(178))+"C";
  lcd.print(output3);
  } 
  else if(gasSensor >=100 && temperature < 40)
  {//Emergency mode heavy smoke
    digitalWrite(red, HIGH);
  digitalWrite(green,LOW);
     digitalWrite(blue,LOW);
  digitalWrite(piezo,HIGH);
  lcd.setCursor(0, 0);
  lcd.print("EMERGENCY: Smoke");
  lcd.setCursor(0,1);
  String output4="Temp: "+String(temperature)+String(char(178))+"C";
  lcd.print(output4);
  } 
  else if (gasSensor>=100 && temperature > 40) {
  //emergency mode:fire alert
  digitalWrite(red, HIGH);
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Fire Alert:Smoke");
  lcd.setCursor(0,1);
  String output5="High Temp: "+String(temperature)+String(char(178))+"C";
  lcd.print(output5);
  }
  else {
    // Normal temperature display
    digitalWrite(green, HIGH);
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    digitalWrite(piezo, LOW);
	lcd.print("Today's Temperat");
    lcd.setCursor(0, 1);
	String output="ure: "+String(temperature)+String(char(178))+"C";
  	lcd.print(output);
  }
 String output1=String(temperature)+String(char(176))+"C";
  Serial.print(output1);
  Serial.print("\t");
  Serial.print(gasSensor);
  Serial.println();
  delay(1000);
}
*/