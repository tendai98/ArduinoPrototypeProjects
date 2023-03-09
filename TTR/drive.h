#include <Servo.h>
#define SERVO_PIN D1
#define DRIVE_PIN D3
#define LED_PIN D4

#define FORWARD 0xF1
#define NEUTRAL 0xD0
#define LEFT_TURN 0xA0
#define RIGHT_TURN 0xB0
#define RETURN 0xFF
#define TEST_DRIVE 0xEE

Servo turningServo;
char driveCommands[4];
void testDrive();

void initDriveSystem(){
  turningServo.attach(SERVO_PIN);
  pinMode(DRIVE_PIN,OUTPUT);
  digitalWrite(DRIVE_PIN,LOW);
  pinMode(LED_PIN,OUTPUT);
  digitalWrite(LED_PIN,HIGH);
}

void flashLed(){
  digitalWrite(D4,LOW);
  delay(70);
  digitalWrite(D4,HIGH);
}

void turningSystem(char opcode){ 
  switch(opcode){
    case LEFT_TURN:
      turningServo.write(40);
      break;
      
    case RIGHT_TURN:
      turningServo.write(90);
      break;
    
    case RETURN:
      turningServo.write(68);
      break;  
  }
}

void rearDriveSystem(char opcode){
  switch(opcode){
    case FORWARD:
      digitalWrite(DRIVE_PIN,HIGH);
      break;

    case NEUTRAL:
      digitalWrite(DRIVE_PIN,LOW);
      break;

    case TEST_DRIVE:
      testDrive();
      break;
  }
}

void executeDriveControls(){
  turningSystem(driveCommands[0]);
  rearDriveSystem(driveCommands[1]);
}

void resetDriveControls(){
  turningSystem(RETURN);
  rearDriveSystem(NEUTRAL);
}


void testDrive(){
  flashLed();
  driveCommands[0]=LEFT_TURN;
  driveCommands[1]=FORWARD;
  executeDriveControls();    
  delay(1000);
  driveCommands[0]=RIGHT_TURN;
  driveCommands[1]=NEUTRAL;
  executeDriveControls();    
  delay(1000);
  driveCommands[0]=RETURN;
  driveCommands[1]=FORWARD;
  executeDriveControls();    
  delay(1000);
}
