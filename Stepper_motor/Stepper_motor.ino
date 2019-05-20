#define pin1 9
#define pin2 10
#define pin3 11
#define pin4 12

int step_number = 0;
void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
}

void loop() {
  for (int a = 0; a < 1000; a++) {      // Call the motor 1000 times (steps)
    OneStep(false);                     // CCW direction
    delay(2); 
  }
  for (int a = 0; a < 1000; a++) {      // Call motor for 1000 steps
    OneStep(true);                      // CW direction
    delay(2);
  }
}


void OneStep(bool dir) {                // Code to move one step of motor (parameter: direction)
  if (dir) {
    switch (step_number) {
      case 0:
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
        break;

      case 1:
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
        break;

      case 2:
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
        break;

      case 3:
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
        break;
    }
  } else {
    switch (step_number) {
      case 0:
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
        break;

      case 1:
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
        break;

      case 2:
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
        break;

      case 3:
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
        break;
    }
  }
  
  step_number++;
  
  if (step_number > 3) {        // If step > 3, reset it to 0
    step_number = 0;
  }
}
