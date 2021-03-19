/*
 * BP EPD Traffic simmulation
 * Written by: Lauren Meenhorst SN632206 
 * Class: 1DC
 * Date: 02-04-2020
 */

// Methods 

// STATE_NO_ACTIVITY
void state_no_activity_Entry() {
  setBuzzerFrequency(getBuzzerLowFrequency());
  showDisplayValue_Stop();
  for (int light = 0; light < getNumberOfTrafficLights(); light++) {
    turnTrafficLightOff(light);
    setTrafficLightPattern(light, getTrafficLightRed());
  }
}
void state_no_activity_Do() {
  setDirectionRequestingPassing();
}
void state_no_activity_Exit() {
  /* <nothing> */
}
// STATE_TO_NIGHT_SHIFT
void state_to_night_shift_Entry() {
  setBuzzerFrequency(getBuzzerLowFrequency());
  showDisplayValue_Stop();
}
void state_to_night_shift_Do() {
  barrierOpen();
}
void state_to_night_shift_Exit() {
  /* <nothing> */
}

// STATE_NIGHT_SHIFT
void state_night_shift_Entry() {
  showDisplayValue_Carefull();
  setBuzzerFrequency(getBuzzerOffFrequency());
  for (int light = 0; light < getNumberOfTrafficLights(); light++) {
    turnTrafficLightOff(light);
    setTrafficLightPattern(light, getTrafficLightToRed());
  }
}
void state_night_shift_Do() {
  trafficLightsBlink(1, 1); // blink yellow lights
}
void state_night_shift_Exit() {
  for (int light = 0; light < getNumberOfTrafficLights(); light++) {
    turnTrafficLightOff(light); // turn all lights off
  }
}

// STATE_TO_DAY_SHIFT
void state_to_day_shift_Entry() {
  showDisplayValue_Stop();
  setBuzzerFrequency(getBuzzerLowFrequency());
  for (int light = 0; light < getNumberOfTrafficLights(); light++) {
    setTrafficLightPattern(light, getTrafficLightToRed()); // turn both yellow lights on
  }
}
void state_to_day_shift_Do() {
  barrierClose();
}
void state_to_day_shift_Exit() {
  for (int light = 0; light < getNumberOfTrafficLights(); light++) {
    turnTrafficLightOff(light);
    setTrafficLightPattern(light, getTrafficLightRed());
  }
}

// STATE_DEAD_TIME
void state_dead_time_Entry() {
  setDeadTimer(millis());
  removeRequestorFromQueue();
}
void state_dead_time_Do() {
  /* <nothing> */
}
void state_dead_time_Exit() {
  /* <nothing> */
}

// STATE_TRAFFIC_LIGHT_TO_GREEN
void state_traffic_light_to_green_Entry() {
  Serial.print(" Traffic light to green ");
  Serial.println (getDirectionRequestingPassing());
  setTrafficLightPattern(getDirectionRequestingPassing(), getTrafficLightToGreen());
  set_traffic_light_to_green_timer(millis());
}
void state_traffic_light_to_green_Do() {}
void state_traffic_light_to_green_Exit() {
  turnTrafficLightOff(getDirectionRequestingPassing());
}

// STATE_TRAFFIC_LIGHT_IS_GREEN
void state_traffic_light_is_green_Entry() {
  setTrafficLightPattern(getDirectionRequestingPassing(), getTrafficLightGreen());
  set_traffic_light_is_green_timer(millis());
}
void state_traffic_light_is_green_Do() {
  /* <nothing> */
}
void state_traffic_light_is_green_Exit() {
  turnTrafficLightOff(getDirectionRequestingPassing());
}

// STATE_TRAFFIC_LIGHT_TO_RED
void state_traffic_light_to_red_Entry() {
  Serial.print(" Traffic light to red ");
  Serial.println (getDirectionRequestingPassing());
  set_traffic_light_to_red_timer(millis());
  setTrafficLightPattern(getDirectionRequestingPassing(), getTrafficLightToRed());
}
void state_traffic_light_to_red_Do() {
  /* <nothing> */
}
void state_traffic_light_to_red_Exit() {
  Serial.print(" Traffic light to red EXIT ");
  Serial.println (getDirectionRequestingPassing());
  setTrafficLightPattern(getDirectionRequestingPassing(), getTrafficLightRed());
}

// STATE_OPENING_BARRIER

void state_opening_barrier_Entry() {
  /* <nothing> */
}
void state_opening_barrier_Do() {
  barrierOpen();
}
void state_opening_barrier_Exit() {
  /* <nothing> */
}

// STATE_BARRIER_OPENED
void state_barrier_openend_Entry() {
  showDisplayValue_Walk();
  set_display_walk_timer(millis());
  setBuzzerFrequency(getBuzzerHighFrequency());
}
void state_barrier_openend_Do() {
  /* <nothing> */
}
void state_barrier_openend_Exit() {
  /* <nothing> */
}

// STATE_COUNTDOWN_PEDESTRIAN_DISPLAY
void state_countdown_pedestrian_display_Entry() {
  setCountdownPedestrianDisplayTimer();
  buzzerTriplePulseSetup();
}
void state_countdown_pedestrian_display_Do() {
  showDisplayValue((getCountdownPedestrianDisplayTimer() - millis()) / 1000);
  buzzerTriplePulse();
}
void state_countdown_pedestrian_display_Exit() {
  /* <nothing> */
}

// STATE_CLOSE_BARRIER
void state_close_barrier_Entry() {
  showDisplayValue_Stop();
  setBuzzerFrequency(getBuzzerLowFrequency());
}
void state_close_barrier_Do() {
  barrierClose();
}
void state_close_barrier_Exit() {
  //removeRequestorFromQueue();
}

//// STATE_TEST
//void state_test_Entry() {
//  testSetup();
//}
//void state_test_Do() {
//  performTest();
//}
//void state_test_Exit() {
//  // nothing
//}
