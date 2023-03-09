#include "constants.h"
#include "utils.h"
#include "lcd.h"
#include "testMenu.h"
#include "configMenu.h"
#include "mainMenu.h"
#include "keypad.h"

int currentKeyCode = 0;
int selector = 0;
int key = 0;
int limit = 0;
bool menuSelected = false;

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


void setup() {
  initGPIO();
  initLcd();
  printBanner();
  renderControls();
}


void loop() {
  key = readKeypad();
  
  if(key){
    switch(key){
        case BUTTON1_KEYCODE:
            if(menuSelected){
               selector = controlCursor(1, limit); 
            }
            break;

        case BUTTON2_KEYCODE:
            switch(selector){
               case 0:
                  break;

               case 1:
                  cursorLine = selector = 0;
                  limit = showTestMenu();
                  break;
            }
            break;

        case BUTTON3_KEYCODE:
            limit = mainMenu(); 
            menuSelected = true;
            break;
            
    }
    
  }

  delay(10);
}
