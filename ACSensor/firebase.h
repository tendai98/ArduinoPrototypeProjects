#include "FirebaseESP8266.h"

#define FIREBASE_DATABASE_URL "https://ac-sensor-default-rtdb.firebaseio.com/"
#define FIREBASE_DATABASE_SECRET "5IDf7QMqhWS69ksqh13AXSxp4WnfxdxtUJ36ir8X"

#define CURRENT_VALUE "current/"
#define DATA_PATH "elecricCurrentData/"
#define DEVICE_MODE "mode/"
#define CMD_CODES "command/"

#define MAX_BUFFER_SIZE 1024
#define READ_TIMEOUT 500

FirebaseData firebaseData;
boolean firebaseOnline = false;

void startFirebaseIO(){
  
    firebaseData.setBSSLBufferSize(MAX_BUFFER_SIZE, MAX_BUFFER_SIZE);
    firebaseData.setResponseSize(MAX_BUFFER_SIZE);
  
    Firebase.begin(FIREBASE_DATABASE_URL,FIREBASE_DATABASE_SECRET);
    Firebase.reconnectWiFi(true);
    Firebase.setReadTimeout(firebaseData,READ_TIMEOUT);
    Firebase.setwriteSizeLimit(firebaseData , "tiny");
    firebaseOnline = true;
   
}

unsigned int extractIntData(FirebaseData &firebaseDataPtr){
  return firebaseDataPtr.intData();
}

unsigned int getData(){
  
  if(firebaseOnline){
      Firebase.getInt(firebaseData, CMD_CODES);
      return extractIntData(firebaseData);
  }
}

boolean clearCommand(){
  
   if(firebaseOnline){
      boolean u1 = Firebase.setInt(firebaseData, CMD_CODES,RELAY_OFF_OPCODE);
      return u1;
   }
  
  return firebaseOnline;
  
}

boolean setDoubleData(double value){
  
   if(firebaseOnline){
      boolean u1 = Firebase.setDouble(firebaseData, DATA_PATH+String(timestamp),value);
      boolean u2 = Firebase.setDouble(firebaseData, CURRENT_VALUE, value);
      return u1 && u2;
   }
   return firebaseOnline;
}

boolean setIntData(double value){
  
   if(firebaseOnline){
      boolean u1 = Firebase.setInt(firebaseData, DEVICE_MODE,value);
      return u1;
   }
   return firebaseOnline;
}
