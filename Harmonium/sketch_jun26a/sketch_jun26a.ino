/* float melody[] = {261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88, 523.25}; */
int buttonPins[] = {A4, A5, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
/*
const char* noteNames[] = {
  "Sa", "Re*", "Re", "Ga*", "Ga",
  "Ma", "Ma*", "Pa", "Dha*", "Dha",
  "Ni*", "Ni", "Sa*"
};
*/

int b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12;
const int bP = 13;  // bP = buzzerPin
int n = sizeof(buttonPins) / sizeof(buttonPins[0]);
int ndl = 500;

struct Note {
  const char* name;  // Indian name
  float freq;        // Frequency in Hz
};

// Define all notes with names and frequencies
Note notes[] = {
  {"Sa", 261.63},
  {"Re*", 277.18},
  {"Re", 293.66},
  {"Ga*", 311.13},
  {"Ga", 329.63},
  {"Ma", 349.23},
  {"Ma*", 369.99},
  {"Pa", 392.00},
  {"Dha*", 415.30},
  {"Dha", 440.00},
  {"Ni*", 466.16},
  {"Ni", 493.88},
  {"Sa*", 523.25}
};

void setup() {
  Serial.begin(9600);
  pinMode(bP, OUTPUT);
  for (int i = 0; i < n; i++) {
    pinMode(buttonPins[i], INPUT);  // Use pull-up to avoid needing external resistors
  }
}

void loop() {
  b0  = digitalRead(buttonPins[0]);
  b1  = digitalRead(buttonPins[1]);
  b2  = digitalRead(buttonPins[2]);
  b3  = digitalRead(buttonPins[3]);
  b4  = digitalRead(buttonPins[4]);
  b5  = digitalRead(buttonPins[5]);
  b6  = digitalRead(buttonPins[6]);
  b7  = digitalRead(buttonPins[7]);
  b8  = digitalRead(buttonPins[8]);
  b9  = digitalRead(buttonPins[9]);
  b10 = digitalRead(buttonPins[10]);
  b11 = digitalRead(buttonPins[11]);
  b12 = digitalRead(buttonPins[12]);

  delay(100);
  if (b0 == 1) {
    Serial.println(String(notes[0].name) + ": " + notes[0].freq);
    tone(bP, notes[0].freq, ndl);
  }

  if (b1 == 1) {
    Serial.println(String(notes[1].name) + ": " + notes[1].freq);
    tone(bP, notes[1].freq, ndl);
  }

  if (b2 == 1) {
    Serial.println(String(notes[2].name) + ": " + notes[2].freq);
    tone(bP, notes[2].freq, ndl);
  }

  if (b3 == 1) {
    Serial.println(String(notes[3].name) + ": " + notes[3].freq);
    tone(bP, notes[3].freq, ndl);
  }

  if (b4 == 1) {
    Serial.println(String(notes[4].name) + ": " + notes[4].freq);
    tone(bP, notes[4].freq, ndl);
  }

  if (b5 == 1) {
    Serial.println(String(notes[5].name) + ": " + notes[5].freq);
    tone(bP, notes[5].freq, ndl);
  }

  if (b6 == 1) {
    Serial.println(String(notes[6].name) + ": " + notes[6].freq);
    tone(bP, notes[6].freq, ndl);
  }

  if (b7 == 1) {
    Serial.println(String(notes[7].name) + ": " + notes[7].freq);
    tone(bP, notes[7].freq, ndl);
  }

  if (b8 == 1) {
    Serial.println(String(notes[8].name) + ": " + notes[8].freq);
    tone(bP, notes[8].freq, ndl);
  }

  if (b9 == 1) {
    Serial.println(String(notes[9].name) + ": " + notes[9].freq);
    tone(bP, notes[9].freq, ndl);
  }

  if (b10 == 1) {
    Serial.println(String(notes[10].name) + ": " + notes[10].freq);
    tone(bP, notes[10].freq, ndl);
  }

  if (b11 == 1) {
    Serial.println(String(notes[11].name) + ": " + notes[11].freq);
    tone(bP, notes[11].freq, ndl);
  }

  if (b12 == 1) {
    Serial.println(String(notes[12].name) + ": " + notes[12].freq);
    tone(bP, notes[12].freq, ndl);
  }
}
