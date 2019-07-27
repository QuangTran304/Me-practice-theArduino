/*
    Author: Quang Tran
    Date: July 26, 2019
*/

#include "pitches.h"

const int SPEAKER = 9; 

const int C_BUTTON = 7;
const int D_BUTTON = 6;
const int E_BUTTON = 5;
const int G_BUTTON = 4;
const int A_BUTTON = 3;

void setup() {
  // Don't need to setup anything
  // tone() will make the output.
}

void loop() {
 while (digitalRead(C_BUTTON)) {
   tone(SPEAKER, NOTE_C4);
 }
 while (digitalRead(D_BUTTON)) {
   tone(SPEAKER, NOTE_D4);
 }
 while (digitalRead(E_BUTTON)) {
   tone(SPEAKER, NOTE_E4);
 }
 while (digitalRead(G_BUTTON)) {
   tone(SPEAKER, NOTE_G4);
 }
 while (digitalRead(A_BUTTON)) {
   tone(SPEAKER, NOTE_A4);
 }

 noTone(SPEAKER);
}
