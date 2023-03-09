#include <ESP8266WiFi.h>
#define AP_SSID "AP"
#define AP_PASS "12345678"

void initWiFi(){

  pinMode(D4,OUTPUT);
  WiFi.begin(AP_SSID,AP_PASS);
  
  while (WiFi.status() != WL_CONNECTED){
    Serial.print("."); 
    delay(500);
  }

  digitalWrite(D4,HIGH);
  Serial.print("[+] Connected -> IPADRESS: ");
  Serial.println(WiFi.localIP());
}
