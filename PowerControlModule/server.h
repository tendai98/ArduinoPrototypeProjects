#include <WiFiUdp.h>

#define DEFAULT_PORT 2020
#define MAX_LEN 2

WiFiUDP server;
char commandData[MAX_LEN];
int * command;

void startServer(){
    server.begin(DEFAULT_PORT);
}


void scanServerData(){
  byte len = server.parsePacket();
  
  if(len){
        server.read(commandData,MAX_LEN);
        command = (int*) &commandData;
        systemControl(*command);     
  }
}
