#define SERVO_PIN D6
#define GATE_OPEN 180
#define GATE_STOP 90
#define GATE_CLOSE 0
#define RUN_DELAY 200

#include <Servo.h>

Servo boomGateServo;
bool servoRunned = false;

void initServo(){
   boomGateServo.attach(SERVO_PIN);
}

void gateOpen(){
  if(servoRunned){
    boomGateServo.write(GATE_OPEN);
    delay(RUN_DELAY);
    boomGateServo.write(GATE_STOP);
    servoRunned = false;
  }
}

void gateClose(){
  if(!servoRunned){
    boomGateServo.write(GATE_CLOSE);
    delay(RUN_DELAY);
    boomGateServo.write(GATE_STOP);
    servoRunned = true;
  }
}
