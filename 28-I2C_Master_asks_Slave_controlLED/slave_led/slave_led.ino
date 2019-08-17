/*
    Author: Quang Tran
    Date: August 17, 2019
*/

#include <Wire.h>

#define SLAVE_ADDR 9

unsigned LED = 13;
unsigned data;      // Holds data receive from master
unsigned rate;      // Blink rate

void receiveEvent(int) {
  data = Wire.read();
  Serial.println(data);
}


void setup() {
  pinMode(LED, OUTPUT);
  Wire.begin(SLAVE_ADDR);
  Wire.onReceive(receiveEvent);

  Serial.begin(9600);
}

void loop() {
  delay(50);
  rate = map(data, 0, 255, 100, 1000);    // 100-2000 is the delay periods
  digitalWrite(LED, HIGH);
  delay(rate);
  digitalWrite(LED, LOW);
  delay(rate);
} 
