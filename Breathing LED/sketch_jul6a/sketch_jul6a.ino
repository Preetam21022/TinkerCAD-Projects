void setup()
{
  pinMode(11, OUTPUT);
}

void loop()
{
  for(int i = 0; i<=255; i++) { 
  analogWrite(11, i);
  delay(20); // Wait for 1000 millisecond(s)
  }
  for (int i = 255; i >= 0; i--) {
  analogWrite(11, i);
  delay(20); // Wait for 1000 millisecond(s)
  }
  delay(200);
}