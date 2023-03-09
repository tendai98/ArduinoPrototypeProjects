
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "Defines.h"

WiFiUDP server;

void flushBuffers(){
  for (Index2 = 0;Index2 < UDP_TX_PACKET_MAX_SIZE;Index2++){
   UPLOAD_BUFFER[Index2]=0;
   PACKET_BUF[Index2]=0; 
  }
}



void  netRecv(){
  PacketLen = server.parsePacket();
  if (PacketLen){
    server.read(PACKET_BUF,UDP_TX_PACKET_MAX_SIZE);
    PARAM = PACKET_BUF;
    
    if (PARAM.substring(0,8).equals("baudrate")){
        PARAM.replace(" ","");
        PARAM.replace("\n","");
        PARAM.replace("\r","");
        PARAM.replace("baudrate","");
        UART_SPEED = PARAM.toInt();
        Serial.begin(UART_SPEED);
        
        server.beginPacket(server.remoteIP(),server.remotePort());
        server.write("[+] UART Serial Port Speed -> ");
        server.write(PARAM.c_str());
        server.write(" B/s\n|");
        server.endPacket();
    
    }
    
    else{
    Serial.println(PACKET_BUF);

    if (Serial.available()){
    while (Serial.available()){
      UPLOAD_BUFFER[Index]=Serial.read();
      Index++;
    }
      
    }
    
    UPLOAD_BUFFER[Index+1]=0;
    server.beginPacket(server.remoteIP(),server.remotePort());
    server.write(UPLOAD_BUFFER);
    server.write("|");
    server.endPacket();
    Index=0;
    flushBuffers(); 
  }
    flushBuffers();
    delay(10);
  }
}

void WIFI_MODE(){
  WiFi.mode(WIFI_AP);
  WiFi.softAP(AP_NAME,AP_PASS);
}


void setup(){
  Serial.begin(UART_SPEED);
  WIFI_MODE();
  server.begin(localPort);
  
}

void loop(){
  netRecv();
}
