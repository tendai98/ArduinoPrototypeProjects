#define GPIO_ERROR_MSG "Usage: gpio-ctl <mode> <gpio-index> <gpio-state>"
#define CMD_EXEC_MSG "[!]:[ERROR] Command not supported\n"
#define RESET_MESSAGE "[!] Resetting...\n"
#define NET_INFO_MSG NET_INFO_IP NET_INFO_MAC NET_INFO_SRV NET_INFO_HOST
#define COMMAND_FUNCTIONS_COUNT 5

char * data_buffer;
bool banner_dropped = false;
bool shell_activated = false;

void prompt(){
  send_data(CMD_PROMPT);
}

void shell_fx(char * data){

    if(!banner_dropped){
      send_data(BANNER);
      prompt();
      banner_dropped = true; 
      shell_activated = true;
    }else{
      prompt();
    }
    
}

void gpio_ctrl(char * data){
  
  switch(data[0]){
    case SET_GPIO_STATE:
       control_gpio_state((byte) data[1],(byte) data[2]);
       break;

    case SET_GPIO_MODE:
       control_gpio_mode((byte) data[1],(byte) data[2]);
       break;

     case GET_GPIO_INFO:
        data_buffer = (char*) GPIO_STATE;
        send_data(data_buffer);
        break;

      default:
        send_data(GPIO_ERROR_MSG);
  }
  
}

void system_rst(char * data){
  send_data(RESET_MESSAGE);
  ESP.reset();
}

void get_help(char * data){
  send_data(HELP_INFO);
}

void get_system_info(char * data){
     send_data(SYSTEM_INFO);
}
