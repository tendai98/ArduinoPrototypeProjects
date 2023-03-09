#include "FS.h"
#include "SD.h"
#include "SPI.h"
#include "fs.h"
#include "net.h"

#define BUFF_MAX 5120

char gpsData[BUFF_MAX];

void nullBuffer(){
  for (int i = 0; BUFF_MAX > i; i++){
    gpsData[i] = 0;
  }
}

bool dumpData(){
  
  bool gotData = false;
  int c = 0;
  
  nullBuffer();

  while(Serial.available()){
     gpsData[c] = (char) Serial.read();
     c++;  
     gotData = true;
  }

  return gotData;
  
}

void setup(){
    Serial.begin(9600);
    if(!SD.begin()){
      return;
    }

  if(readFile(SD, DATA_DUMP)){
  }else{
    writeFile(SD, DATA_DUMP, "");
  }

  startWiFi();
}

void loop(){
    if(dumpData()){
       appendFile(SD, DATA_DUMP, gpsData); 
       Serial.println(gpsData);
    }

    delay(100);
}
