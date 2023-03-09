#include <ESP8266WebServer.h>

#include "temp.h"
#include "sonar.h"

const int CODE_OK = 200;
const int CODE_404 = 404;
#define MIME "text/plain"
#define OK_MSG "Success"

ESP8266WebServer server(80);

void sendSensorData(){
  server.send(CODE_OK, MIME, String(getTempValue())+String(":")+String(getDistance()));
}

void f_404(){
  server.send(CODE_404, MIME, "No Found");
}

void setupServer(){
    server.on("/value", sendSensorData);  
    server.begin();
    delay(100);
}


void serverHandler(){
  server.handleClient();
}
