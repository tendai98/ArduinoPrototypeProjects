#include <SPI.h>
#include <MFRC522.h>
#include "deviceFunctions.h"


void setup()
{
  
  usbSerial.begin(SERIAL_SPEED);
  SPI.begin();
  MFRC_Device.PCD_Init();
  pinMode(DETECT_RFID,OUTPUT);
  init_device();

}

void loop(){
    deviceModes[deviceMode]();
    ioctl();
}
