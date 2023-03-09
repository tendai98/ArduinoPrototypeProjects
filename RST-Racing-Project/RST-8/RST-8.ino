#include "constants.h"
#include "wifi.h"
#include "car.h"
#include "net.h"

char controlBuffer[MAX_LEN];
bool controlsEngaged = false;

void setup(){
  
  startWiFi(AP_SSID, AP_PASS, HOSTNAME);
  
  initVehicleGPIO();
  assignMotorEnableGPIO(TURN_MOTOR, DRIVE_MOTOR);
  assignTurnerGPIO(LEFT_GPIO, RIGHT_GPIO);
  assignDriveGPIO(FORWARD_GPIO, REVERSE_GPIO);
  enableMotors(HIGH);
  shutDownAllMotors();

  startServer(SERVER_PORT);
}

void loop(){

  if(recv(controlBuffer, MAX_LEN)){
    executeControls(controlBuffer);
  }else{
    if(controlsEngaged){
      shutDownAllMotors();
      controlsEngaged = false; 
    }
  }
  
  delay(70); 
}

void executeControls(char * controls){
  controlsEngaged = true;
  
  switch(controls[0]){
     case TURN_LEFT_CODE:
        digitalWrite(RIGHT_GPIO, LOW);
        digitalWrite(LEFT_GPIO, HIGH);
        break;

     case TURN_RIGHT_CODE:
        digitalWrite(RIGHT_GPIO, HIGH);
        digitalWrite(LEFT_GPIO, LOW);
        break;

     case RETURN_TURNER_CODE:
        digitalWrite(RIGHT_GPIO, LOW);
        digitalWrite(LEFT_GPIO, LOW);
        break;        

     case SHUTDOWN_MOTORS:
        shutDownAllMotors();
        break;

     case RUN_FULL_TEST:
        testVehicle();
        break;

     case RESET_CONTROLLER:
        ESP.reset();
        break;
      
  }

  switch(controls[1]){
     case FORWARD_DRIVE_CODE:
        digitalWrite(FORWARD_GPIO, HIGH);
        digitalWrite(REVERSE_GPIO, 0);
        break;

     case REVERSE_DRIVE_CODE:
        digitalWrite(FORWARD_GPIO, 0);
        digitalWrite(REVERSE_GPIO, HIGH);
        break;

     case E_BOOST_DRIVE_MODE:
        digitalWrite(FORWARD_GPIO, HIGH);
        digitalWrite(REVERSE_GPIO, LOW);
        break;

     case STOP_DRIVE_CODE:
        digitalWrite(FORWARD_GPIO, LOW);
        digitalWrite(REVERSE_GPIO, LOW);
        break;     

     case SHUTDOWN_MOTORS:
        shutDownAllMotors();
        break;

     case RESET_CONTROLLER:
        ESP.reset();
        break;
  }
  
}

void testVehicle(){
  shutDownAllMotors();
  
  digitalWrite(LEFT_GPIO, HIGH);
  delay(TEST_DELAY);  
  digitalWrite(RIGHT_GPIO, LOW);
  delay(TEST_DELAY);  
  digitalWrite(LEFT_GPIO, LOW);
  delay(TEST_DELAY);  
  digitalWrite(RIGHT_GPIO, HIGH);
  delay(TEST_DELAY);

  digitalWrite(FORWARD_GPIO, HIGH);
  delay(TEST_DELAY);
  digitalWrite(REVERSE_GPIO, 0);
  delay(TEST_DELAY);
  digitalWrite(FORWARD_GPIO, 0);
  delay(TEST_DELAY);
  digitalWrite(REVERSE_GPIO, HIGH);
  delay(TEST_DELAY);
  
  shutDownAllMotors();
  delay(1000);
} 
