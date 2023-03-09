#include "constants.h"
#include "firebase.h"
#include "net.h"
#include "hw.h"

int cmd , groupCode;

void resetCommand(){
    path = String(LAMP_ID COMMAND);  
    set(path, NO_OPERATION);
    dht.begin();
}

void setup() {
  Serial.begin(9600);
  initializeWiFi();
  initializeFirebase();
  checkNodeStatus();
  pinMode(PIR_SENSOR_PIN, INPUT);
}

void loop() {

  path = String(LAMP_ID LED_GROUP_0_DATA)+String(millis());
  set(path, analogRead(A0));

  path = String(LAMP_ID LED_GROUP_0_ANALOG_VALUE);
  set(path, analogRead(A0));
  
  path = String(LAMP_ID COMMAND);
  cmd = get(path);
    
  switch(cmd){
       case NO_OPERATION:
          break;

       case GROUP_CTL:
          path = String(LAMP_ID TARGET_GROUP);
          groupCode = get(path);
          controlGroup(groupCode);
          resetCommand();
          break;

       case LAMP_ON:
          lampOn();
          resetCommand();
          break;

       case LAMP_OFF:
          lampOff();
          resetCommand();
          break;

       case FULL_LAMP:
          fullLampOn();
          resetCommand();
          break;
          
       case RESET_MODULE:
          resetCommand();
          ESP.reset();
          break;

  }

    if(getPIRTrigger(PIR_SENSOR_PIN)){
      activateLampDevice();
      delay(1000*15);
    }else{
      lampDim();
    }


    uploadDHT11Data();
}
