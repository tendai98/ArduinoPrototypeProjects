#include <ESP8266WiFi.h>
#define AP_SSID "iPhone"
#define AP_PASS "Welcome123!"

void initWiFi(){

  WiFi.begin(AP_SSID,AP_PASS);
  pinMode(D4,OUTPUT);
  
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    digitalWrite(D4,LOW); 
    delay(250);
    digitalWrite(D4,HIGH);
    delay(250);
  }
  
  digitalWrite(D4,HIGH);  
  Serial.print("[+] Connected -> IPADDRESS: ");
  Serial.println(WiFi.localIP());
}
