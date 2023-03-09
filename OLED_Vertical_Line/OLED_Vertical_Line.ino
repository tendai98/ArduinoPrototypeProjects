#include <U8g2lib.h>
#include <Wire.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);

int xLine1 = 0;
int xLine2 = 128;

void setup(){
  u8g2.begin();
  u8g2.clearBuffer();  
}

void loop(){
  u8g2.drawVLine(xLine1, 8, 10);
  xLine1 = (xLine1 == 128) ? 0 : xLine1;
  xLine1++;
  
  u8g2.drawVLine(xLine2, 16, 5);
  xLine2 = (xLine2 == 0) ? 128 : xLine2;
  xLine2--;

  u8g2.sendBuffer();
  
  delay(30);
  u8g2.clearBuffer();
}
