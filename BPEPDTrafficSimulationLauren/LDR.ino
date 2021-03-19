/*
 * BP EPD Traffic simmulation
 * Written by: Lauren Meenhorst SN632206 
 * Class: 1DC
 * Date: 02-04-2020
 */

// Attributes
const int LDR_PIN = A1;
const int MIN_VALUE = 0;
const int MAX_VALUE_ANALOG = 1023;
const int MAX_VALUE_RANGE = 100;

// Methods
void LDRSetup() {
  pinMode(LDR_PIN, INPUT);
}

int getLDRValue() {
  int LDRValue = map(analogRead(LDR_PIN), MIN_VALUE, MAX_VALUE_ANALOG, MIN_VALUE, MAX_VALUE_RANGE);
  //Serial.println(LDRValue);
  return LDRValue;
}
