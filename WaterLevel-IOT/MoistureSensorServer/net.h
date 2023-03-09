#include <ESP8266WiFi.h>

void setupWiFiHostpot(const char * ap_name, const char * pass_key){
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ap_name, pass_key);
}
