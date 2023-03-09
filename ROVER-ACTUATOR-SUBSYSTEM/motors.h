#define RIGHT_MOTORS_ENABLE D2
#define RIGHT_MOTORS_FORWARD D0
#define RIGHT_MOTORS_REVERSE D1

#define LEFT_MOTORS_ENABLE D5
#define LEFT_MOTORS_FORWARD D6
#define LEFT_MOTORS_REVERSE D3


void initMotorControls() {
  pinMode(LEFT_MOTORS_ENABLE, OUTPUT);
  pinMode(LEFT_MOTORS_FORWARD, OUTPUT);
  pinMode(LEFT_MOTORS_REVERSE, OUTPUT);
  pinMode(RIGHT_MOTORS_ENABLE, OUTPUT);
  pinMode(RIGHT_MOTORS_FORWARD, OUTPUT);
  pinMode(RIGHT_MOTORS_REVERSE, OUTPUT);
  digitalWrite(LEFT_MOTORS_ENABLE, HIGH);
  digitalWrite(RIGHT_MOTORS_ENABLE, HIGH);
  delay(1000);
}

void forwardDrive(int driveDelay) {
  digitalWrite(RIGHT_MOTORS_FORWARD, HIGH);
  digitalWrite(LEFT_MOTORS_FORWARD, HIGH);
  digitalWrite(RIGHT_MOTORS_REVERSE, LOW);
  digitalWrite(LEFT_MOTORS_REVERSE, LOW);
  delay(driveDelay);
}

void reverseDrive(int driveDelay) {
  digitalWrite(RIGHT_MOTORS_FORWARD, LOW);
  digitalWrite(LEFT_MOTORS_FORWARD, LOW);
  digitalWrite(RIGHT_MOTORS_REVERSE, HIGH);
  digitalWrite(LEFT_MOTORS_REVERSE, HIGH);
  delay(driveDelay);
}

void leftTurnDrive(int driveDelay) {
  digitalWrite(RIGHT_MOTORS_FORWARD, HIGH);
  digitalWrite(LEFT_MOTORS_FORWARD, LOW);
  digitalWrite(RIGHT_MOTORS_REVERSE, LOW);
  digitalWrite(LEFT_MOTORS_REVERSE, HIGH);
  delay(driveDelay);
}

void rightTurnDrive(int driveDelay) {
  digitalWrite(RIGHT_MOTORS_FORWARD, LOW);
  digitalWrite(LEFT_MOTORS_FORWARD, HIGH);
  digitalWrite(RIGHT_MOTORS_REVERSE, HIGH);
  digitalWrite(LEFT_MOTORS_REVERSE, LOW);
  delay(driveDelay);
}

void killAllMotors(){
  digitalWrite(RIGHT_MOTORS_FORWARD, LOW);
  digitalWrite(LEFT_MOTORS_FORWARD, LOW);
  digitalWrite(RIGHT_MOTORS_REVERSE, LOW);
  digitalWrite(LEFT_MOTORS_REVERSE, LOW);  
}
