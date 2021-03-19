/*
 * BP EPD Traffic simmulation
 * Written by: Lauren Meenhorst SN632206 
 * Class: 1DC
 * Date: 02-04-2020
 */
 
// Attributes
const int BAUD = 9600;

// Methods
void serialSetup() {
  Serial.begin(BAUD);
}
