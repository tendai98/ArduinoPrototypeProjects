#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "tx500.h"

void setup(){
  Serial.begin(portSpeed);
  WiFi.softAP(AP_NAME,AP_PASS);
  server.begin(localPort);
}

void loop(){
 recvData(); 
}
