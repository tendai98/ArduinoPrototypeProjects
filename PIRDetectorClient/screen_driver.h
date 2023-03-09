#include <U8g2lib.h>
#include <Wire.h>
#define Y_POS 25
#define X_POS 0

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0); // Setup U8G2 Controller Object

void ready_screen(){
  u8g2.begin();
  u8g2.setFont(u8g2_font_tenthinguys_tf); 
}

void clear_screen(){
   u8g2.clearBuffer();
}

void print_char(char c){
   char b[1] = {c};
   u8g2.drawStr(X_POS, Y_POS, b);
   u8g2.sendBuffer();  
}

void print_char_at(char c, int x, int y){
   char b[1] = {c};
   u8g2.drawStr(x, y, b);
   u8g2.sendBuffer();  
}

void print_string(char * ptr){
  
   clear_screen();
   u8g2.drawStr(X_POS, Y_POS, ptr);
   u8g2.sendBuffer();  
}

void print_string_at(char * ptr, int x, int y){

   clear_screen();
   u8g2.drawStr(x, y, ptr);
   u8g2.sendBuffer();
}
