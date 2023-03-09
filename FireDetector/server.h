#include <ESP8266WebServer.h>
#include "sensor.h"

#define DEFAULT_MIME "text/plain"
#define HTTP_OK_CODE 200
#define HTTP_ERROR_CODE 404

ESP8266WebServer server(80);
int FIRE_SENSOR_STATE = 0;

void getSensorData(){
  FIRE_SENSOR_STATE = readSensorState();
  server.send(HTTP_OK_CODE, DEFAULT_MIME, String(FIRE_SENSOR_STATE));
}

void resetSensor(){
  server.send(HTTP_OK_CODE, DEFAULT_MIME, "Resetting Sensor....");
  delay(3000);
  ESP.reset();
}

void deadend(){
  server.send(HTTP_ERROR_CODE, DEFAULT_MIME, "");
}

void initServer(){
   initSensor();
   server.on("/data", getSensorData);
   server.on("/reset", resetSensor);
   server.onNotFound(deadend);
   server.begin();
}


void handleRequest(){
  server.handleClient();
}
