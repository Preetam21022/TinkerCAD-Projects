int bulb = 3;                   // Pin 3 is connected to the bulb (or LED)
int potentiometer = A0;        // A0 is connected to the potentiometer
int potentiometervalue;        // Variable to store the potentiometer value

void setup() {
  pinMode(bulb, OUTPUT);       // Set the bulb pin as an output
  pinMode(potentiometer, INPUT);//Set potentiometer pin as input
  Serial.begin(9600);
}

void loop() {
  potentiometervalue = analogRead(potentiometer); // Read the analog value from the potentiometer (0–1023)
  potentiometervalue = map(potentiometervalue, 0, 1023, 0, 255); // Map it to PWM range (0–255)
  analogWrite(bulb, potentiometervalue); // Output the mapped value to the bulb for brightness control
  Serial.print("You are writing a value of ");
  Serial.println(potentiometervalue);
}


/*
int potPin= A0;
// Declare potPin to be analog pin A0

int LEDPin= 3;
// Declare LEDPin to be arduino pin 3

int readValue;
// Use this variable to read Potentiometer

int writeValue;
// Use this variable for writing to LED

void setup() {
  pinMode (potPin, INPUT) ;
  // set potPin to be an input
  pinMode (LEDPin, OUTPUT); 
  // set LEDPin to be an OUTPUT
  Serial.begin (9600);
  // turn on Serial Port
}

void loop() {
  readValue = analogRead (potPin); 
  // Read the voltage on the Potentiometer (range: 0 to 1023)

  writeValue = (255./1023.) * readValue; 
  // Calculate Write Value for LED brightness (scale 0–255)
  // upper command takes a range of values from 0 to 1023 and converts to 0 to 255

  analogWrite (LEDPin, writeValue) ;
  // Write to the LED using PWM

  Serial.print ("You are writing a value of "); 
  // for debugging print to Serial Monitor
  Serial.println(writeValue);
}
*/