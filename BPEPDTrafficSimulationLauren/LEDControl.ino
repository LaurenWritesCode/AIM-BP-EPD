/*
 * BP EPD Traffic simmulation
 * Written by: Lauren Meenhorst SN632206 
 * Class: 1DC
 * Date: 02-04-2020
 */

// Methods
void ledControlSetup(int leds[], int number_of_leds) {
  for (int led = 0; led < number_of_leds; led++) {
    pinMode(leds[led], OUTPUT);
  }
}

void ledControlSetLedOn (int led) {
  Serial.print(" set led on ");
  Serial.println (led);
  digitalWrite(led, HIGH);
}

void ledControlSetLedOff (int led) {
  digitalWrite(led, LOW);
}

int blinkSpeed = 500; 
unsigned long blinkPreviousMillis;
void ledControlLedsBlink (int led1, int led2) {
  if (millis() - blinkPreviousMillis >= blinkSpeed) {        
    blinkPreviousMillis = millis();                              
    digitalWrite(led1, !digitalRead(led1));
    digitalWrite(led2, !digitalRead(led2));                   
  }
}
