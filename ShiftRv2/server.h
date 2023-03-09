#include <WiFiUdp.h>

WiFiUDP server;

void init_server(int  port){
  server.begin(port);
}

bool recv(){
  byte packet_len = server.parsePacket();
  
  if(packet_len > 0){
      server.read(control_commands,4);
      return true;
  }
  
  return false;
}
