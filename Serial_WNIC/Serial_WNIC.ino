#include "constants.h"
#include "net.h"
#include "sys.h"
#include "lcd.h"

void setup() {
  Serial.begin(9600);
  initLCD();
  initServo();
  initNet();
  initServer();
  lcdPrint(ONLINE_MSG);
}

byte readData(){
   byte index = 0;
   
    while (Serial.available()){
       Buffer[index] = (char) Serial.read();
       index++;
    }
    return index;
}

void loop() {
  char * bufferPtr;
  int * opcode;
  
  if(netRecv()){
       opcode = (int*) Buffer;
      
      switch(*opcode){
        
         case CMD_SERIAL_RD:
            Serial.print(READ_MODE); 
            break;

         case CMD_LCD_WRITE:
            bufferPtr = Buffer + 4;
            lcdPrint(bufferPtr);
            break;

         case CMD_LCD_CLEAR:
            lcdClear();
            break;

         case CMD_SERVO_OPN:
            gateOpen();
            break;

         case CMD_SERVO_CLS:
            gateClose();
            break;

         case CMD_SYS_RESET:
            ESP.reset();
            break;
      }

      Serial.println(*opcode, HEX);
      
  }

  if(readData()){
    netSend();
  }

  flushBuffer();
  delay(50);
}
