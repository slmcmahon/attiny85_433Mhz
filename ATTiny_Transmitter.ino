#include <VirtualWire.h>

char *controller;

void setup() {
  pinMode(1, INPUT);
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(2);
  vw_setup(4000);
}


void loop() {
  
  int sensorValue = digitalRead(1);

  if(sensorValue == 1)
  {
    sendMessage("1");
  }

  else
  {
    sendMessage("0");
  }
  
  delay(1);        // delay in between reads for stability
}

void sendMessage(char *message) {
  vw_send((uint8_t *)message, strlen(message));
  vw_wait_tx();
}

