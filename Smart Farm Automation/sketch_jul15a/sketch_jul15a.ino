//ATtiny Code

const int PIR = 0;     // PB0 (PIR sensor input)
const int intruder = 1; // PB1 (output to Arduino)


void setup() {
  pinMode(PIR, INPUT);
  pinMode(intruder, OUTPUT);
  
  // Initialize outputs
  digitalWrite(intruder, LOW);
}

void loop() {
  delay(25);
  
  // PIR sensor handling
  if (digitalRead(PIR) == HIGH) {
    digitalWrite(intruder, HIGH);
  } else {
    digitalWrite(intruder, LOW);
  }
}