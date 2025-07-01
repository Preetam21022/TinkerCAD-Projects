#include <Keypad.h>
#include <LiquidCrystal.h>

int dr = 2000; // delay time of red light
int dy = 1000; // delay time of yellow light
int dg = 2000; // delay time of green light

bool pass = false; // password mode
bool input = false; // input mode (edit delay)

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
int r = 13, g = 12, pr = 9, py = 10, pg = 11;

const byte ROWS = 4;
const byte COLS = 4;
int piezo = 8;
char cKey;
String password = "6556";
String vstup = "";

char numPad[ROWS][COLS] = {
  {'1','2','3','R'},
  {'4','5','6','Y'},
  {'7','8','9','G'},
  {'*','0','#','C'}
};

byte rowPin[ROWS] = {7,6,5,4};
byte colPin[COLS] = {3,2,1,0};
Keypad cKeypad = Keypad(makeKeymap(numPad), rowPin, colPin, ROWS, COLS);

void setup() {
  pinMode(g, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(pr, INPUT);
  pinMode(py, INPUT);
  pinMode(pg, INPUT);
  pinMode(piezo, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
}

void loop() {
  cKey = cKeypad.getKey();

  switch (cKey) {
    case '*':
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter Passcode:");
      lcd.setCursor(0, 1);
      vstup = "";
      pass = true;
      input = false;
      break;

    case '0' ... '9':
      if (pass && !input) {
        if (vstup.length() < 4) {
          lcd.print("*");
          vstup += cKey;
        }
        if (vstup.length () == 4 && pass) {
        delay (800);
        if (password == vstup) {
        lcd.clear();
        lcd.print("Welcome: Delay");
        lcd.setCursor(0,1);
        lcd.print("Editing Enabled");
        digitalWrite (r, LOW);
        digitalWrite (g, HIGH);
        tone (piezo, 500) ;
        delay (500);
        noTone (piezo) ;
        lcd.clear();
        pass=false;
        input=true; //if password is true then ou can change delay time
          //giving permission to change delay time
        }

        else {
        lcd.clear();
        lcd.print("Wrong Passcode");


        digitalWrite (r, HIGH);
        digitalWrite(g, LOW) ;
        tone (piezo, 1000) ;
        delay (800) ;
        tone (piezo, 1000) ;
        delay (100) ;
        noTone (piezo) ;
        lcd.clear();
        lcd.print("Enter Passcode: ");
        lcd.setCursor(0,1);
        }

        delay(800) ;
        vstup ="";
        

        digitalWrite(r,LOW);
        digitalWrite(g,LOW);
        }
    }
    break;

    case 'R':
    case 'Y':
    case 'G':
      if (input && !pass) {
        lcd.clear();
        switch (cKey) {
          case 'R':
            lcd.print("Red Delay:");
            dr = getDelay();
            break;
          case 'Y':
            lcd.print("Yellow Delay:");
            dy = getDelay();
            break;
          case 'G':
            lcd.print("Green Delay:");
            dg = getDelay();
            break;
        }
        lcd.clear();
      }
      break;
  }


  // Default traffic mode
  if (!pass) {
    int br = digitalRead(pr);
    int by = digitalRead(py);
    int bg = digitalRead(pg);
    lcd.setCursor(0, 0);
    lcd.clear();

    if (br == 1 && by == 0 && bg == 0) {
      lcd.print("STOP!");
      digitalWrite(r, HIGH);
      digitalWrite(g, LOW);
      delay(dr);
    } else if (br == 0 && by == 1 && bg == 0) {
      lcd.print("Get Ready");
      digitalWrite(r, HIGH);
      digitalWrite(g, HIGH);
      delay(dy);
    } else if (br == 0 && by == 0 && bg == 1) {
      lcd.print("Go! Go! Go!");
      digitalWrite(r, LOW);
      digitalWrite(g, HIGH);
      delay(dg);
    } else {
      digitalWrite(r, LOW);
      digitalWrite(g, LOW);
    }
  }
}

long getDelay() {
  long value = 0;
  lcd.setCursor(0, 1);
  while (true) {
    char key = cKeypad.getKey();
    if (key >= '0' && key <= '9') {
      value = value * 10 + (key - '0');
      lcd.print(key);
    } else if (key == 'C') {
      break;
    }
  }  // return to traffic mode after setting delay
  return value;
}
