#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define AP_NAME "ESP-HYBRID"
#define AP_PASS "12345678"
#define MAX_LEN 30
#define HTTP_OK_CODE 200

ESP8266WebServer server(80);
String data = "";
char c;

void getData(){
  data = "";
  while(Serial.available()){
      c = Serial.read();
      data += String(c);
      if(c == 10 || data.length() == MAX_LEN){
        break;            
      }
  }
}

void sendTimeData(){
  getData();
  server.send(HTTP_OK_CODE, "text/plain", data);
}

void resetNET(){
  server.send(HTTP_OK_CODE, "text/plain", "RESET");
  delay(2500);
  ESP.reset();
}

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(AP_NAME, AP_PASS);
  
  server.on("/time", sendTimeData);
  server.on("/reset", resetNET);
  server.begin();
}

void loop() {
  server.handleClient();
}
