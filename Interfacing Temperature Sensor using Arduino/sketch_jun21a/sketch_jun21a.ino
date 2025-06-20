int temp = A0;
float temp_celsius;
float Voltage;
float analog_reading;
float temp_far;
void setup ()
{
pinMode (A0, INPUT); //set temp sensor as input
Serial.begin(9600);
}
void loop()
{
analog_reading = analogRead (A0) ;
Serial.print ("Analog reading:");//read analog reading
Serial.println (analog_reading) ;
//converting analog reading to voltage
Voltage = analog_reading*5/1024;
// we divide by 1024 as the analog reading from the data pin is between 0 and 10
// 5 because 5Volts;
Serial.print ("Voltage reading:"); //display Voltage
Serial.println (Voltage);
//reading in celsius:
//converting from 10 mv per degree with 0.5V offset
temp_celsius = 100* (Voltage - 0.5);
Serial.println("Celsius reading:" + String(temp_celsius) + (" °C"));
temp_far = (temp_celsius * 9/5) + 32;
  //we can use "string" to call the value
  //or we can just write "Serial.print(temp_celsius);"
  
Serial.println("Fahrenheit reading:" + String(temp_far) + (" °F\n"));
delay (3000) ; //give a delay of 3 seconds before repeating the loop
}
//scale factor=10 mV/°C
//offset value= 0.5 V
//input value 5V
//analog reading ranges from 0-1023.so multiply by 1024