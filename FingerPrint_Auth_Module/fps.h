#include <Adafruit_Fingerprint.h>
#include "SoftwareSerial.h"

#define FPS_SCAN_MODE 'A'
#define FPS_PROG_MODE 'B'
#define FPS_FLSH_MODE 'X'
#define FPS_CHCK_MODE 'V'

#define FPS_CAPTURE_CODE 'C'
#define FPS_PLACE_FINGER 'D'
#define FPS_GOT_BIOMETRIC 'E'
#define FPS_OPERATION_FAIL 'F'
#define FPS_REMOVE_FINGER 'G'
#define FPS_PLACE_AGAIN 'H'
#define FPS_SCAN_COMPLETE 'I'
#define GPS_GOT_PRINT 'J'
#define FPS_PRINT_MATCH 'K'
#define FPS_NO_MATCH 'L'
#define FPS_ENROLLED 'M'
#define FPS_DEVICE_READY 'N'
#define FPS_DEVICE_NULL  'O'
#define FPS_FAILED_STORE 'P'
#define FPS_SCANNING_PRG 'Q'
#define FPS_ACCESS_GRANT 'R'
#define FPS_ACCESS_DENID 'S'
#define FPS_OPERXN_DONE  'Z'
#define FPS_OPERXN_FAIL  'Y'

//SoftwareSerial fps(2,3);
SoftwareSerial fps(D3,D2);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&fps);

int getRandomID(){
  return random(1,127);
}

int runProc(){
  int code = -1;
  
  while(code != FINGERPRINT_OK){
      code = finger.getImage();
      if(code == FINGERPRINT_OK){
        Serial.println(FPS_CAPTURE_CODE);
        break;
      }else{
        Serial.println(FPS_PLACE_FINGER);
      }
      delay(100);
  }

  code = finger.image2Tz(1);

  if(code == FINGERPRINT_OK){
      Serial.println(FPS_GOT_BIOMETRIC);
      delay(100);
  }else{
      Serial.println(FPS_OPERATION_FAIL);
      return -1;
  }

  Serial.println(FPS_REMOVE_FINGER);
  delay(1000);
  
  Serial.println(FPS_PLACE_AGAIN);
  code = 0;
  while (code != FINGERPRINT_NOFINGER){
      code = finger.getImage();
  }

  code = -1;
  while(1){
     if(code != FINGERPRINT_OK){
       code  = finger.getImage(); 
     }else{
        Serial.println(FPS_SCAN_COMPLETE);
        break;
     }
  }

  code = finger.image2Tz(2);

  if(code == FINGERPRINT_OK){
    Serial.println(GPS_GOT_PRINT);
  }else{
    Serial.println(FPS_OPERATION_FAIL);
    return -1;
  }

  delay(1000);
  code = finger.createModel();
  
  if(code == FINGERPRINT_OK){
    Serial.println(FPS_PRINT_MATCH);
  }else{
    Serial.println(FPS_NO_MATCH);
    return -1;
  }

  delay(1000);
  int id = getRandomID();
  code = finger.storeModel(id);
  if(code == FINGERPRINT_OK){
    Serial.println(FPS_ENROLLED);
    delay(1000);
    Serial.println(id);
    return 0;
  }else{
    Serial.println(FPS_FAILED_STORE);
    return -1;
  }
}

void enrollFingerprints(){
  randomSeed(analogRead(A0));
  finger.begin(57600);
  delay(1000);
  if(finger.verifyPassword()){
    
    int code = -1;
    while(code == -1){
      code = runProc();
    }
    
  }else{
    Serial.println(FPS_DEVICE_NULL);
  }
  fps.end();
}

int scanFingerprint(){
  randomSeed(analogRead(A0));
  finger.begin(57600);
  delay(1000);
  
  int code = -1;
  
  while(code != FINGERPRINT_OK){

    code = finger.getImage(); 
    Serial.println(FPS_SCANNING_PRG);
    delay(250);
     code = finger.image2Tz();
     
     if(code == FINGERPRINT_OK){
       code = finger.fingerSearch();
       
       if(code == FINGERPRINT_OK){
          Serial.println(FPS_ACCESS_GRANT);
          delay(1000);
          fps.end();
          return finger.fingerID;
       }else{
          Serial.println(FPS_ACCESS_DENID);
          delay(1000);
       }
     }else{
       delay(100);
     }
  }

  fps.end();
  return -1;
}

int checkFingerprint(){
  finger.begin(57600);
  delay(1000);
  
  int code = -1;
  int count = 0;
  
  while(10 >= count){

    code = finger.getImage(); 
    delay(250);
     code = finger.image2Tz();
     
     if(code == FINGERPRINT_OK){
       code = finger.fingerSearch();
       
       if(code == FINGERPRINT_OK){
          delay(1000);
          fps.end();
          Serial.println(finger.fingerID);
          break;
       }else{
          count++;
          delay(100);
       }
     }else{
       delay(100);
     }
  }

  fps.end();
  Serial.println(-1);
}

void flushPrints(){
  finger.begin(57600);
  delay(1000);
  int p;
  
  for (int id = 1; 128 > id; id++){
      p = finger.deleteModel(id);
      if (p == FINGERPRINT_OK) {
          Serial.println(FPS_OPERXN_DONE);
      }else{
          Serial.println(FPS_OPERXN_FAIL);
      }
  }
  fps.end();
}
