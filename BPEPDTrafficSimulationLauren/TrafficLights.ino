/*
 * BP EPD Traffic simmulation
 * Written by: Lauren Meenhorst SN632206 
 * Class: 1DC
 * Date: 02-04-2020
 */

// Attributes
const int NUMBER_OF_TRAFFIC_LIGHTS = 2, NUMBER_OF_COLORS_PER_TRAFFIC_LIGHT = 3, NUMBER_OF_TRAFFIC_LIGHT_PATTERNS = 4;
const int LEFT_TRAFFIC_LIGHT = 0, RIGHT_TRAFFIC_LIGHT = 1;
const int TRAFFICLIGHTS [NUMBER_OF_TRAFFIC_LIGHTS][NUMBER_OF_COLORS_PER_TRAFFIC_LIGHT] = {{4, 3, 2}, {7 , 6, 5}};

unsigned long trafficLightToGreenTimer = 0;
const int timeTrafficLightToGreen = 500;

unsigned long trafficLightIsGreenTimer = 0;
const int timeTrafficLightIsGreen = 3000;

unsigned long trafficLightToRedTimer = 0;
const int timeTrafficLightIsYellow = 1000;

unsigned long trafficLightPreviousMillis;


const int TRAFFIC_LIGHT_RED = 0, TRAFFIC_LIGHT_TO_GREEN = 1, TRAFFIC_LIGHT_GREEN = 2, TRAFFIC_LIGHT_YELLOW = 3;
const int TRAFFIC_LIGHT_PATTERNS [NUMBER_OF_TRAFFIC_LIGHT_PATTERNS][NUMBER_OF_COLORS_PER_TRAFFIC_LIGHT] {
  {1, 0, 0}, // red
  {0, 0, 0}, // to green
  {0, 0, 1}, // green
  {0, 1, 0} // yellow (to red)
};

// Methods
void trafficLightSetup() {
  for ( int light = 0; light <= NUMBER_OF_TRAFFIC_LIGHTS; light ++) {
    ledControlSetup(TRAFFICLIGHTS[light], NUMBER_OF_COLORS_PER_TRAFFIC_LIGHT);
    //setTrafficLightPattern(light, TRAFFIC_LIGHT_RED);
  }
}

void turnTrafficLightOff(int trafficLight) {
  for (int light = 0; light < NUMBER_OF_COLORS_PER_TRAFFIC_LIGHT; light++) {
    ledControlSetLedOff(TRAFFICLIGHTS [trafficLight][light]);
  }
}

void setTrafficLightPattern(int trafficLight, int pattern) {
  for (int i = 0; i < NUMBER_OF_COLORS_PER_TRAFFIC_LIGHT; i++) {
    if (TRAFFIC_LIGHT_PATTERNS[pattern][i] > 0) {
      ledControlSetLedOn(TRAFFICLIGHTS[trafficLight][i]);
    } else {
      ledControlSetLedOff(TRAFFICLIGHTS[trafficLight][i]);
    }
  }
}

void trafficLightsBlink(int light1, int light2) {
  ledControlLedsBlink(TRAFFICLIGHTS[LEFT_TRAFFIC_LIGHT][light1], TRAFFICLIGHTS[RIGHT_TRAFFIC_LIGHT][light2]);
}

//Getters
int getTrafficLightRed() {
  return TRAFFIC_LIGHT_RED;
}
int getTrafficLightToGreen() {
  return TRAFFIC_LIGHT_TO_GREEN;
}
int getTrafficLightGreen() {
  return TRAFFIC_LIGHT_GREEN;
}
int getTrafficLightToRed() {
  return TRAFFIC_LIGHT_YELLOW;
}
int getNumberOfTrafficLights() {
  return NUMBER_OF_TRAFFIC_LIGHTS;
}

unsigned long get_traffic_light_to_green_timer() {
  return trafficLightToGreenTimer;
}
int get_time_to_green() {
  return timeTrafficLightToGreen;
}

void set_traffic_light_to_green_timer(unsigned long time) {
  trafficLightToGreenTimer = time;
}
unsigned long get_traffic_light_is_green_timer() {
  return trafficLightIsGreenTimer;
}
void set_traffic_light_is_green_timer(unsigned long time) {
  Serial.print(" set is green timer ");
  Serial.println (time);
  trafficLightIsGreenTimer = time;
}
int get_time_traffic_light_is_green() {
  return timeTrafficLightIsGreen;
}
unsigned long get_traffic_light_to_red_timer() {
  return trafficLightToRedTimer;
}
void set_traffic_light_to_red_timer(unsigned long time) {
  Serial.print(" set to red timer ");
  Serial.println (time);
  trafficLightToRedTimer = time;
}
int get_time_traffic_light_is_yellow() {
  return timeTrafficLightIsYellow;
}
