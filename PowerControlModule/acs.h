#define RELAY_CONTROL_PIN D4
#define SENSOR_INPUT_PIN A0

#define RELAY_ON_OPCODE 0x11AA
#define RELAY_OFF_OPCODE 0x22BB
#define RESET_OPCODE 0x33CC

const float FREQUENCY = 50.0;
const float WINDOW = (100.0 / FREQUENCY);
const float INTERCEPT = 0.0;
const float SLOPE = 1.7;
const unsigned long printPeriod = 1000;
unsigned long previousMillis = 0;

#include <Filters.h>

boolean acsOnline = false;
RunningStatistics inputStats;

void initACS(){
  pinMode(RELAY_CONTROL_PIN,OUTPUT);
  digitalWrite(RELAY_CONTROL_PIN,LOW);
  inputStats.setWindowSecs(WINDOW);
  acsOnline = true;
}

double currentReading(){
  
    int RawValue = analogRead(SENSOR_INPUT_PIN);
    inputStats.input(RawValue);
        
    if((unsigned long)(millis() - previousMillis) >= printPeriod) {
      previousMillis = millis();
      double Volts_TRMS = inputStats.sigma()* SLOPE + INTERCEPT;  
      return Volts_TRMS;  
    }
  
}

void controlRelayState(boolean state){
  if(acsOnline){
    if(state){
      digitalWrite(RELAY_CONTROL_PIN,HIGH);
    }else{
      digitalWrite(RELAY_CONTROL_PIN,LOW);
    }
  }
}

void systemControl(unsigned int opcode){

    switch(opcode){
      
        case RELAY_ON_OPCODE:
            controlRelayState(true);
            break;

        case RELAY_OFF_OPCODE:
            controlRelayState(false);
            break;

        case RESET_OPCODE:
            ESP.reset();

         default:
            Serial.println("[!] Invalid Command Opcode");
    }
  
}
