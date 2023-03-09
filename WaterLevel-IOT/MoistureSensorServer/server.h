#include <ESP8266WebServer.h>
#include "moisture.h"

#define HTTP_OK_CODE 200
#define DEFAULT_MIME "text/plain"

ESP8266WebServer server(80);

void getProcessedSensorData(){
  float rawValue = ((MAX_ADC - getRawSensorReading()) * 100.0) / MAX_ADC;
  server.send(HTTP_OK_CODE, DEFAULT_MIME, String(rawValue)); 
}

void setupHTTPServer(){
  server.on("/data", getProcessedSensorData);
  server.begin();
}

void handleRequest(){
  server.handleClient();
}
