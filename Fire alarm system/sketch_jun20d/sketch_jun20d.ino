//for gas sensor use 1k resistance
bool alert = false;

float temp;
float vout;//output value of the temperature sensor
float vout1;//when the temperature increases a new voltage will be produced
int gasSensor;
int LED=4;
int red=7;
int piezo=2;
int gas=A1;
int Tem=A0;
void setup()
{
  pinMode(gas,INPUT);
  pinMode(Tem,INPUT);
  pinMode(LED,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(piezo,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  vout=analogRead(Tem);
  vout1=(vout/1023)*5000;
  temp=(vout1-500)/10;
  gasSensor=analogRead(gas);

bool alert = false;

if (temp < 10) {
  digitalWrite(LED, HIGH);
  alert = true;
} else {
  digitalWrite(LED, LOW);
}

if (gasSensor >= 100 || temp > 40) {
  digitalWrite(red, HIGH);
  alert = true;
} else {
  digitalWrite(red, LOW);
}

digitalWrite(piezo, alert ? HIGH : LOW);

  
  Serial.print("in DegreeC= ");
  Serial.print(" ");
  Serial.print(temp);
  Serial.print("\t");
  Serial.print("GasSensor= ");
  Serial.print(" ");
  Serial.print(gasSensor);
  Serial.println();
  delay(1000);
}
