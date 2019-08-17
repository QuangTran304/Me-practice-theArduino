/*
    Author: Quang Tran
    Date: August 16, 2019
*/

#include <Wire.h>

#define SLAVE_ADDR 9
#define ANSWER_SIZE 5

String answer = "Hello";        // 5 characters in size

void receiveEvent(int) {        // This func wants an int parameter but we don't need to use it here
   while (Wire.available() > 0) {
    byte x = Wire.read();
    Serial.print("Event is received: ");
    Serial.println(x);
   }
}

void requestEvent() {
   byte response[ANSWER_SIZE];

   for (byte i = 0; i < ANSWER_SIZE; ++i) {
     response[i] = (byte)answer.charAt(i);
   }
   
   Serial.println("Event is requested, Slave is answering...");
   Wire.write(response, sizeof(response));
   
}


void setup() {
  Wire.begin(SLAVE_ADDR);         // Give parameter to Wire.begin(...) == Slave mode.
  Wire.onRequest(requestEvent);   // Called when data is requested
  Wire.onReceive(receiveEvent);   // Called when data is received

  Serial.begin(9600);
} 

void loop() {
  delay(2000);
}
