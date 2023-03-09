#include <Servo.h>

Servo servo;
char control_commands[4];
void control_mycar();

void start_mycar(){
  
  servo.attach(SERVO_PIN);
  
  pinMode(DRIVE_PIN, OUTPUT);
  digitalWrite(DRIVE_PIN, LOW);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  
}

void turn_wheels(int command){

  switch(command){
  
    case LEFT_TURN:
      servo.write(40);
      break;
      
    case RIGHT_TURN:
      servo.write(90);
      break;
    
    case RETURN_POSITION:
      servo.write(66);
      break;  
  
  }
  
}

void drive_train(int command){

  switch(command){
    case FORWARD_DRIVE:
      digitalWrite(DRIVE_PIN,HIGH);
      break;

    case STOP_REAR_WHEELS:
      digitalWrite(DRIVE_PIN,LOW);
      break;

    case CONTROL_CAR:
      control_mycar();
      break;
  }

}

void drive(){
  turn_wheels(control_commands[0]);
  drive_train(control_commands[1]);

}

void reset_systems(){
  turn_wheels(RETURN_POSITION);
  drive_train(STOP_REAR_WHEELS);
}


void control_mycar(){
  
  control_commands[0]=LEFT_TURN;
  control_commands[1]=FORWARD_DRIVE;
  drive();    
  delay(2000);
  
  control_commands[0]=RIGHT_TURN;
  control_commands[1]=STOP_REAR_WHEELS;
  drive(); 
  delay(2000);
  
  control_commands[0]=RETURN_POSITION;
  control_commands[1]=FORWARD_DRIVE;
  drive();   
  delay(2000);
  
}
