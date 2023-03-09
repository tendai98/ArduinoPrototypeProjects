#include "net.h"
#define READ_MODE '\x00'

void setup() {
  Serial.begin(9600);
  initWiFi();
  initServer();
}

byte readData(){
   byte index = 0;
   
    while (Serial.available()){
       Buffer[index] = (char) Serial.read();
       index++;
    }
    return index;
}

void loop() {
 
  if(netRecv()){
      bool check = Buffer[0]==0x41 && Buffer[1]==0x42 && Buffer[2]==0x30 &&  Buffer[3]== 0x31;
      if(check){
          Serial.print(READ_MODE); 
      }
  }

  if(readData()){
    netSend();
  }

  flushBuffer();
  delay(50);
}
