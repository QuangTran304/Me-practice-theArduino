/*
    Author: Quang Tran
    Date: August 9, 2019
*/

#include <Mouse.h>

unsigned leftButton = 4;    // Left mouse click
unsigned rightButton = 2;   // Right mouse click
unsigned X_Axis = 0;        // Joystick to A0
unsigned Y_Axis = 1;        // Joystick to A1

void setup() {
  Mouse.begin();
}

void loop() {
  double x = readJoystick(X_Axis);        // Get X-axis movement. 'Double' for more precision.
  double y = readJoystick(Y_Axis);        // Get Y-axis movement
 
  Mouse.move(x, y, 0);                    // Third parameter is for scroll wheel

  readButton(leftButton, MOUSE_LEFT);     // Control left button
  readButton(rightButton, MOUSE_RIGHT);   // Control right button

  delay(10);                              // Affect the responsiveness of the mouse
}



/* If we want to change the orientation of the joystick (horizontal/ vertical move)
   Write 2 separate readJoystick() functions for each dimensions. Reverse the mapping
   values on the axis that we want to reverse. */
   
double readJoystick(double axis) {
  double val = analogRead(axis);
  val = map(val, 0, 1023, 15, -15);       // The larger the value, the faster the mouse will accelerate. Consider fine-tuning this values and delay() value
  if (val <= 1  &&  val >= -1) {          // Dead-zone/tolerance for potential meters. Smaller zone is better.
    return 0;                             // set val = 0  =>  tell it NOT to move.
  } else {
    return val;
  }
}

void readButton(int pin, char mouseCommand) {
  if (digitalRead(pin) == HIGH) {
      Mouse.press(mouseCommand);
  } else {
      Mouse.release(mouseCommand);
  }
}
