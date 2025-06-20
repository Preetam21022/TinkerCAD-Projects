//code is same led pin is different
//two sample projects in tinker cad 
int led=11;
void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(led,OUTPUT);
}

void loop()
{
  int val= analogRead(A0);
  Serial.println(val);
  delay(100);

int ldr=analogRead (A0);
ldr=map (ldr, 0,1023,0,255);
analogWrite(led, ldr); 
}