
#include <ESP8266WiFi.h>

void initializeWiFi(){
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(AP_SSID,AP_PASS);
  pinMode(D4,OUTPUT);
  pinMode(D4,LOW);
  
  while (WiFi.status() != WL_CONNECTED){
    delay(CONNECT_DELAY);
    Serial.print(".");
  }

  digitalWrite(D4,HIGH);
  Serial.print("[IP Address] -> ");
  Serial.println(WiFi.localIP());
}
