import processing.serial.*;
Serial port;
float brightness = 0;

void setup() {
  size(500, 500);
  port = new Serial(this, "/dev/cu.usbmodem14101", 9600);
  port.bufferUntil('\n');
}

void draw() {
  background(0, brightness, 0);
}

void serialEvent(Serial port) {
  brightness = float(port.readStringUntil('\n'));
}
