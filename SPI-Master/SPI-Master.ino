#include <SPI.h>
#define CHIP_SELECT 2

char data[]="Message From SPI Master\r";
char c;

void setup() {
     pinMode(CHIP_SELECT,OUTPUT);
     digitalWrite(CHIP_SELECT,HIGH);
     SPI.begin();
     SPI.setClockDivider(SPI_CLOCK_DIV8);
     Serial.begin(9600);
}

void loop() { 
     digitalWrite(CHIP_SELECT,LOW);
     
     for (int i = 0;i < 1024;){
        if( (char) data[i] != '\x00'){
            c = data[i];
            SPI.transfer(c); 
            i++;
        }else{
          break;
        }
     }

     digitalWrite(CHIP_SELECT,HIGH);
     delay(2000);
}
