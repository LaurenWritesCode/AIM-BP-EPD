/*
 * BP EPD Traffic simmulation
 * Written by: Lauren Meenhorst SN632206 
 * Class: 1DC
 * Date: 02-04-2020
 */

// Attributes
const int QUEUE_POSITIONS = 3;
const int QUEUE_VALUE_WHEN_EMPTY = 3;

int queue[ QUEUE_POSITIONS ] = {3, 3, 3};

// Methods
boolean requestorInQueue(int requestor) {
  for (int i = 0; i < QUEUE_POSITIONS; i++) {
    if (queue[i] == requestor) {
      return true;
    }
  }
  return false;
}

void placeRequestorInQueue(int requestor) {
  if (!requestorInQueue(requestor)) {
    for (int i = 0; i < QUEUE_POSITIONS; i++) {
      if (queue[i] == QUEUE_VALUE_WHEN_EMPTY) {
        queue[i] = requestor;
        Serial.println("requestor placed in queue");
        Serial.println(queue[0]);
        Serial.println(queue[1]);
        Serial.println(queue[2]);
        Serial.println("done");
        break;
      }
    }
  }
  Serial.println("requestor was already in queue");
}

int prevVal = queue[QUEUE_POSITIONS - 1], i;
void removeRequestorFromQueue() {
  for (int i = QUEUE_POSITIONS - 1; i >= 0; i--) {
    int currVal = queue[i];
    queue[i] = prevVal;
    prevVal = currVal;
  }
  queue[QUEUE_POSITIONS - 1] = QUEUE_VALUE_WHEN_EMPTY;
  Serial.println(queue[0]);
  Serial.println(queue[1]);
  Serial.println(queue[2]);
}

int getFirstInLine() {
  return queue[0];
}
int getQueValueWhenEmpty() {
  return QUEUE_VALUE_WHEN_EMPTY;
}
