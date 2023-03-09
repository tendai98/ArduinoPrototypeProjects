#include "net.h"
#define GET_TRIGGER_STATE 0xFFFFFFF1
#define NO_OPERATION_CODE 0

int code = 0;

void led(){
  digitalWrite(D4, LOW);
  delay(50);
  digitalWrite(D4,HIGH);
  delay(50);
}

void setup() {
  
  init_wifi_network(); 
  init_udp_server();
  pinMode(D4, OUTPUT);
  digitalWrite(D4, HIGH);

}

void loop() {
  
  code = get_operation_code();
  
  switch(code){

      case NO_OPERATION_CODE:
         led();
         break;

      case GET_TRIGGER_STATE:
         write_sensor_state();
         break;
  }
}
