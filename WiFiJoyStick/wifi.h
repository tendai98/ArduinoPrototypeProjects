#include <WiFi.h>

#define AP_ID "Joystick"
#define AP_PD "1234567890"
#define LED 2

void blinkLED(){
   digitalWrite(LED, HIGH);
   delay(100);
   digitalWrite(LED, LOW);
   delay(100); 
}

void startWiFiNet(){
  WiFi.mode(WIFI_AP);
  WiFi.softAP(AP_ID, AP_PD);
  pinMode(LED, OUTPUT);
  blinkLED();
}
