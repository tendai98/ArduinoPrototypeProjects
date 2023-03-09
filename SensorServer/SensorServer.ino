#include "wifi.h"
#include "server.h"

const char * ssid = "Dev-0";
const char * pass = "qwertyuiop";


void setup() {
    Serial.println(9600);
    startWiFiHotSpot(ssid, pass);
    initHttp();
}

void loop() {
  handleClientRequest();
}
