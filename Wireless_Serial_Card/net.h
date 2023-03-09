#include <ESP8266WiFi.h>
#define AP_SSID "AccessPoint"
#define AP_PASS "12345678"

void initNet(){
  pinMode(D4, OUTPUT);
  WiFi.softAP(AP_SSID, AP_PASS);
}
