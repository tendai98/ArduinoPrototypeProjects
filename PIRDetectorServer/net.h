#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char * networkSSID = "motionSensor";
const char * networkPassword = "1234567890";
const int maximumByteCount = 4;
const int port = 51;

char dataBuffer[maximumByteCount];
char outBoundBuffer[2];

WiFiUDP udpEndPoint;

void init_wifi_network(){
  WiFi.softAP(networkSSID, networkPassword);
}

void init_udp_server(){
  udpEndPoint.begin(port);
}

int get_operation_code(){
  int len = udpEndPoint.parsePacket();
  int * opcode;
  
  if(len > 0){
    udpEndPoint.read(dataBuffer, maximumByteCount);
    opcode = (int*) dataBuffer;
    return *opcode;    
  }else{
    return 0;
  }
}

void send_data(char * dataPointer){
    udpEndPoint.beginPacket(udpEndPoint.remoteIP(), udpEndPoint.remotePort());
    udpEndPoint.write(dataPointer);
    udpEndPoint.endPacket();
}

void write_sensor_state(){
    String state = String(digitalRead(D0));
    state.toCharArray(outBoundBuffer, 2);
    send_data(outBoundBuffer);
}
