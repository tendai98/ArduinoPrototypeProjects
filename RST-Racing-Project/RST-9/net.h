#include <WiFiUdp.h>

WiFiUDP server;

void startServer(int port){
  server.begin(port);
}

bool recv(char * buff, int len){
  if(server.parsePacket()){
    server.read(buff, len);
    return true;
  }else{
    return false; 
  }
}
