#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char * networkSSID = "motionSensor";
const char * networkPassword = "1234567890";
const int port = 51;
const int getSensorStateCode = 0xFFFFFFF1; 

WiFiUDP udpEndPoint;

void wifi_connect(){
  WiFi.mode(WIFI_STA);
  WiFi.begin(networkSSID, networkPassword);
  while(WiFi.status() != WL_CONNECTED){
    delay(100);
  }
  
  udpEndPoint.begin(port);
}

int recv_data(){
  
  int len = udpEndPoint.parsePacket();
  char b[4] = {0,0,0,0};
  int * value;
  
  if(len > 0){
    udpEndPoint.read(b, 4);
    value = (int *) b;
    return *value;    
  }

  return -1;
}

void send_data(char * dataPointer){
    udpEndPoint.beginPacket(IPAddress(192,168,4,1), port);
    udpEndPoint.write(dataPointer);
    udpEndPoint.endPacket();
}
