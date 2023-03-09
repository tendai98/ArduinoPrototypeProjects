#define ACTIVATE_RB0 0B00000001     //
#define ACTIVATE_RB1 0B00000010
#define ACTIVATE_RB2 0B00000000
#define SHUTDOWN_PIO 0B00000100

#include <Servo.h>
#define SERVO D7

Servo servo;
const int IO_Drive[] = {D3, D4, D5};


void openMode(){
  servo.write(0);
}


void closeMode(){
  servo.write(90);
}

void initIODriver(){
  servo.attach(SERVO);
  
  for(int i=0; 3 > i; i++){
    pinMode(IO_Drive[i], OUTPUT);
    digitalWrite(IO_Drive[i], LOW);
  }
}

void driveIO(int target){
  switch(target){
     case ACTIVATE_RB0:
        digitalWrite(IO_Drive[0], HIGH);
        digitalWrite(IO_Drive[1], LOW);
        digitalWrite(IO_Drive[2], LOW);
        break;
        
     case ACTIVATE_RB1:
        digitalWrite(IO_Drive[0], LOW);
        digitalWrite(IO_Drive[1], HIGH);
        digitalWrite(IO_Drive[2], LOW);   
        break;

     case ACTIVATE_RB2:
        digitalWrite(IO_Drive[0], HIGH);
        digitalWrite(IO_Drive[1], HIGH);
        digitalWrite(IO_Drive[2], HIGH);   
  }
}
