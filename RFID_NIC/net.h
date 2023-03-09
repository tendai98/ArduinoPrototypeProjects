#include "wifi.h"
#include <WiFiUdp.h>
#define BUFFER_MAX 20

WiFiUDP server;
unsigned short localPort = 1200;
bool deviceConnected = false;

char Buffer[BUFFER_MAX]={0};

void flushBuffer(){
  for (byte i=0;i<BUFFER_MAX;i++)
    Buffer[i]=0;
}

byte netRecv(){
	byte packetLen = server.parsePacket();
 
	if(packetLen){
    deviceConnected = true;
		server.read(Buffer,BUFFER_MAX);
		return 1;
	}
	return 0;
}

byte netSend(){
	server.beginPacket(server.remoteIP(),server.remotePort());
	server.write(Buffer);
	server.endPacket();
}

void initServer(){
  server.begin(localPort);
}
