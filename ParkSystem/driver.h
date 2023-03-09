#define LEFT_PARK_BAY_LED D7
#define RGHT_PARK_BAY_LED D8
#define LEFT_PARK_BAY_SENSOR D1
#define RGHT_PARK_BAY_SENSOR D0

#define BOOM_GATE D3

#define BAY_0_OPEN 1
#define BAY_0_CLOS 2
#define BAY_1_OPEN 3
#define BAY_1_CLOS 4
#define BOOM_GATE_OPEN 5
#define BOOM_GATE_CLOS 6

#define BAY_OPEN 1
#define BAY_CLOS 0
#define BAY_0 1
#define BAY_1 2

#include <Servo.h>
Servo boomGateServo;

void controlBay(int bayId,int mode){
  switch(bayId){
    case BAY_0:
      if(mode == BAY_OPEN){
        digitalWrite(RGHT_PARK_BAY_LED,HIGH);
      }else if(mode == BAY_CLOS){
        digitalWrite(RGHT_PARK_BAY_LED,LOW);        
      }
      break;

    case BAY_1:
      if(mode == BAY_OPEN){
        digitalWrite(LEFT_PARK_BAY_LED,HIGH);
      }else if(mode == BAY_CLOS){
        digitalWrite(LEFT_PARK_BAY_LED,LOW);        
      }
      break;
  }
}

int getSensors(){
   int state = !digitalRead(RGHT_PARK_BAY_SENSOR)*1;
   state |= !digitalRead(LEFT_PARK_BAY_SENSOR)*2;
   return state;
}

void runBoomGate(int mode){
  switch(mode){
    case BOOM_GATE_OPEN:
      boomGateServo.write(180);
      break;
    case BOOM_GATE_CLOS:
      boomGateServo.write(68);
      break;
  }
}

void executeRequest(int requestCode){
  switch(requestCode){
    case BAY_0_OPEN:
      controlBay(BAY_0,BAY_OPEN);
      break;
    case BAY_0_CLOS:
      controlBay(BAY_0,BAY_CLOS);
      break;
    case BAY_1_OPEN:
      controlBay(BAY_1,BAY_OPEN);
      break;
    case BAY_1_CLOS:
      controlBay(BAY_1,BAY_CLOS);
      break;
    case BOOM_GATE_OPEN:
      runBoomGate(BOOM_GATE_OPEN);
      break;
    case BOOM_GATE_CLOS:
      runBoomGate(BOOM_GATE_CLOS);
      break;
  }
 
}

void initSystem(){
  pinMode(LEFT_PARK_BAY_LED,OUTPUT);
  pinMode(RGHT_PARK_BAY_LED,OUTPUT);
  pinMode(LEFT_PARK_BAY_SENSOR,INPUT);
  pinMode(RGHT_PARK_BAY_SENSOR,INPUT);
  boomGateServo.attach(BOOM_GATE);
}
