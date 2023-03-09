#include <ESP8266WiFi.h>

#include<ESP8266WebServer.h>

ESP8266WebServer server(80);

void getvalue() {

server.send(200,"text/plain",String(readAnalog()));
}

void notFound() {
  
  server.send(404,"text/plain","Not Found");
  

  
}

#define AP_SSID "Server-0000"

#define AP_PASS "iot_dev_"

int readAnalog(){
  
  return analogRead(A0);
}

void setup() {
  
  WiFi.mode(WIFI_AP); 
  WiFi.softAP(AP_SSID, AP_PASS);
  server.on("/value",getvalue);
  server.onNotFound(notFound);
  server.begin();
  
}

void loop() {

  server.handleClient();
  
  

}
