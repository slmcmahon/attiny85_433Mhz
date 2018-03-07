#include <VirtualWire.h>


const int LED = 0;
const int RCV = 1;

void setup() {
  pinMode(LED, OUTPUT);
  vw_set_rx_pin(RCV);
  vw_set_ptt_inverted(true);
  vw_setup(4000);
  vw_rx_start();
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(buf, &buflen)) {
    if (buf[0]=='1') {
      digitalWrite(LED, HIGH);
    }
    if (buf[0]=='0') {
      digitalWrite(LED, LOW);
    }
  }
}
