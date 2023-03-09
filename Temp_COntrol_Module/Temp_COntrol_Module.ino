#include "relay.h"
#include "lcd.h"
#include "dht.h"

#define TARGET_THRESHOLD 15
String data;
int temp;

void setup() {
  initLCD();
  initDHT();
  initRelay();
  relayOff();
}

void loop() {
  
  temp = getTemperature();
  data = "Temp: "+String(temp)+" *C";
  
  if(temp > TARGET_THRESHOLD){
    lcdClear();
    relayOn();
    lcdPrintString("COOLING....",1, 4);
  }else{
    relayOff();
    lcdPrintString("SYSTEM CUTOFF",1, 4);
  }

  lcdPrintObject(&data, 0, 4);
  delay(1000);
}
