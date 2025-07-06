int led = 1;         // PWM-capable pin (like pin 0/1 on ATtiny85)
int pot = A3;        // Potentiometer input pin.Don't use pwm.
int pot_val = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(pot, INPUT);
}

void loop() {
  pot_val = analogRead(pot);                    // Read analog input (0–1023)
  pot_val = map(pot_val, 0, 1023, 0, 255);      // Scale to 0–255 for PWM
  analogWrite(led, pot_val);                    // Write brightness level
}
