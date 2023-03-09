#include <SPI.h>
char buff[50]={0};
byte index;
boolean process;

void setup() {
    Serial.begin(9600);
    pinMode(MISO,OUTPUT);
    SPCR |= _BV(SPE);
    index = 0;
    process = false;
    SPI.attachInterrupt();
}

ISR (SPI_STC_vect){
  byte c = SPDR;
  if (index < sizeof(buff)){
    buff[index++] = c;
    if(c == '\r'){
      process = true;
    }
  }
}

void loop() {
  if(process){
    process = false;
    Serial.println(buff);
    index = 0;
  }
}
