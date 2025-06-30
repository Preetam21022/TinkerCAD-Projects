int buzzer= 6;
int pir= 7;
int red= 2;
int blue= 3;
int green= 4;

void setup() {
  pinMode(pir, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  if(digitalRead(pir) == HIGH) {
    digitalWrite(buzzer, HIGH);
    RBG_color(0,255,0);//blue
	//as we use RCBG instead of RCGB LED, we have to write RBG_color = (0,255,0);
    //if we used the right sequence RCGB LED, we would write RGB_color = (0,0,255); as shown in the video
    while(digitalRead(pir) == HIGH);
  }
  else {
    digitalWrite(buzzer, LOW);
    RBG_color(255,255,0);//Magenta
    //as we use RCBG instead of RCGB LED, we have to write RBG_color = (255,0,255);
    //if we used the right sequence RCGB LED, we would write RGB_color = (255,255,0); as shown in the video
  }
}

void RBG_color(int red_value, int blue_value, int green_value) {
  digitalWrite(red, red_value);
  digitalWrite(blue, blue_value);
  digitalWrite(green, green_value);
}