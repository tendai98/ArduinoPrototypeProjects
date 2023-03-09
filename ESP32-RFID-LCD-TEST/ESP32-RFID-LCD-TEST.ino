#include <SPI.h>
#include <Servo.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

int lcdColumns = 16;
int lcdRows = 2;
static const int servoPin = 15;

#define SS_PIN  5  // ESP32 pin GIOP5 
#define RST_PIN 27 // ESP32 pin GIOP27 

Servo servo1;
MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void initServo(){
    servo1.attach(servoPin);
}

void initLCD(){
  lcd.init();           
  lcd.backlight();
  lcd.print("Place Card");
}

void initRFID(){
  SPI.begin();
  rfid.PCD_Init();
}


void testServo(int angle){
    servo1.write(angle);
}

void testRFID(){
 if (rfid.PICC_IsNewCardPresent()) { // new tag is available
    if (rfid.PICC_ReadCardSerial()) { // NUID has been readed
      MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
      Serial.print("RFID/NFC Tag Type: ");
      Serial.println(rfid.PICC_GetTypeName(piccType));

      // print UID in Serial Monitor in the hex format
      Serial.print("UID:");
      for (int i = 0; i < rfid.uid.size; i++) {
        Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(rfid.uid.uidByte[i], HEX);
      }
      Serial.println();

      rfid.PICC_HaltA(); // halt PICC
      rfid.PCD_StopCrypto1(); // stop encryption on PCD
      lcd.setCursor(0, 0);
      lcd.print("  Access Granted");
      testServo(90);
      delay(2000);
    }
  }else{
    delay(1000);
    lcd.setCursor(0, 0);
    lcd.print("Place AccessCard");
    testServo(0);
  }
  
}


void setup(){
  initLCD();
  initRFID();
  initServo();
  Serial.begin(9600);   
}

void loop(){
  testRFID();
}
