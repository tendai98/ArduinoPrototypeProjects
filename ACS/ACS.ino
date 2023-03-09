#include "banner.h"
#include "init.h"
#include "gpio.h"
#include "wlan.h"
#include "server.h"
#include "cmd_engine.h"

#define REQUEST_SIGNATURE 0xFFAC50E1
#define COMMAND_OPCODE_OFFSET 4
#define DATA_OFFSET 5
#define UART_BAUDRATE 9600

char recv_buffer[MAX_BUFFER_SIZE];

void execute_cmd(){
  if(recv_data(recv_buffer)){
      int * check_signature = (int*) recv_buffer;
      if(* check_signature == REQUEST_SIGNATURE){
        run_command(recv_buffer[COMMAND_OPCODE_OFFSET],((char *) recv_buffer+DATA_OFFSET));         
      }
  }
}

void setup() {
  Serial.begin(UART_BAUDRATE);
  init_leds();
  init_gpio();
  init_server();
  init_cmd_engine();
  init_wlan_mode(MANAGED_MODE);
  toggle_leds(OK_LED,HIGH);
}


void loop() {
  execute_cmd();
  delay(100);
}
