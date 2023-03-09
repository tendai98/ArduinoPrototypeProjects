#define AP_NAME "WAP"
#define AP_PASS "uart-rocks"
#define MAX_SIZE 1024
#define NULLBYTE 0
#define ACTIVATOR_BYTE 0xBE

WiFiUDP server;
unsigned int portSpeed = 19200;
const unsigned short localPort = 2020;
unsigned short packetLen = 0;
unsigned int buffer_index = 0;

char recv_packet_buffer[MAX_SIZE]={NULLBYTE};
char send_packet_buffer[MAX_SIZE]={NULLBYTE};
bool isVXCode = false;

#include "vxe.h"
  
void readSerialConsole(){
  while (true){
    if (Serial.available()){
      send_packet_buffer[buffer_index]=Serial.read();
      buffer_index++;
    }else{
      break;
    }
  }
      send_packet_buffer[buffer_index+1]=NULLBYTE;
      buffer_index=0;
 }

void resetBuffers(){
  for (buffer_index = 0;buffer_index < MAX_SIZE;buffer_index++){
      recv_packet_buffer[buffer_index]=NULLBYTE;
      send_packet_buffer[buffer_index]=NULLBYTE; 
  }
   buffer_index=0;
}

void sendData(){

  if(send_packet_buffer[0]!= NULLBYTE){
        server.beginPacket(server.remoteIP(),server.remotePort());
        server.write(send_packet_buffer);
        server.endPacket();
        resetBuffers();
  }
}

void recvData(){
  packetLen = server.parsePacket();
  
  if (packetLen){
    server.read(recv_packet_buffer,MAX_SIZE);
    
     switch(recv_packet_buffer[0]){
      
      case ACTIVATOR_BYTE: 
        loadVXI(packetLen);
        resetBuffers();
        break;

      default:
       Serial.println(recv_packet_buffer);
       readSerialConsole();
       sendData();
         
    }
  }
}
