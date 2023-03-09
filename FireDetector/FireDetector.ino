#include "wifi.h"
#include "server.h"
#define RELAY_GPIO D1

void initRelay(){
  pinMode(RELAY_GPIO, OUTPUT);
  digitalWrite(RELAY_GPIO, LOW);
}

void driveRelay(int state){
  digitalWrite(RELAY_GPIO, state);
}

void setup() {
  initWiFi();
  initServer();
  initRelay();
}

void loop() {
  handleRequest();
  blinkLED();
  if(FIRE_SENSOR_STATE){
    driveRelay(HIGH);
  }else{
    driveRelay(!HIGH);
  }
}
