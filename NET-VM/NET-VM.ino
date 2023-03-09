//#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
//#include "tx500.h"

void setup(){
  Serial.begin(portSpeed);
  //WiFi.softAP(AP_NAME,AP_PASS);
  WiFi.begin(AP_NAME,AP_PASS);
  while(WiFi.status() != WL_CONNECTED){
    delay(10);
  }
  Serial.println(WiFi.localIP());
  server.begin(localPort);
  pinMode(D4,OUTPUT);
  digitalWrite(D4,HIGH);
}

void loop(){
 //recvData();
}
