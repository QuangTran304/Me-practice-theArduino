/*
    Author: Quang Tran
    Date: July 25, 2019

    Note: This program scan and report the distance of the surrounding
          objects using LEDs: closer - brighter/ farther - dimmer.
          
    Note2: Can't use pin 9 & 10 for PWM when using Servo Library
*/

#include <Servo.h>

const int SERVO = 9;
const int IR = 0;
const int LED1 = 3;
const int LED2 = 5;
const int LED3 = 6;
const int LED4 = 11;

Servo servo1;
int dist1 = 0;    // Distance for the first quadrant
int dist2 = 0;    // Distance for the second
int dist3 = 0;    // Third quadrant
int dist4 = 0;    // Fourth

void setup() {
  servo1.attach(SERVO);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {
  // Sweep the servo into 4 regions and change the LEDs accordingly
  dist1 = readDistance(0);     // 0 Degree
  analogWrite(LED1, dist1);
  delay(1000);

  dist2 = readDistance(60);     // 60 Degree
  analogWrite(LED2, dist2);
  delay(1000);

  dist3 = readDistance(120);    // 120 Degree
  analogWrite(LED3, dist3);
  delay(1000);

  dist4 = readDistance(180);    // 180 Degree
  analogWrite(LED4, dist4);
  delay(1000);
}

int readDistance(int pos) {
  servo1.write(pos);
  delay(600);                           // Wait for the servo to move
  int dist = analogRead(IR);
  dist = map(dist, 50, 500, 0, 255);    // 50 & 500 are just two distance values picked to measure. To find out, use Serial.print(distance).
  dist = constrain(dist, 0, 255);
  return dist;
}
