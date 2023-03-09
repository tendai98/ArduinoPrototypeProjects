#define I2C_ADDR 0x27
#define LCD_COLUMNS 16
#define LCD_ROWS 2

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_ROWS);  

void initLCD(){
  Wire.begin(D2,D1);
  lcd.backlight();           
  lcd.home();      
}

void lcdPrint(char * data){
  lcd.print(data);  
}

void lcdClear(){
  lcd.clear();
}
