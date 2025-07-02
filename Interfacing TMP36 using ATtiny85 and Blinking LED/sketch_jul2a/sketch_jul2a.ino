const int sensorPin = A2, r = 0, b = 1, g = 2;
float t;
float voltage;
float vout;

bool yellow[] = {1, 1, 0}, red[] = {1, 0, 0}, blue[] = {0, 0, 1};
bool green[] = {0, 1, 0}, cyan[] = {0, 1, 1}, white[] = {1, 1, 1}, purple[] = {1, 0, 1};
bool off[] = {0, 0, 0};

void setup() {
  pinMode(r, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(5, OUTPUT); // ATTiny Reset Pin
  digitalWrite(5, HIGH);
}

void loop() {
  vout = analogRead(sensorPin);
  voltage = (vout * 3.0) / 1024.0;       // Convert to actual voltage
  t = (voltage - 0.5) * 100.0;           // TMP36 conversion
  colorConditions();
}

void colorConditions() {
  bool* color[] = {purple, blue, cyan, green, white, yellow, red};
  float temp[] = {-40, 10, 15, 21, 25, 30, 35, 126};

  for (int i = 0; i < 7; i++) {
    if (t >= temp[i] && t < temp[i+1]) {
      ledControl(color[i]);
      delay(500);
  	  ledControl(off);
 	  delay (500) ;
    }
  }
}

void ledControl(bool color[]) {
  digitalWrite(r, color[0]);
  digitalWrite(g, color[1]);
  digitalWrite(b, color[2]);
}