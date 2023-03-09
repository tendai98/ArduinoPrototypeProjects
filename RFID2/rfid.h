#define SERIAL_SPEED 9600
#define SS_PIN 10
#define RST_PIN 5

#define DETECT_RFID 2
#define DATA_BLOCK1 1
#define DATA_BLOCK2 4
#define BLOCK_MAX 10
#define BUFFER_SIZE 32

byte DATA_LEN = 18;

byte subBuffer[10]={0},dataBuffer[BUFFER_SIZE]={0};
byte syncCode,deviceMode = 0;
boolean readBlock2=false;
uint8_t byteIndex0 = 0,byteIndex1;

void (*deviceModes[2])();

#include "devctl.h"

MFRC522 MFRC_Device(SS_PIN, RST_PIN);
MFRC522::StatusCode status;
MFRC522::MIFARE_Key key;
  
void readData()
{
  
  for (byte i = 0; i < 6; i++){
       key.keyByte[i] = 0xFF;
  }
  
    if ( !( MFRC_Device.PICC_IsNewCardPresent() && MFRC_Device.PICC_ReadCardSerial()))
    {
        syncCode = 0;
    }
    
    else{
      
      status = MFRC_Device.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 4, &key, &(MFRC_Device.uid));
      
      if (status != MFRC522::STATUS_OK) {
          Serial.println(MFRC_Device.GetStatusCodeName(status));
      }
       
      else{
       status = MFRC_Device.MIFARE_Read(DATA_BLOCK2,dataBuffer,&DATA_LEN);
       if (status != MFRC522::STATUS_OK) {
          Serial.println(MFRC_Device.GetStatusCodeName(status));
        }
      
       else{
            Serial.print("[<d]");
            for (byteIndex0 = 0; byteIndex0 < BLOCK_MAX; byteIndex0++)
              {
                if (dataBuffer[byteIndex0] != 32 && dataBuffer[byteIndex0] != 0)
                    Serial.write(dataBuffer[byteIndex0]);
                    readBlock2=true;
              }
          }
      }

      status = MFRC_Device.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 1, &key, &(MFRC_Device.uid)); //line 834
      
      if (status != MFRC522::STATUS_OK && readBlock2) {
          Serial.println(MFRC_Device.GetStatusCodeName(status));
      }
      else{
        
          readBlock2=false;
          
          status = MFRC_Device.MIFARE_Read(DATA_BLOCK1,subBuffer, &DATA_LEN);
          if (status != MFRC522::STATUS_OK) {
              Serial.println(MFRC_Device.GetStatusCodeName(status));
          }

           else{ 
              for (byteIndex1 = 0; byteIndex1 < BLOCK_MAX; byteIndex1++) {
                  dataBuffer[(byteIndex0+byteIndex1)]=subBuffer[byteIndex1];
                  Serial.write(dataBuffer[(byteIndex0+byteIndex1)] );
             }
             
                Serial.println("[d>]");
                Serial.flush();
                ledCtl(150);
                
             }
          } 
      
  
        }
       MFRC_Device.PICC_HaltA();
       MFRC_Device.PCD_StopCrypto1(); 
       byteIndex0 = byteIndex1 = 0;
       delay(100);

}

void writeData(){

  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;

  if ( !( MFRC_Device.PICC_IsNewCardPresent() && MFRC_Device.PICC_ReadCardSerial()))
  {
     return;
  }

  byte buffer[34]={0x0};
  byte block;
  byte len;

  Serial.setTimeout(3600000L);     
  Serial.println("[<i]WRITE MODE READY[i>]");
  len = Serial.readBytesUntil('|', (char *) buffer, 10) ; 
  
  block = 1;
 
  status = MFRC_Device.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(MFRC_Device.uid));
  if (status != MFRC522::STATUS_OK) {
    Serial.print("[<el]PCD::AUTH -> FAILED");
    Serial.print(MFRC_Device.GetStatusCodeName(status));
    Serial.println("[el>]");
    return;
  }
  else{
    Serial.println("[<el]PCD::AUTH -> SUCCESS");
  }

  status = MFRC_Device.MIFARE_Write(block, buffer, 16);
  if (status != MFRC522::STATUS_OK) {
    Serial.print("[<el]DATA::WRITE -> FAILED");
    Serial.print(MFRC_Device.GetStatusCodeName(status));
    Serial.println("[el>]");
    return;
  }
  else {
      Serial.println("[<el]DATA::WRITE -> SUCCESS[el>]");
      ledCtl(200);
  }
 
  MFRC_Device.PICC_HaltA();
  MFRC_Device.PCD_StopCrypto1();
  Serial.flush();
}

void init_device(){

      deviceModes[0]=readData;
      deviceModes[1]=writeData;
     
      while (true){
          
          byte selector = Serial.read();
          
          ledCtl(500);
          if (selector < 2){
            deviceMode = selector;
            break;
          }
      }

}
