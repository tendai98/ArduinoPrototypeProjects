#define DEFAULT_FONT  u8g2_font_profont29_mr

#include <U8g2lib.h>
#include <Wire.h>


U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0); // Setup U8G2 Controller Object

// Ready the OLED to operation
void initOLED(){
   u8g2.begin();
}


// Use the function to write to OLED Display
void oledPrint(char * bufferPointer, int xPosition, int yPosition){

   u8g2.clearBuffer();
   u8g2.setFont(DEFAULT_FONT); 
   u8g2.drawStr(xPosition, yPosition, bufferPointer);
   u8g2.sendBuffer();
}
