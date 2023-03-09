#include <Wire.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);
int offset = 0;

void setup(){
  u8g2.begin();
  u8g2.clearBuffer();
}

void loop(){

  u8g2.drawCircle(offset, 28, 2);
  u8g2.sendBuffer();

  offset = (offset == 128) ? 0 : offset;
  offset++;

  delay(40);
  u8g2.clearBuffer();
}
