/*
 * BP EPD Traffic simmulation
 * Written by: Lauren Meenhorst SN632206 
 * Class: 1DC
 * Date: 02-04-2020
 */

// Attributes
const int STATE_NO_ACTIVITY                   = 0;
const int STATE_TO_NIGHT_SHIFT                = 1;
const int STATE_NIGHT_SHIFT                   = 2;
const int STATE_TO_DAY_SHIFT                  = 3;
const int STATE_DEAD_TIME                     = 4;

const int STATE_TRAFFIC_LIGHT_TO_GREEN        = 5;
const int STATE_TRAFFIC_LIGHT_IS_GREEN        = 6;
const int STATE_TRAFFIC_LIGHT_TO_RED          = 7;

const int STATE_OPENING_BARRIER               = 8;
const int STATE_BARRIER_OPENED                = 9;
const int STATE_COUNTDOWN_PEDESTRIAN_DISPLAY  = 10;
const int STATE_CLOSE_BARRIER                 = 11;

//const int STATE_TEST                          = 12;

int currentState;
int direction_requesting_passing;

// Methods
int getDirectionRequestingPassing() {
  return direction_requesting_passing;
}
void setDirectionRequestingPassing() {
  direction_requesting_passing = getFirstInLine();
}
void simulationStateMachineSetup() {
  pedestrianDisplaySetup();
  trafficLightSetup();
  barrierSetup();
  currentState = STATE_NO_ACTIVITY;
  state_no_activity_Entry();
}

void simulationStateMachineLoop() {
  unsigned long currentMillis = millis();
  switch (currentState) {
    case STATE_NO_ACTIVITY:
      state_no_activity_Do();
      if (direction_requesting_passing == getButtonCarLeft() || direction_requesting_passing == getButtonCarRight()) {
        state_no_activity_Exit();
        state_traffic_light_to_green_Entry();
        currentState = STATE_TRAFFIC_LIGHT_TO_GREEN;
      }
      else if (direction_requesting_passing == getButtonPedestrian()) {
        state_no_activity_Exit();
        state_opening_barrier_Entry();
        currentState = STATE_OPENING_BARRIER;
      }
      else if (isNight()) {
        state_no_activity_Exit();
        currentState = STATE_TO_NIGHT_SHIFT;
        state_to_night_shift_Entry();
      }
      //      else if (getLastSerialMessage() == "t") {
      //        state_no_activity_Exit();
      //        currentState = STATE_TEST;
      //        state_test_Entry();
      //      }
      break;
    case STATE_TO_NIGHT_SHIFT:
      if (barrierOpened()) {
        state_to_night_shift_Exit();
        state_night_shift_Entry();
        currentState = STATE_NIGHT_SHIFT;
      } else {
        state_to_night_shift_Do();
      }
      break;
    case STATE_NIGHT_SHIFT:
      if ( !isNight() ) {
        state_night_shift_Exit();
        state_to_day_shift_Entry();
        currentState = STATE_TO_DAY_SHIFT;
      } else {
        state_night_shift_Do();
      }
      break;
    case STATE_TO_DAY_SHIFT:
      if ( barrierClosed() ) {
        state_no_activity_Entry();
        state_to_day_shift_Exit();
        currentState = STATE_NO_ACTIVITY;
      } else {
        state_to_day_shift_Do();
      }
      break;
    case STATE_DEAD_TIME:
      if (currentMillis - getDeadTimer() >= getDeadTime()) {
        state_dead_time_Exit();
        state_no_activity_Entry();
        currentState = STATE_NO_ACTIVITY;
      } else {
        state_dead_time_Do();
      }
      break;
    case STATE_TRAFFIC_LIGHT_TO_GREEN:
      if (currentMillis - get_traffic_light_to_green_timer() >= get_time_to_green()) {
        state_traffic_light_to_green_Exit();
        state_traffic_light_is_green_Entry();
        currentState = STATE_TRAFFIC_LIGHT_IS_GREEN;
      } else {
        state_traffic_light_to_green_Do();
      }
      break;
    case STATE_TRAFFIC_LIGHT_IS_GREEN:
      if (currentMillis - get_traffic_light_is_green_timer() >= get_time_traffic_light_is_green()) {
        state_traffic_light_is_green_Exit();
        state_traffic_light_to_red_Entry();
        currentState = STATE_TRAFFIC_LIGHT_TO_RED;
      } else {
        state_traffic_light_is_green_Do();
      }
      break;
    case STATE_TRAFFIC_LIGHT_TO_RED:
      if (currentMillis - get_traffic_light_to_red_timer() >= get_time_traffic_light_is_yellow()) {
        state_traffic_light_to_red_Exit();
        state_dead_time_Entry();
        currentState = STATE_DEAD_TIME;
      }
      else {
        state_traffic_light_to_red_Do;
      }
      break;
    case STATE_OPENING_BARRIER:
      if (barrierOpened()) {
        state_opening_barrier_Exit();
        state_barrier_openend_Entry();
        currentState = STATE_BARRIER_OPENED;
      } else {
        state_opening_barrier_Do();
      }
      break;
    case STATE_BARRIER_OPENED:
      if (currentMillis - get_display_walk_timer() >= get_time_pedestrians_can_Walk()) {
        Serial.print("display walk timer");
        Serial.println(get_display_walk_timer());
        state_barrier_openend_Exit();
        state_countdown_pedestrian_display_Entry();
        currentState = STATE_COUNTDOWN_PEDESTRIAN_DISPLAY;
      } else {
        state_barrier_openend_Do();
      }
      break;
    case STATE_COUNTDOWN_PEDESTRIAN_DISPLAY:
      if (currentMillis >= getCountdownPedestrianDisplayTimer()) {
        state_countdown_pedestrian_display_Exit();
        state_close_barrier_Entry();
        currentState = STATE_CLOSE_BARRIER;
      } else {
        state_countdown_pedestrian_display_Do();
      }
      break;
    case STATE_CLOSE_BARRIER:
      if (barrierClosed()) {
        state_close_barrier_Exit();
        state_dead_time_Entry();
        currentState = STATE_DEAD_TIME;
      } else {
        state_close_barrier_Do();
      }
      break;
      //    case STATE_TEST:
      //      if (testCompleted()) {
      //        state_test_Exit();
      //        state_no_activity_Entry();
      //        currentState = STATE_NO_ACTIVITY;
      //      }
      //      else
      //        sate_test_Do();
      //      break;
  }
}
