#include <LiquidCrystal_I2C.h>

#define LCD_I2C_ADDRESS 0x27
#define LCD_ROWS 4
#define LCD_COLS 16

LiquidCrystal_I2C lcdController(LCD_I2C_ADDRESS, LCD_COLS, LCD_ROWS);
int cursorLine = 0;

void setLCDCursor(int character, int line){
  lcdController.setCursor(character, line);
}

void clearScreen(){
  lcdController.clear();
}

void lcdPrint(char * charBuffer){
  lcdController.print(charBuffer);
}

void lcdPrintAt(String Buffer, int character, int line){
    lcdController.setCursor(character, line);
    lcdController.print(Buffer);    
}

void renderControls(){
  setLCDCursor(0,3);
  lcdPrint(CONTROLS);
  setLCDCursor(0,0);
}

void initLcd(){
   lcdController.init();
   lcdController.clear();
   lcdController.backlight();
}
