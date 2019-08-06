/*
    Author: Quang Tran
    Date: August 6, 2019
*/

import processing.serial.*;
PImage img;
Serial port;

void setup() {
  size(640, 256);                                          // Size of the screen/image
  img = loadImage("hsv.jpg");                              // An image from 'data' folder
  port = new Serial(this, "/dev/cu.usbmodem14101", 9600);  // Create a serial stream
}

void draw() {
  //background(0);            
  image(img, 0, 0);     // A floating image: a 'color selector'
}

void mousePressed() {
  color c = get(mouseX, mouseY);    // Get the color where the mouse is clicked
  String colors = int(red(c)) + ", " + int(green(c)) + ", " + int(blue(c)) + "\n";   // Convert color to R,G,B values
  print(colors);                    // Display the color selected in R, G, B
  port.write(colors);               // Send value through serial port we created above
}
