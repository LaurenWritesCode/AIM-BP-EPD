/*
 * BP EPD Traffic simmulation
 * Written by: Lauren Meenhorst SN632206 
 * Class: 1DC
 * Date: 02-04-2020
 */

// Attributes
const int MAX_NIGHT_LIGHT_VALUE = 50;
const int MIN_DAY_LIGHT_VALUE = 60;
const int timer_to_prevent_in_and_out_switch = 4000;
const int prev_millis_night_switch = 0;

// Methods
void nightShiftSetup() {
  LDRSetup();
}

boolean isNight() {
  int LDRValue = getLDRValue();
  Serial.println(LDRValue);
  if (LDRValue <= MAX_NIGHT_LIGHT_VALUE) {
    if (millis() - prev_millis_night_switch >= timer_to_prevent_in_and_out_switch) {
      return true;
    }
  } else if (LDRValue >= MIN_DAY_LIGHT_VALUE) {
    if (millis() - prev_millis_night_switch >= timer_to_prevent_in_and_out_switch) {
      return false;
    }
  }
  else {
    return false;
  }
}
