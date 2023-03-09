#include <EEPROM.h>

#include "constants.h"
#include "utils.h"

#include "lcd.h"
#include "keypad.h"
#include "mcp.h"


bool menu = false, presetsLoaded = false;

int currentKeyCode = 0;
int currentCursorPosition = 0, lastCursorPosition = 0;
int selector = 0;
int key = 0;
int limit = 0;

void initGPIO(){
  
  pinMode(HIGH_TRIGGER_PIN, OUTPUT);
  digitalWrite(HIGH_TRIGGER_PIN, HIGH);
   
  for (int index = 0; KEYCOUNT > index; index++){
    pinMode(keypadPins[index], INPUT);
    pinMode(relayPins[index], OUTPUT);
    digitalWrite(relayPins[index], LOW);
    digitalWrite(keypadPins[index], HIGH);  
  }
}

void printBanner(){
  setLCDCursor(0,0);
  lcdPrint(BANNER);
  delay(3000);
  clearScreen();
}

void cursorIncrement(){
   if(CURSOR_LIMIT >= currentCursorPosition){
      lcdPrintAt(">", 0, currentCursorPosition);
      selector = currentCursorPosition;
      lastCursorPosition = currentCursorPosition;
      
      if((currentCursorPosition - 1) >= 0){
        
        lcdPrintAt(" ", 0, (currentCursorPosition - 1));  
      }      
      
      currentCursorPosition++;
      
   }else{
      lastCursorPosition = currentCursorPosition;
      lcdPrintAt(" ", 0, (currentCursorPosition - 1));    
      selector = currentCursorPosition = 0;  
      lcdPrintAt(">", 0, currentCursorPosition); 
   }
}

int resetValue(int chr , int line, int type){
  
  switch(type){
      case TEMP_SELECTOR:
         lcdPrintAt("    ", chr, line);
         return TEMP_LOW_LIMIT;

      case HMD_SELECTOR:
         lcdPrintAt("    ", chr, line);
         return HUMIDITY_LOW_LIMIT;

      case TIMER_SELECTOR:
         lcdPrintAt("    ", chr, line);
         return TIME_LOW_LIMIT;
  }

}

void cleanUpAndCommit(){
  
  presetsLoaded = false;
  menu = false;
  lcdPrintAt(" ", 0, (lastCursorPosition));  
  currentCursorPosition = selector = 0;

  EEPROM.put(TEMPERATURE_PRESET_ADDRESS, tempSetting);
  EEPROM.put(HUMIDITY_PRESET_ADDRESS, humiditySetting);
  EEPROM.put(TIMER_CTRL_PRESET_ADDRESS, activationTimeSetting);
  
  clearScreen();
  lcdPrintAt("[Presets Saved]", 2, 1);
  delay(1000);
  clearScreen();  
  renderControls();
}


void setup() {
  initGPIO();
  initLcd();
  initMCP();
  printBanner();
  renderControls();
}

void loop() {
  key = readKeypad();
  
  if(key == BUTTON3_KEYCODE){
    menu = true;
  }
  
  if(menu){
    switch(key){
      case BUTTON1_KEYCODE:
         if(menu){
            switch(selector){
                case TEMP_SELECTOR:
                    tempSetting = (tempSetting >= TEMP_HIGH_LIMIT) ? resetValue(16, 0, TEMP_SELECTOR) : tempSetting += 1; 
                    break;
                    
                case HMD_SELECTOR:
                    humiditySetting = (humiditySetting >= HUMIDITY_HIGH_LIMIT) ? resetValue(16, 1, HMD_SELECTOR) : humiditySetting += 1;
                    break;
                    
                case TIMER_SELECTOR:
                    activationTimeSetting = (activationTimeSetting >= TIME_HIGH_LIMIT) ? resetValue(16, 2, TIMER_SELECTOR) : activationTimeSetting += 1;
                    break;
            }
         }
         
         renderCurrentData();
         delay(400);
         break;

      case BUTTON2_KEYCODE:
        if(menu){
          cleanUpAndCommit();
        }
        break;

      case BUTTON3_KEYCODE:
        cursorIncrement();
        delay(500);
        break;
    } 
    
  }else{
    if(!presetsLoaded){
      presetsLoaded = true;
      loadPresets(); 
    }

    mainControlSub();
  }
  
}
