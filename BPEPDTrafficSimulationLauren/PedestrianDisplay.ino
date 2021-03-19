/*
 * BP EPD Traffic simmulation
 * Written by: Lauren Meenhorst SN632206 
 * Class: 1DC
 * Date: 02-04-2020
 */

// Attributes
const int NUMBER_OF_DISPLAYVALUES = 10;
const byte DISPLAYVALUES[ NUMBER_OF_DISPLAYVALUES ] = {
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B00011100, // Walk
  B01101110, // Stop
  B00000010  // Be carefull
};
unsigned long countdownPedestrianDisplayTimer;
unsigned long displayWalkTimer;
int timePedestriansCanWalk = 5000;
int timeNeededForCountdown = 7000;

// Methods
void pedestrianDisplaySetup() {
  shiftRegisterSetup();
}
void showDisplayValue( int valueNumber ) {
  setShiftRegister( DISPLAYVALUES[ valueNumber ] );
}

void showDisplayValue_Walk() {
  showDisplayValue( 7 );
}
void showDisplayValue_Stop() {
  showDisplayValue( 8 );
}
void showDisplayValue_Carefull() {
  showDisplayValue( 9 );
}

unsigned long previousMillisCountdown = 0;
int timePerNumber = 1000;
boolean completedCountdown = false;
int displayValue = NUMBER_OF_DISPLAYVALUES - 4;

unsigned long get_display_walk_timer() {
  return displayWalkTimer;
}
void set_display_walk_timer(unsigned long time) {
  displayWalkTimer = time;
}
int get_time_pedestrians_can_Walk() {
  return timePedestriansCanWalk;
}
void setCountdownPedestrianDisplayTimer() {
  countdownPedestrianDisplayTimer = millis() + timeNeededForCountdown;
}
unsigned long getCountdownPedestrianDisplayTimer() {
  return countdownPedestrianDisplayTimer;
}
