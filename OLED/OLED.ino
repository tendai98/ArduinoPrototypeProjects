#include <Wire.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0); // Setup U8G2 Controller Object

void setup() {
  u8g2.begin();
  u8g2.setFont(u8g2_font_tenthinguys_tf);
  u8g2.drawStr(16, 16,"Hello");
  u8g2.sendBuffer();
}

void loop() {
}
