#include <ESP8266WebServer.h>
#include "motors.h"

#define HTTP_OK_CODE 200
#define DEFAULT_MIME "text/plain"
#define SUBSYSTEM_ID "ROV3R:RMCS"

ESP8266WebServer server(80);
int driveDelay = 0;

void forwardDriveProcedure(){
    driveDelay = server.arg(0).toInt();
    forwardDrive(driveDelay);
    server.send(HTTP_OK_CODE, DEFAULT_MIME, "FORWARD");
    killAllMotors();
}

void reverseDriveProcedure(){
    driveDelay = server.arg(0).toInt();    
    reverseDrive(driveDelay);
    server.send(HTTP_OK_CODE, DEFAULT_MIME, "REVERSE");
    killAllMotors();
}

void rightTurnProcedure(){
    driveDelay = server.arg(0).toInt();
    rightTurnDrive(driveDelay);
    server.send(HTTP_OK_CODE, DEFAULT_MIME, "RIGHT TURN");
    killAllMotors();
}

void leftTurnProcedure(){
    driveDelay = server.arg(0).toInt();
    leftTurnDrive(driveDelay);
    server.send(HTTP_OK_CODE, DEFAULT_MIME, "LEFT TURN");
    killAllMotors();
}

void shutDownMotors(){
  killAllMotors();
  server.send(HTTP_OK_CODE, DEFAULT_MIME, "HALT");  
}

void beaconEndpoint(){
  server.send(HTTP_OK_CODE, DEFAULT_MIME, SUBSYSTEM_ID);
}

void resetController(){
  server.send(HTTP_OK_CODE, DEFAULT_MIME, "SUBSYSTEM RESET...");
  delay(4000);
  ESP.reset();
}

void deadend(){
  server.send(HTTP_OK_CODE, DEFAULT_MIME, "");
}

void initControlServer(){
  server.on("/forward", forwardDriveProcedure);
  server.on("/reverse", reverseDriveProcedure);
  server.on("/left", leftTurnProcedure);
  server.on("/right", rightTurnProcedure);
  server.on("/stop", shutDownMotors);
  server.on("/reset", resetController);
  server.on("/id", beaconEndpoint);
  server.onNotFound(deadend);
  server.begin();  
}

void runControlServer(){
  server.handleClient();
}
