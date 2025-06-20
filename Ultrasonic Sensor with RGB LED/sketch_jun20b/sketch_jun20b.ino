int trig_pin=2, echo_pin=3, red_light=4, blue_light=5, green_light=6;
//can use single leds too
void setup()
{
  pinMode(red_light,OUTPUT);
  pinMode(blue_light,OUTPUT);
  pinMode(green_light,OUTPUT);
  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig_pin,LOW);
  delayMicroseconds(2);//extra
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin,LOW);

  long duration = pulseIn(echo_pin,HIGH);
  float distance= duration*0.034/2; //unit of v cm/microsecond
  Serial.print(distance);//serial print line
  Serial.println(" cm");
  delay(100);

   if(distance>=50 && distance<75)
  {
    digitalWrite(green_light,HIGH);
  }
  else
  digitalWrite(green_light,LOW);

   if(distance>=35 && distance<50)
  {
    digitalWrite(red_light, HIGH);
  }
  else
  digitalWrite(red_light,LOW);

  if(distance<35)
  {
    digitalWrite(blue_light,HIGH);
  }
  else
  digitalWrite(blue_light,LOW);
}