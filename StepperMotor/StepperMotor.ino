#define A 2
#define B 3
#define C 4
#define D 5

void setup() {
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
}

void writeMotor(bool a,bool b,bool c,bool d){
  digitalWrite(A,a);
  digitalWrite(B,b);
  digitalWrite(C,c);
  digitalWrite(D,d);
}

void loop(){
  
}

void driveMotor() {
   writeMotor(1,0,0,0);
   delay(5);
   writeMotor(1,1,0,0);
   delay(5);
   writeMotor(0,1,0,0);
   delay(5);
   writeMotor(0,0,1,0);
   delay(5);
   writeMotor(0,0,1,1);
   delay(5);
   writeMotor(0,0,0,1);
   delay(5);
   writeMotor(1,0,0,0);
   delay(5);
}
