/*
 * BP EPD Traffic simmulation
 * Written by: Lauren Meenhorst SN632206 
 * Class: 1DC
 * Date: 02-04-2020
 */

void setup() {
  serialSetup();
  buttonSetup();
  buzzerSetup();
  nightShiftSetup();
  simulationStateMachineSetup();
}

void loop() {
  if (!isNight()) {
    buzzerBuzz();
    checkButtons();
  }
  simulationStateMachineLoop();
}
