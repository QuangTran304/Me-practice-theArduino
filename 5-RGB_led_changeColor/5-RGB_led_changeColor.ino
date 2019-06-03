const int RED = 9;
const int GREEN = 10;
const int BLUE = 11;
const int BUTTON = 6;

int ledMode = 0;
bool currentButton = LOW;
bool lastButton = LOW;


void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  currentButton = findCurrentState(lastButton);

  if (currentButton == HIGH && lastButton == LOW) {
    ledMode++;
  }
  lastButton = currentButton;
  if (ledMode == 12)   ledMode = 0;
  setUp(ledMode);
}

void setUp(int mode) {
    switch(mode) {
      case 1:
        digitalWrite(RED, HIGH);
        digitalWrite(GREEN, LOW);
        digitalWrite(BLUE, LOW);
        break;
      case 2:
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, HIGH);
        digitalWrite(BLUE, LOW);
        break;
      case 3:
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, LOW);
        digitalWrite(BLUE, HIGH);
        break; 
      case 4: 
        digitalWrite(RED, 102);
        digitalWrite(GREEN, 255);
        digitalWrite(BLUE, 153);
        break;
      case 5:
        digitalWrite(RED, 0);
        digitalWrite(GREEN, 102);
        digitalWrite(BLUE, 255);
        break;  
      case 6:  
        digitalWrite(RED, 255);
        digitalWrite(GREEN, 255);
        digitalWrite(BLUE, 0);
        break;
      case 7:  
        digitalWrite(RED, 153);
        digitalWrite(GREEN, 0);
        digitalWrite(BLUE, 255);
        break;
      case 8:  
        digitalWrite(RED, 204);
        digitalWrite(GREEN, 255);
        digitalWrite(BLUE, 255);
        break;
      case 9:  
        digitalWrite(RED, 204);
        digitalWrite(GREEN, 153);
        digitalWrite(BLUE, 0);
        break;
      case 10:  
        digitalWrite(RED, 204);
        digitalWrite(GREEN, 0);
        digitalWrite(BLUE, 102);
        break;
      case 11:  
        digitalWrite(RED, 51);
        digitalWrite(GREEN, 204);
        digitalWrite(BLUE, 255);
        break;
      default:
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, LOW);
        digitalWrite(BLUE, LOW);
    }
}

bool findCurrentState(bool last) {
  bool current = digitalRead(BUTTON);
  
  if (last != current) {
    delay(5);
    current = digitalRead(BUTTON);
  }
  return current;
}
