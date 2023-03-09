#include "cmd.h"
#include "cmd_fx.h"

void (*cmd_engine_fx[COMMAND_FUNCTIONS_COUNT])(char * data);

void init_cmd_engine(){
  
  cmd_engine_fx[SHELL_MANAGER] = shell_fx;
  cmd_engine_fx[GPIO_CTRL] = gpio_ctrl;
  cmd_engine_fx[SYSTEM_RST] = system_rst;
  cmd_engine_fx[GET_HELP] = get_help;
  cmd_engine_fx[GET_SYS_INFO] = get_system_info;
  
}

void run_command(char syscall,char * data){
  if(syscall < COMMAND_FUNCTIONS_COUNT){
    cmd_engine_fx[syscall](data);
  }else{
    send_data(CMD_EXEC_MSG);
  }
}
