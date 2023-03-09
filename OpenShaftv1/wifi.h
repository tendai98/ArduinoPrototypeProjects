#include <ESP8266WiFi.h>

void startWiFi(const char * ap_ssid, const char * ap_pass, const char * host_name){
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ap_ssid, ap_pass);
    WiFi.hostname(host_name);
}
