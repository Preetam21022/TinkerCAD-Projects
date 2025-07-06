// C++ code
//
int pin[]={3,5,10};//just change the array after adding more pins to LEDs
int n = sizeof(pin) / sizeof(pin[0]);

void setup()
{
  for(int i=0; i<n; i++) { 
    pinMode(pin[i], OUTPUT);
  }
}

void loop()
{
  for(int i=0; i<n; i++) {
    digitalWrite(pin[i], HIGH);
    delay(300);
  }
  for(int i=0; i<n; i++) {
    digitalWrite(pin[i], LOW);
    delay(300);
  }
}