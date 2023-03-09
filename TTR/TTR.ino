#include "constants.h"
#include "drive.h"
#include "wifi.h"
#include "server.h"

void setup(){
  initWiFi();
  initServer(SERVER_PORT);
  initDriveSystem();
}

void loop(){
  if(recv()){
    executeDriveControls();
  }else{
    resetDriveControls();
  }
  delay(70);
}
