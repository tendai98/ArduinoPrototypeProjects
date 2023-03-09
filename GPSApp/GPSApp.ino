#include "SoftwareSerial.h"

SoftwareSerial wnicSerial = SoftwareSerial(2, 3);
SoftwareSerial gpsSerial = SoftwareSerial(4, 5);
char c = 0;

int readSerialDevice(SoftwareSerial * serialDevice){
   bool dataDumped = false;
   int len = 0;
   
   while(serialDevice->available()){
      c = serialDevice->read();
      Serial.print(c);
      len++;
      dataDumped = true;
   }
    return dataDumped ? Serial.println() | len : len;
}

int forwardSerialData(SoftwareSerial * srcDev, SoftwareSerial * destDev){
   bool dataDumped = false; int len = 0;
   
   while(srcDev->available()){
      c = srcDev->read();
      destDev->print(c);
      len++;
      dataDumped = true;
   }
    return dataDumped ? srcDev->println() | len : len;  
}

void setup(){
  wnicSerial.begin(9600);
  gpsSerial.begin(9600);
  Serial.begin(9600);
}


void loop(){
   readSerialDevice(&gpsSerial);
   delay(100);
   forwardSerialData(&gpsSerial, &wnicSerial);
   delay(100);
}
