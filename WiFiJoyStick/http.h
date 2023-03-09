#include <WebServer.h>
#include "joystick.h"

#define HTTP_OK_CODE 200
#define HTTP_ERROR_CODE 404
#define DEFAULT_MIME "text/plain"

WebServer server(80);

void getControllerData(){
  readJoyStickState();
  server.send(HTTP_OK_CODE, DEFAULT_MIME, GLOBAL_CONTROL_DATA);
}

void checkController(){
  for(int i=0; i<10; i++)
    blinkLED();
    
  server.send(HTTP_OK_CODE, DEFAULT_MIME, "Ready");
}

void invalidOperation(){
  server.send(HTTP_ERROR_CODE, DEFAULT_MIME, "NOT SUPPORTED");
}

void resetController(){
 for(int i=0; i<20; i++)
    blinkLED();

  delay(4000);
  ESP.restart();
}

void startServer(){
 server.on("/control", getControllerData);
 server.on("/check", checkController);
 server.on("/reset", resetController);
 server.onNotFound(invalidOperation);
 server.begin();
}

void handleRequests(){
  server.handleClient();
}
