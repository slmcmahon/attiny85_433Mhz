#include <VirtualWire.h>

const int LED_PIN = 0;
const int RCV_PIN = 1;
const int TX_SPEED = 4000;
const char *ON = "1";

void setup() {
  pinMode(LED_PIN, OUTPUT);
  vw_set_rx_pin(RCV_PIN);
  vw_set_ptt_inverted(true);
  vw_setup(TX_SPEED);
  vw_rx_start();
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf, &buflen)) {
     int val = buf[0] == ON ? HIGH : LOW;
     digitalWrite(LED_PIN, val);
  }
}
