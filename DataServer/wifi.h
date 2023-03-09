#define ESP_SSID              "S-0"
#define ESP_PASS              "123456789"

#include <ESP8266WiFi.h>

// Run to setup WIFI 

void initWiFi(){
  WiFi.softAP(ESP_SSID, ESP_PASS); 
  pinMode(D4, OUTPUT);
  digitalWrite(D4, LOW);
}
