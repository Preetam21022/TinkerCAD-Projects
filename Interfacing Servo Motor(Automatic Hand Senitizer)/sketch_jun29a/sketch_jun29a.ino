#include <Servo.h>
#define trig 2
#define echo 3
#define servo 5//any pwm pin

Servo myservo;
//signal pin must connect to a pwm pin
//to control servo using time period we need Servo.writeicroseconds();
//like when the the time is 1 ms it will rotate anticlockwise
//when the time is 1.5 it will stop and when it is 2ms it will rotate clockwise
//or we can specify our desired angular position by using Servo.write();
//like when we say 0 it will rotate anticlockwise
//when we sa 180 it will rotate clockwise
//when we say 90 it will stop rotating
void setup() {
  myservo.attach(servo);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo,HIGH);
  float distance = (0.034*duration)/2;
  Serial.print("Distance: ");

  if (distance >= 4 || distance <= 2) {
    Serial.println("Out of range");
    myservo.detach();
  }

  else {
    myservo.attach(servo);
    myservo.write(0);
    delay(1000);
    myservo.write(90);
    delay(1000);
    myservo.write(180);
    delay(1000);
    myservo.write(90);

    Serial.print(distance);
    Serial.println("cm");
    delay(500);
  }

  delay(500);
  myservo.detach();
}
//ekbar clockwise arekbar anticlock wise ghurbe