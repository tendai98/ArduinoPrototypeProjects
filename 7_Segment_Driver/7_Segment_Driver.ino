#include "driver.h"

uint8_t systemMode = 0;
char c;

void executeCurrentMode(){
  switch(systemMode){
    case LOOP_MODE:
      loopMode();
      break;

    case PRINT_MODE:
      c = Serial.available() ? printChar(Serial.read()) : 0;
      break;
  }
  
}

void setup() {
  init7SegmentDriver();
  Serial.begin(115200); 
  Serial.print("\nSet a mode: 'l' -> Loop Mode, 'p' -> Print Mode:> ");
  systemMode = setSystemMode();
}

void loop() {
 executeCurrentMode(); 
 delay(2000);
}
