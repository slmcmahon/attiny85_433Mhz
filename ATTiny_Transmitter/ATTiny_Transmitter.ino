#include <VirtualWire.h>

const int PIR_PIN = 1;
const int TX_PIN = 2;
char *controller;

void setup() {
  pinMode(PIR_PIN, INPUT);
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(TX_PIN);
  vw_setup(4000);
}

void loop() {
  int sensorValue = digitalRead(PIR_PIN);
  char *message = sensorValue == 1 ? "1" : "0";

  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx();

  delay(1);        // delay in between reads for stability
}
