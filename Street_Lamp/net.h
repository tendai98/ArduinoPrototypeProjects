
#include <ESP8266WiFi.h>


void initializeWiFi(){
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(AP_SSID,AP_PASS);
  pinMode(D4, OUTPUT);
  
  while (WiFi.status() != WL_CONNECTED){
    delay(CONNECT_DELAY);
    Serial.print(".");
    analogWrite(D4, 1023);
    delay(100);
    analogWrite(D4, 0);
  }

  Serial.print("[IP Address] -> ");
  Serial.println(WiFi.localIP());
}
