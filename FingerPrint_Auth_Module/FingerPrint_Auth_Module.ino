#include "fps.h"

char readCommand(){
  char command = 0;
  while(Serial.available()){
    command = Serial.read();
  }

  return command;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
    int id;
    
    switch(readCommand()){
      case FPS_SCAN_MODE:
          id = scanFingerprint();
          Serial.println(id);
          break;

      case FPS_PROG_MODE:
          enrollFingerprints();
          break;

      case FPS_CHCK_MODE:
          checkFingerprint();
          break;

      case FPS_FLSH_MODE:
          flushPrints();
          break;
    }

    delay(100);
}
