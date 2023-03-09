#include <ESP8266WiFi.h>

void setup(){
  WiFi.mode(WIFI_STA);
  WiFi.begin("JE","judie4541");
  while (WL_CONNECTED != WiFi.status()){
    delay(100);
  }

  pinMode(D4, OUTPUT);
  digitalWrite(D4, LOW);
}

void loop(){
  delay(1000);
}
