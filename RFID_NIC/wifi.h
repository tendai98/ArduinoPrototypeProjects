#include <ESP8266WiFi.h>
#define AP_SSID "Access"
#define AP_PASS "12345678"

void initWiFi(){

  pinMode(D4,OUTPUT);
  WiFi.mode(WIFI_AP);
  WiFi.begin(AP_SSID,AP_PASS);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
  }
  Serial.println(WiFi.localIP());
  pinMode(D4,INPUT);
  
}
