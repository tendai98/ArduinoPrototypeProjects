#define HIGH_TRIGGER_PIN 2
#define BUTTON1_PIN 13
#define BUTTON2_PIN 12
#define BUTTON3_PIN 8

#define BUTTON1_KEYCODE 0x10
#define BUTTON2_KEYCODE 0x11
#define BUTTON3_KEYCODE 0x12

#define TEMPERATURE_PRESET_ADDRESS 0
#define HUMIDITY_PRESET_ADDRESS    4
#define TIMER_CTRL_PRESET_ADDRESS     8

#define RELAY1_PIN 2
#define RELAY2_PIN 4
#define RELAY3_PIN 7

#define MAIN_MENU_CODE 0x40

#define TEMP_LOW_LIMIT 0
#define TEMP_HIGH_LIMIT 99
#define TIME_HIGH_LIMIT 5
#define TIME_LOW_LIMIT 1
#define TIME_MULTIPLIER 1000*60

#define HUMIDITY_LOW_LIMIT 20
#define HUMIDITY_HIGH_LIMIT 99

#define CURSOR_LIMIT 2

#define TEMP_SELECTOR 0
#define HMD_SELECTOR 1
#define TIMER_SELECTOR 2
  
#define BANNER "->> [TinkerTech] <<---[ACS Prototype1]--"
#define CONTROLS "[<] [OK]    [SELECT]"

const int keypadPins[] = {  
      BUTTON1_PIN, 
      BUTTON2_PIN, 
      BUTTON3_PIN
   };

const int relayPins[] = {
    RELAY1_PIN,
    RELAY2_PIN,
    RELAY3_PIN
};

const int keyMap[] = {
  BUTTON1_KEYCODE,
  BUTTON2_KEYCODE,
  BUTTON3_KEYCODE
};
