int redPin = 9;    // Adjust as per your circuit
int greenPin = 7;
int bluePin = 6;
int t=500;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  for(int n = 255; n > 0; n=n-15) {

  setColor(0, 0, n);   // Blue
  delay(t);

  setColor(0, n, 0);   // Green
  delay(t);

  setColor(0, n, n);   // Cyan
  delay(t);

  setColor(n, 0, 0);   // Red
  delay(t);

  setColor(n, 0, n);   // Magenta
  delay(t);

  setColor(n, n, 0);   // Yellow
  delay(t);

  setColor(n, n, n);   // White
  delay(t);
  }
  
  setColor(0, 0, 0);   // Off
  delay(t);
}

void setColor(int redVal, int greenVal, int blueVal) {
  analogWrite(redPin, redVal);
  analogWrite(greenPin, greenVal);
  analogWrite(bluePin, blueVal);
}
