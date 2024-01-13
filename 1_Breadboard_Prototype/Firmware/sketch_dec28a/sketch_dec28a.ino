//50157735 vol up
//50165895 vol down
//50190375 chan next
//50198535 chan prev
//50153655 power
#include "IRremote.h"

int PWR_pin=2;
int NEXT_pin=4;
int PREV_pin=5;
int VOLU_pin=6;
int VOLD_pin=7;
int irrecv_pin=4;

decode_results results;
IRsend irsend;

void setup() {
  Serial.begin(9600);
  pinMode(PWR_pin, INPUT_PULLUP);
  pinMode(NEXT_pin, INPUT_PULLUP);
  pinMode(PREV_pin, INPUT_PULLUP);
  pinMode(VOLU_pin, INPUT_PULLUP);
  pinMode(VOLD_pin, INPUT_PULLUP);
}

void loop() {
  boolean PWR_btn = !(digitalRead(PWR_pin));
  boolean NEXT_btn = !(digitalRead(NEXT_pin));
  boolean PREV_btn = !(digitalRead(PREV_pin));
  boolean VOLU_btn = !(digitalRead(VOLU_pin));
  boolean VOLD_btn = !(digitalRead(VOLD_pin));

  if (PWR_btn == 1) {
    irsend.sendNEC(50153655,32);
    delay(30);
  };

  if (NEXT_btn == 1) {
    irsend.sendNEC(50190375,32);
    delay(30);
  };

  if (PREV_btn == 1) {
    irsend.sendNEC(50198535,32);
    delay(30);
  };

  if (VOLU_btn == 1) {
    irsend.sendNEC(50157735,32);
    delay(30);
  };

  if (VOLD_btn == 1) {
    irsend.sendNEC(50165895,32);
    delay(30);
  };
}