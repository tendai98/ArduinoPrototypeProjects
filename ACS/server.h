#define SERVER_PORT 7600
#define MAX_BUFFER_SIZE 64
#include <WiFiUdp.h>

WiFiUDP server;

void init_server(){
  server.begin(SERVER_PORT);
}

void clear_buffer(char * buffer_ptr){
  for(byte i=0; i<MAX_BUFFER_SIZE; i++){
    buffer_ptr[i]=0;
  }
}

byte recv_data(char * buffer_ptr){
    int len =  server.parsePacket();
    if(len){
      clear_buffer(buffer_ptr);
      server.read(buffer_ptr,MAX_BUFFER_SIZE);
      return len;
    }
    return len;
}

void send_data(char * data){
  server.beginPacket(server.remoteIP(),server.remotePort());
  server.write(data);
  server.endPacket();
}
