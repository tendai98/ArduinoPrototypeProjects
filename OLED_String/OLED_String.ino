#include <Wire.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);

void setup(){
  u8g2.begin();
}

void print_oled(char * buff, int x, int y){
  u8g2.drawStr(x, y, buff);
  u8g2.sendBuffer();
}

void loop(){

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_profont29_mr);
  print_oled("Hello World", 64, 16);
  u8g2.sendBuffer();

  delay(1000);
}
