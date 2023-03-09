#include "constants.h"
#include "drive.h"
#include "wifi.h"
#include "server.h"

bool wheelsTurned = false;

void setup(){

  init_wifi();
  init_server(SERVER_PORT);
  start_mycar();

}

void loop(){

  if(recv() > 0){ 
    drive();
    wheelsTurned =  true;
  }else{
  
    if(wheelsTurned){
      reset_systems();
      wheelsTurned = false;
    }
  }
  delay(50);

}
