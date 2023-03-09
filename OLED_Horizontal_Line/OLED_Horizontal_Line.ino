#include <Wire.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);
int reverse_offset = 128;
int forward_offset = 0;

void setup(){
  u8g2.begin();
  u8g2.clearBuffer();
}

void loop(){
  
  u8g2.drawHLine(reverse_offset, 8, 10);
  reverse_offset = (reverse_offset == 0) ? 128 : reverse_offset;
  reverse_offset--;
  
  u8g2.drawHLine(forward_offset, 16, 10);
  forward_offset = (forward_offset == 128) ? 0 : forward_offset;
  forward_offset++;

  u8g2.sendBuffer();
  
  delay(50);
  u8g2.clearBuffer();
}
