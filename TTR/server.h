#include <WiFiUdp.h>

WiFiUDP server;
void initServer(int  port){
  server.begin(port);
}

bool recv(){
  byte packet_len = server.parsePacket();
  if(packet_len){
    server.read(driveCommands,4);
    return true;
  }
  return false;
}
