#include <ESP8266WiFi.h>

#define AP_SSID "Server-0000" 
#define AP_PASS "iot_dev_"

void startWiFi(){
  WiFi.mode(WIFI_STA);
  WiFi.begin(AP_SSID, AP_PASS);
  pinMode(D4, OUTPUT);
  
  while(WiFi.status() != WL_CONNECTED){
    delay(100);
    digitalWrite(D4, HIGH);
    delay(100);
    digitalWrite(D4, LOW);
  }

   digitalWrite(D4, LOW);
}
