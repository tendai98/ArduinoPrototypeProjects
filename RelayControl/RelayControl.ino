
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define GPIO1 0
#define GPIO2 2
#define CONTROL_GPIO GPIO2
#define SERVER_PORT 80

#define AP_SSID "Iona-CTRL"
//#define AP_PASS "12345678"
#define AP_PASS "2b3c3afaea63d2f7f26a"
#define DEVICE_ID "1e9a8c632c84593d271f5e89eb5cbda7"
#define INVALID_OPERATION_CODE "55"
#define EXECUTD_OPERATION_CODE "11"

int state = 0;
String data;

ESP8266WebServer server(SERVER_PORT);

void stateOn(){
  state = 1;
  digitalWrite(GPIO1, state);
  digitalWrite(GPIO2, state);
  server.send(200, "text/plain", EXECUTD_OPERATION_CODE);
}

void stateOff(){
  state = 0;
  digitalWrite(GPIO1, state);
  digitalWrite(GPIO2, state);
  server.send(200, "text/plain", EXECUTD_OPERATION_CODE);
}


void getState(){
  server.send(200, "text/plain", String(state));   
}

void getDeviceId(){
  server.send(200, "text/plain", String(DEVICE_ID));  
}

void invalidOperation(){
  server.send(200, "text/plain", INVALID_OPERATION_CODE);
}

void connectToWiFiNetwork(char * ssid, char * password){
   WiFi.begin(ssid, password);
   while(WiFi.status() != WL_CONNECTED){
      delay(100);
   }
}

void setup(){
    WiFi.mode(WIFI_STA);
    connectToWiFiNetwork(AP_SSID, AP_PASS);

    pinMode(GPIO1, OUTPUT);
    pinMode(GPIO2, OUTPUT);

    digitalWrite(GPIO1, LOW);
    digitalWrite(GPIO2, LOW);
      
    server.on("/on", stateOn);
    server.on("/off", stateOff);
    server.on("/state", getState);
    server.on("/id", getDeviceId);
    server.onNotFound(invalidOperation);
    server.begin();
}

void loop(){
  server.handleClient(); 
}
