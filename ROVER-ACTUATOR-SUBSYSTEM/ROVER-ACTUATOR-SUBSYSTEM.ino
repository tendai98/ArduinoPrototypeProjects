#include "wifi.h"
#include "server.h"

void setup() {
  initMotorControls();
  initWiFiConnection();
  initControlServer();
}

void loop() {
  checkConnection();
  runControlServer();
  blinkLED(40);
}
