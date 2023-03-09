#include "net.h"
#include "udp.h"

int operationCode = 0;

void setup() {
  
  pinMode(D0, INPUT);
  pinMode(D4, OUTPUT);
  digitalWrite(D4, HIGH);

  startWifi();
  initServer(5353);
}

void loop() {
  
  operationCode = recvData();
  
  if(operationCode){
    executeOperation(operationCode);
  } 
  
}
