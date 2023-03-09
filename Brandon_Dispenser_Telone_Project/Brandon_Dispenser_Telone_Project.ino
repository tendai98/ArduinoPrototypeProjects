#include "io_driver.h"
#include "sensors.h"

#define TEMP_LIMIT 30

void setup() {
  initIODriver();
  initMLX();
}

void loop() {
  if(getProx()){
    if(getTemp() > TEMP_LIMIT){
      driveIO(ACTIVATE_RB1); 
      buzz(50);
      closeMode();
    }else{
        driveIO(ACTIVATE_RB0);
        openMode(); 
    }
  }else{
        driveIO(ACTIVATE_RB2);
        closeMode();      
  }
}
