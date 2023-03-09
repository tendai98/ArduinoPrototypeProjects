#include "constants.h"
#include "lcd.h"
#include "net.h"
#include "sys.h"

void setup(){
  initLCD();
  lcdPrint(ONLINE_MSG);
  initNet();
  initServo();
}

void loop(){
  
    gateOpen();
    delay(1000);
    gateClose();
    delay(1000);
    
}
