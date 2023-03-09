#include "wifi.h"
#include "http.h"

void setup() {
  startWiFiNet();
  startServer();
}

void loop() {
  handleRequests();
}
