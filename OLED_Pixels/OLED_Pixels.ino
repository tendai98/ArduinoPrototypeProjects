#include <Wire.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);

int x_offset = 0;

void setup(){
  u8g2.begin();
  u8g2.clearBuffer();
}

void loop(){
  
  u8g2.drawPixel(x_offset+00, 8);
  u8g2.drawPixel(x_offset+00, 9);
  
  u8g2.drawPixel(x_offset+16, 16);
  u8g2.drawPixel(x_offset+16, 17);
    
  u8g2.drawPixel(x_offset+12, 24);
  u8g2.drawPixel(x_offset+12, 25);
  
  u8g2.sendBuffer();

  x_offset = (x_offset == 128) ? 0 : x_offset;
  x_offset++;
    
  delay(20);
  u8g2.clearBuffer();
}
