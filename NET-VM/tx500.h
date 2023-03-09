#define AP_NAME "AndroidAPCD25"
#define AP_PASS "qeny7744"
#define MAX_SIZE 1024
#define NULLBYTE 0
#define ACTIVATOR_BYTE 0xBE
#define ACTIVATE_DEVICE 0xA0
#define DEACTIVATE_DEVICE 0xA1
#define ACTIVATION_CODE 0x11223344
#define DEACTIVATION_CODE 0x44332211

WiFiUDP server;
unsigned int portSpeed = 19200;
const unsigned short localPort = 2020;
unsigned short packetLen = 0;
unsigned int buffer_index = 0;

char recv_packet_buffer[MAX_SIZE]={NULLBYTE};
char send_packet_buffer[MAX_SIZE]={NULLBYTE};
bool isVXCode = false;
bool deviceActivated = false;

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
  int * code;
  
  if (packetLen){
    server.read(recv_packet_buffer,MAX_SIZE);
    
     switch(recv_packet_buffer[0]){
      
      case ACTIVATOR_BYTE:
        if(deviceActivated){ 
          loadVXI(packetLen);
          resetBuffers();
        }
        break;

      case ACTIVATE_DEVICE:
        Serial.println("Activating....");
        code = (int*) ((char*) recv_packet_buffer+1);
        if(*code == ACTIVATION_CODE){
           deviceActivated=true;
           digitalWrite(D4,LOW);
        }
        resetBuffers();
        break;

      case DEACTIVATE_DEVICE:
        Serial.println("Deactivating....");
        code = (int*) ((char*) recv_packet_buffer+1);
        if(*code == DEACTIVATION_CODE){
           deviceActivated=false;
           digitalWrite(D4,HIGH);
        }
        resetBuffers();
        break;

      default:
       Serial.println(recv_packet_buffer);
       readSerialConsole();
       sendData();
         
    }
  }
}
