#include "net.h"
#include "server.h"

#define AP_NAME "Moisture-Sensor"
#define AP_PASS "12345678"

void setup() {
  setupWiFiHostpot(AP_NAME, AP_PASS);
  setupHTTPServer();
}

void loop() {
 handleRequest();
 delay(100);
}
