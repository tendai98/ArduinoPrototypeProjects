#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LCD_COLS 16
#define LCD_ROWS 2
#define DEVICE_ADDR 0x27
#define SENSOR A0
#define ALERT_MSG "GSM DETECTED"
#define SCANNR_MSG "Scanning..."
#define DELAY 1000
#define BLUE_LED D0
#define BUZZER D5

LiquidCrystal_I2C lcd(DEVICE_ADDR, LCD_COLS, LCD_ROWS);  

unsigned int readSensor(){
  Serial.println(analogRead(SENSOR));
  analogRead(SENSOR);
}

void warn(unsigned int state){
  digitalWrite(BUZZER,state);
  digitalWrite(BLUE_LED,state);
}

void setup(){
  Serial.begin(115200);
  lcd.init();                      
  lcd.backlight();
  pinMode(D4,OUTPUT);
  pinMode(BLUE_LED,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  digitalWrite(D4,HIGH);
}

void loop(){
  
  lcd.setCursor(0, 0);
  
  if(readSensor() > 1000){
    lcd.print(ALERT_MSG);
    warn(HIGH);
  }else{
    lcd.print(SCANNR_MSG);
    warn(LOW);
  }
  
  delay(DELAY);
  lcd.clear();
    
}
