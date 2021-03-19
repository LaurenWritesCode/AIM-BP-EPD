/*
 * BP EPD Traffic simmulation
 * Written by: Lauren Meenhorst SN632206 
 * Class: 1DC
 * Date: 02-04-2020
 */

// Attributes 
const int OPENED = 90;
const int CLOSED = 0;

// Methods
void barrierSetup() {
  servoSetup();
}

void barrierOpen() {
  moveServo(OPENED);
}
void barrierClose() {
  moveServo(CLOSED);
}

boolean barrierOpened() {
  int barrierPos = getServoCurrentPos();
  return (barrierPos >= OPENED);
}

boolean barrierClosed() {
  int barrierPos = getServoCurrentPos();
  return (barrierPos <= CLOSED);
}
