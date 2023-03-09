#define DEVICE_BAUDRATE 57600
#define TIME_DELAY 1000
#define BUFFER_MAX 15
int isConnected = false;
#include "net.h"


void setup(){
  Serial.begin(DEVICE_BAUDRATE);
  initNet();
}

int checkSerial(){
  int counter = 0;
  
  while(Serial.available()){
    egressBuffer[counter] = Serial.read();
    counter++;
  }
  Serial.print(egressBuffer);
  delay(TIME_DELAY);
  return counter;
  
}

void loop(){
  
  recvTrigger();
  if(checkSerial()){
    sendInfo();  
    clearBuffer();
  }
  
}
