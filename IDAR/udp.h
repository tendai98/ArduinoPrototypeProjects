#include <WiFiUdp.h>

#define GET_DATA_REQ_CODE   0xBBBBBBB1
#define RESET_SYSTEM_CODE   0xBBBBBBB2
#define MAX_LEN 4

WiFiUDP server;

char command[MAX_LEN];
const char HIGH_STATE[] = "1";
const char LOW_STATE[] = "0";
int state;

void initServer(int port){
    server.begin(port);
}

void  flashLed(){
  digitalWrite(D4, OUTPUT);
  delay(200);
  digitalWrite(D4, HIGH);
}

void executeOperation(int code){

    switch(code){
        case GET_DATA_REQ_CODE:
            state = digitalRead(D0);
            if(state){
              server.beginPacket(server.remoteIP(), server.remotePort());
              server.write(HIGH_STATE);
              server.endPacket();
            }else{
              server.beginPacket(server.remoteIP(), server.remotePort());
              server.write(LOW_STATE);
              server.endPacket();              
            }
            flashLed();
            break;

        case RESET_SYSTEM_CODE:
          ESP.reset();
          break;      
    }
  
}

int recvData(){
  
  int packetLength = server.parsePacket();
  int * opcode;
  
  if(packetLength){
       server.read(command, MAX_LEN);
       opcode = (int *) command;
       return *opcode;
  }else{
    return 0;
  }
}
