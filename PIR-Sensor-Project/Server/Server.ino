#include <ESP8266WiFi.h>
#include<ESP8266WebServer.h>

ESP8266WebServer server(80);

void getvalue() {

server.send(200,"text/plain",String(readAnalog()));
}

void notFound() {
  server.send(404,"text/plain","Not Found");
}

#define AP_SSID "Server-1234"
#define AP_PASS "1234567890"

int readAnalog(){
  return digitalRead(D0);
}

void setup() {
  
  WiFi.mode(WIFI_AP); 
  WiFi.softAP(AP_SSID, AP_PASS);
  server.on("/value",getvalue);
  server.onNotFound(notFound);
  server.begin();
  pinMode(D0, INPUT);
}

void loop() {
  server.handleClient();
}
