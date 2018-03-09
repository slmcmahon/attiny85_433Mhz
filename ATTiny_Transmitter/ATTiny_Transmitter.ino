#include <VirtualWire.h>

const int PIR_PIN = 1;
const int TX_PIN = 2;
const int TX_SPEED = 4000;
const char *ON = "1";
const char *OFF = "0";

void setup() {
  pinMode(PIR_PIN, INPUT);
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(TX_PIN);
  vw_setup(TX_SPEED);
}

void loop() {
  int sensorValue = digitalRead(PIR_PIN);
  char *message = sensorValue == 1 ? ON : OFF;

  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx();

  delay(500);
}
