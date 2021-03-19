/*
 * BP EPD Traffic simmulation
 * Written by: Lauren Meenhorst SN632206 
 * Class: 1DC
 * Date: 02-04-2020
 */

// Attributes
const int DEAD_TIME = 2000;
unsigned long deadTimer = 0;

// Methods
unsigned long getDeadTimer() {
  return deadTimer;
}
void setDeadTimer(unsigned long time) {
  deadTimer = time;
}
int getDeadTime(){
  return DEAD_TIME;
}
