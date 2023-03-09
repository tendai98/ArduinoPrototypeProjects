#define PIR_SENSOR D7
#define MOTION_LED D0
#define ACTIVE 1
#define NON_ACTIVE 0

void initMotionSensor(){
  pinMode(PIR_SENSOR,INPUT_PULLUP);
  pinMode(MOTION_LED,OUTPUT);
}

int runMotionSensor(){
   byte sensorState = digitalRead(PIR_SENSOR);
   if(sensorState){
      digitalWrite(MOTION_LED,HIGH);
      return ACTIVE;
    }else{
      digitalWrite(MOTION_LED,LOW);
      return NON_ACTIVE;
  }
}
