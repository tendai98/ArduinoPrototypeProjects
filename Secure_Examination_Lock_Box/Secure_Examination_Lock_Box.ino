#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Fingerprint.h>
#include "SoftwareSerial.h"

SoftwareSerial    fingerPrint(2, 3);
SoftwareSerial    gps(6, 7);
LiquidCrystal_I2C lcd(0x27, 16, 2);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&fingerPrint);

char c;

void wnicTest(){
  bool data = false;
  while(Serial.available()){
    c = Serial.read();
    Serial.print(c);
    data = true;
  }

  if(data){
      lcd.print("WNIC");
  }
  Serial.println();
}

void gpsTest(){
  gps.begin(9600);
  delay(1000);
  bool data = false;
  while(gps.available()){
    c = gps.read();
    Serial.print(c);
    data = true;
  }

  if(data){
      lcd.print("GPS");
  }
  gps.end();
  Serial.println();
}


void fingerPrintTest(){
  
  finger.begin(57600);
  if (finger.verifyPassword()) {
    lcd.print("FPS");
  } 
  else {
    lcd.print("No FPS");
  }
  fingerPrint.end();
}

void lcdTest(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LCD");
}

void setup(){
  
  Serial.begin(9600); 

  lcd.init();
  lcd.backlight();

}

void loop(){
  
  fingerPrintTest();
  delay(1000);
  lcd.clear();
  
  gpsTest();
  delay(1000);
  lcd.clear();
    
  wnicTest();
  delay(1000);
  lcd.clear();
    
  lcdTest();
  delay(1000);
  lcd.clear();
}
