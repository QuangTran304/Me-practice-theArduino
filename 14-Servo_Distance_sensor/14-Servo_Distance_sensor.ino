/*
    Author: Quang Tran
    Date: July 25, 2019
*/

#include <SharpIR.h>
#include <Servo.h>

#define IR A0          // IR sensor pin 0/ A0
#define model 1080

//Sharp-IR-sensor codes:

//2 to 15 cm GP2Y0A51SK0F                     use 1080
//4 to 30 cm GP2Y0A41SK0F / GP2Y0AF30 series  use 430
//10 to 80 cm GP2Y0A21YK0F                    use 1080
//10 to 150 cm GP2Y0A60SZLF                   use 10150
//20 to 150 cm GP2Y0A02YK0F                   use 20150
//100 to 550 cm GP2Y0A710K0F                  use 100550

SharpIR SharpIR(IR, model);
Servo servo1;

const int SERVO = 9;
int value = 0;

void setup() {
  Serial.begin(9600);
  servo1.attach(SERVO);
}

void loop() {
  int dist = SharpIR.distance();
  Serial.print("Current distance: ");
  Serial.print(dist);
  Serial.println(" cm");

  value = analogRead(IR);
  value = map(value, 0, 1023, 0, 255);
  servo1.write(value);
  delay(100);
}
