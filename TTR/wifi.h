#include <ESP8266WiFi.h>

void initWiFi(){
  WiFi.softAP(AP_NAME,AP_PASS);
}
