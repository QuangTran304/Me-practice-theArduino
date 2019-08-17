/*
    Author: Quang Tran
    Date: August 16, 2019
*/

#include <Wire.h>

#define SLAVE_ADDR 9
#define ANSWER_SIZE 5

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  delay(2000);

/* 
Trigger onReceive() from Slave device. Once Slave 
device receives data from Master, it's gonna 
response (depend on how we code it to response).
*/
//  Serial.println("Writing data to Slave...");
//  Wire.beginTransmission(SLAVE_ADDR);
//  Wire.write(123);       // Any number/char Master wants.
//  Wire.endTransmission();


/*
This part triggers onRequest() from Slave device. 
Once Slave receive the request, it's gonna response
(depend on how we code it to response). We should 
comment this part and the part above, then test separately.
*/
  Serial.println("Requesting data from Slave...");
  Wire.requestFrom(SLAVE_ADDR, ANSWER_SIZE);

  Serial.print("Slave's answer: ");
  String response = "";
  while(Wire.available() > 0) {
    char b = Wire.read();
    response += b;
  }
  Serial.println(response);
}
