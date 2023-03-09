#define ENABLE_TURN_MOTOR D0    // Turn Motor
#define RIGHT_TURN_PIN D1
#define LEFT_TURN_PIN D2

#define ENABLE_DRIVE_MOTOR D7     // Drive Motor
#define FORWARD_DRIVE_PIN D5
#define REVERSE_DRIVE_PIN D6

void setup(){
  pinMode(ENABLE_TURN_MOTOR, OUTPUT);
  pinMode(RIGHT_TURN_PIN, OUTPUT);
  pinMode(LEFT_TURN_PIN, OUTPUT);

  pinMode(ENABLE_DRIVE_MOTOR, OUTPUT);
  pinMode(FORWARD_DRIVE_PIN, OUTPUT);
  pinMode(REVERSE_DRIVE_PIN, OUTPUT);

  digitalWrite(ENABLE_TURN_MOTOR, HIGH);
  digitalWrite(RIGHT_TURN_PIN, LOW);
  digitalWrite(LEFT_TURN_PIN, LOW);

  digitalWrite(ENABLE_DRIVE_MOTOR, HIGH);
  digitalWrite(FORWARD_DRIVE_PIN, LOW);
  digitalWrite(REVERSE_DRIVE_PIN, LOW);
    
}

void runMotorA(){
  digitalWrite(LEFT_TURN_PIN, HIGH);
  delay(1000);
  digitalWrite(LEFT_TURN_PIN, LOW);
  delay(1000);
  digitalWrite(RIGHT_TURN_PIN, HIGH);
  delay(1000);
  digitalWrite(RIGHT_TURN_PIN, LOW);
  delay(1000);
}

void runMotorB(){
  digitalWrite(FORWARD_DRIVE_PIN, HIGH);
  delay(1000);
  digitalWrite(FORWARD_DRIVE_PIN, LOW);
  delay(1000);
  digitalWrite(REVERSE_DRIVE_PIN, HIGH);
  delay(1000);
  digitalWrite(REVERSE_DRIVE_PIN, LOW);
  delay(1000);
}

void forward(short runTime){
  digitalWrite(REVERSE_DRIVE_PIN, LOW);
  digitalWrite(FORWARD_DRIVE_PIN, HIGH);
  delay(runTime);
}

void reverse(short runTime){
  digitalWrite(FORWARD_DRIVE_PIN, LOW);
  digitalWrite(REVERSE_DRIVE_PIN, HIGH);
  delay(runTime);
  
}

void left(short runTime){
  digitalWrite(RIGHT_TURN_PIN, LOW);
  digitalWrite(LEFT_TURN_PIN, HIGH);
  delay(runTime);
}

void right(short runTime){
  digitalWrite(LEFT_TURN_PIN, LOW);
  digitalWrite(RIGHT_TURN_PIN, HIGH);
  delay(runTime);
}

void shutDown(){
  digitalWrite(LEFT_TURN_PIN, LOW); 
  digitalWrite(RIGHT_TURN_PIN, LOW);
  digitalWrite(FORWARD_DRIVE_PIN, LOW); 
  digitalWrite(REVERSE_DRIVE_PIN, LOW);
}


void loop(){
  forward(2000);
  left(2000);
  right(2000);
  reverse(2000);
  shutDown();
  delay(5000);
}
