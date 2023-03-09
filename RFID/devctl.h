#include "SoftwareSerial.h"
SoftwareSerial usbSerial(2, 3);

void ledCtl(unsigned short timeout){
  digitalWrite(DETECT_RFID,HIGH);
  delay(timeout);
  digitalWrite(DETECT_RFID,LOW);
  delay(timeout);
}

void ioctl(){
  while (Serial.available()){
     byte selector = Serial.read();
     if (selector < 2){
       deviceMode = selector;
       break;
      }
    }
}
