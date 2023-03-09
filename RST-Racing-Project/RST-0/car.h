int enableTurnMotor, enableDriveMotor;
int leftGPIO, rightGPIO;
int forwardGPIO, reverseGPIO;


void initVehicleGPIO(){
  enableTurnMotor = enableDriveMotor = leftGPIO = -1;
  rightGPIO = forwardGPIO = reverseGPIO = -1;
}

void assignMotorEnableGPIO(int gpio1, int gpio2){
  enableTurnMotor = gpio1;
  enableDriveMotor = gpio2;
  pinMode(enableTurnMotor, OUTPUT);
  pinMode(enableDriveMotor, OUTPUT);
}

void assignTurnerGPIO(int gpio3, int gpio4){
  leftGPIO = gpio3;
  rightGPIO = gpio4;
  pinMode(leftGPIO, OUTPUT);
  pinMode(rightGPIO, OUTPUT);
}

void assignDriveGPIO(int gpio5, int gpio6){
  forwardGPIO = gpio5;
  reverseGPIO = gpio6;
  pinMode(forwardGPIO, OUTPUT);
  pinMode(reverseGPIO, OUTPUT);
}

void enableMotors(int state){
  digitalWrite(enableTurnMotor, state);
  digitalWrite(enableDriveMotor, state);  
}

void shutDownAllMotors(){
  
  digitalWrite(leftGPIO, LOW);
  digitalWrite(rightGPIO, LOW);

  analogWrite(forwardGPIO, 0);
  analogWrite(reverseGPIO, 0);
}
