#define AP_SSID "ZigBee-Project"
#define AP_PASS "kundai@dl20"
#define PORT 9900

#include <WiFi.h>
#include <WiFiUdp.h>

char  egressBuffer[15];
WiFiUDP udp;

void initNet(){
  WiFi.softAP(AP_SSID,AP_PASS);
  udp.begin(PORT);  
}

void sendInfo(){
  if(isConnected){
    udp.beginPacket(udp.remoteIP(),udp.remotePort());
    udp.printf("%s", egressBuffer);
    udp.endPacket();
  }
}

void recvTrigger(){
  int len =  udp.parsePacket();
  udp.flush();
  if(len > 0){
      isConnected = true;
  }
}

void clearBuffer(){
  for(int i=0;i < BUFFER_MAX; i++){
    egressBuffer[i]=0;
  }
}
