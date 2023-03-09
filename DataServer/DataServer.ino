#include "wifi.h"
#include "http.h"


void setup() {
    initWiFi();
    initHttp();
}

void loop() {
  handleClients();
}
