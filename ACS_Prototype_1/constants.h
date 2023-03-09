#define HIGH_TRIGGER_PIN 2
#define BUTTON1_PIN 13
#define BUTTON2_PIN 12
#define BUTTON3_PIN 8

#define BUTTON1_KEYCODE 0x10
#define BUTTON2_KEYCODE 0x11
#define BUTTON3_KEYCODE 0x12

#define RELAY1_PIN 2
#define RELAY2_PIN 4
#define RELAY3_PIN 7

#define MAIN_MENU_CODE 0x40

#define BANNER "->> [TinkerTech] <<---[ACS Prototype1]--"
#define CONTROLS "<<  [ENTER]   [MENU]"

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
