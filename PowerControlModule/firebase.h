#include "FirebaseESP8266.h"

#define FIREBASE_DATABASE_URL "https://powercontrolsystem-1234.firebaseio.com/"
#define FIREBASE_DATABASE_SECRET "v91ExPTV0Qmd1z5t4GV2VOi6PvwR13cJay1qMnSG"

#define CURRENT_VALUE "currentVoltage/"
#define DATA_PATH "analogSensorVoltageData/"
#define CMD_CODES "command/"

#define MAX_BUFFER_SIZE 1024
#define READ_TIMEOUT 60000

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
      boolean u1 = Firebase.setDouble(firebaseData, DATA_PATH+String(millis()),value);
      boolean u2 = Firebase.setDouble(firebaseData, CURRENT_VALUE, value);
      return u1 && u2;
   }
  
  return firebaseOnline;
  
}
