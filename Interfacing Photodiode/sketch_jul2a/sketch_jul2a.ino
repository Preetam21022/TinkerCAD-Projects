int pd = A0;
float val = 0;

void setup() {
  pinMode(pd, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(pd); // Read analog voltage value (scaled from 0 to 1023)
  // Convert analog value to voltage (0–5V range)
  float voltage = (val / 85) * 5.0;

  Serial.print("Analog Value: ");
  Serial.println(val);

  Serial.print("Voltage Value: ");
  Serial.print(voltage);
  Serial.println(" V");
}
//***map fuction gives intiger value as output***
