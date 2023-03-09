#include <ESP8266WiFi.h>

#define AP_SSID "FireMonitoringNetwork"
#define AP_PASS "12345678"
#define SENSOR_ID "FSM-0000001"
#define BLINK_LED D4

void blinkLED(){
  digitalWrite(BLINK_LED, HIGH);
  delay(50);
  digitalWrite(BLINK_LED, LOW);
  delay(50);
}

void initWiFi(){
  pinMode(BLINK_LED, OUTPUT);
  WiFi.mode(WIFI_AP);
  WiFi.hostname(SENSOR_ID);
  WiFi.softAP(AP_SSID, AP_PASS);
}
