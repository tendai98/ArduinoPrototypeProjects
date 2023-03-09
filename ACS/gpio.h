#define CHANNEL_0 D2    // Relay 1
#define CHANNEL_1 D3    // Relay 2
#define CHANNEL_3 D6    // Relay 3
#define CHANNEL_6 D7    // Relay 4

#define CHANNEL_5 D1    // RED LED
#define CHANNEL_4 D4    // LED Builtin
#define CHANNEL_8 D0    // GREEN LED
#define CHANNEL_2 D5
#define CHANNEL_7 D8    

#define CHANNEL_COUNT 9
#define SELECTED_GPIO CHANNEL_COUNT

#define HIGH_STATE 0xA
#define LOW_STATE 0xB
#define OUTPUT_MODE 0xC
#define INPUT_MODE 0xD

const byte GPIO[] = {
  CHANNEL_0, CHANNEL_1, CHANNEL_2,
  CHANNEL_3, CHANNEL_4, CHANNEL_5, 
  CHANNEL_6, CHANNEL_7, CHANNEL_8
};

byte GPIO_MODE[] = {  0, 0, 0,  0, 0, 0,  0, 0, 0 };
byte GPIO_STATE[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void register_gpio_mode(byte gpio_index,byte gpio_mode){
  GPIO_MODE[gpio_index]=gpio_mode; 
}

void register_gpio_state(byte gpio_index,byte gpio_state){
  GPIO_STATE[gpio_index]=gpio_state;
}

void init_gpio(){
  for (byte gpio_index=0;gpio_index < SELECTED_GPIO; gpio_index++){
    pinMode(GPIO[gpio_index],OUTPUT);
    digitalWrite(GPIO[gpio_index],LOW);
    register_gpio_mode(gpio_index,OUTPUT_MODE);
    register_gpio_state(gpio_index, LOW_STATE);
  }
  
}

void control_gpio_mode(byte gpio_index,byte gpio_mode){
    pinMode(GPIO[gpio_index],gpio_mode);
    if(gpio_mode == OUTPUT){
      register_gpio_mode(gpio_index,OUTPUT_MODE);  
    }else if(gpio_mode == INPUT){
      register_gpio_mode(gpio_index,INPUT_MODE); 
    }
}

void control_gpio_state(byte gpio_index,byte state){
  digitalWrite(GPIO[gpio_index],state);
  if(state == HIGH){
      register_gpio_state(gpio_index,HIGH_STATE);  
    }else if(state == LOW){
      register_gpio_state(gpio_index,LOW_STATE); 
    }
}
