/*
 * BP EPD Traffic simmulation
 * Written by: Lauren Meenhorst SN632206 
 * Class: 1DC
 * Date: 02-04-2020
 */

// Attributes 
const int NUMBER_OF_BUTTONS = 3;
const int BUTTONS[ NUMBER_OF_BUTTONS ] = {A5, A3, A4};
const int BUTTON_CAR_LEFT = 0, BUTTON_CAR_RIGHT = 1, BUTTON_PEDESTRIAN = 2;

// Button timing
unsigned long buttonPreviousMillis[ NUMBER_OF_BUTTONS ] = {0, 0, 0};
const int DEBOUNCE_TIME = 20;

// Methods
void buttonSetup() {
  for (int button = 0; button < NUMBER_OF_BUTTONS; button++) {
    pinMode(BUTTONS[button], INPUT);
  }
}

boolean buttonPressed(int button) {
  //Serial.println(digitalRead(BUTTONS[button]) == HIGH);
  return digitalRead(BUTTONS[button]) == HIGH;
}

void checkButtons() {
  for (int button = 0; button < NUMBER_OF_BUTTONS; button++) {
    unsigned long currentMillis = millis();
    if (buttonPressed(button) && currentMillis - buttonPreviousMillis[button] >= DEBOUNCE_TIME) {
      buttonPreviousMillis[button] = currentMillis;
      placeRequestorInQueue(button);
    }
  }
}

// Getters / setters
int getButtonCarLeft() {
  return BUTTON_CAR_LEFT;
}
int getButtonCarRight() {
  return BUTTON_CAR_RIGHT;
}
int getButtonPedestrian() {
  return BUTTON_PEDESTRIAN;
}
