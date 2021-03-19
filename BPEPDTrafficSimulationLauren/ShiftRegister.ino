/*
 * BP EPD Traffic simmulation
 * Written by: Lauren Meenhorst SN632206 
 * Class: 1DC
 * Date: 02-04-2020
 */

// Attributes
const int DS_PIN = 8;
const int SH_CP = 9;
const int ST_CP = 10;

const int NUMBEROFSHIFTPINS = 7;

// Methods
void shiftRegisterSetup() {
  pinMode(DS_PIN, OUTPUT);
  pinMode(ST_CP, OUTPUT);
  pinMode(SH_CP, OUTPUT);
}

void setShiftRegister (byte pattern) {
  digitalWrite(ST_CP, LOW);
  for (int i = 0; i < 8; i ++) {
    digitalWrite(SH_CP, LOW);
    if (bit_is_set(pattern, i)) {
      digitalWrite(DS_PIN, HIGH);
    } else {
      digitalWrite(DS_PIN, LOW);
    }
    digitalWrite(SH_CP, HIGH);
  }
  digitalWrite(ST_CP, HIGH);
  digitalWrite(ST_CP, LOW);
}

boolean isSet(byte pattern, int led) {
  for (int i = 0; i < pattern; i ++) {
    if (i == 1) {
      return true;
    } else {
      return false;
    }
  }
}
