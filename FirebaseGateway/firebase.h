#include "FirebaseESP8266.h"

#define FIREBASE_DATABASE_URL "https://gassensor-1234.firebaseio.com/"
#define FIREBASE_DATABASE_SECRET "Eq1iDYS5ijA8Dyo442qC0O8NHjX98VTx9fdxVUnu"

#define VALUE_PATH "reading/"
#define DATA_PATH "GasReadingData/"

#define MAX_BUFFER_SIZE 1024
#define READ_TIMEOUT 500

FirebaseData firebaseData;
boolean firebaseOnline = false;

void initFirebase(){
  
    firebaseData.setBSSLBufferSize(MAX_BUFFER_SIZE, MAX_BUFFER_SIZE);
    firebaseData.setResponseSize(MAX_BUFFER_SIZE);
  
    Firebase.begin(FIREBASE_DATABASE_URL,FIREBASE_DATABASE_SECRET);
    Firebase.reconnectWiFi(true);
    Firebase.setReadTimeout(firebaseData,READ_TIMEOUT);
    Firebase.setwriteSizeLimit(firebaseData , "tiny");
    firebaseOnline = true;
   
}

boolean setIntData(int value){
  
   if(firebaseOnline){
      boolean u1 = Firebase.setInt(firebaseData, VALUE_PATH,value);
      return u1;
   }
   return firebaseOnline;
}

boolean setDataLog(int value){
  if(firebaseOnline){
    boolean u1 = Firebase.setInt(firebaseData, DATA_PATH+String(millis()), value);
    return u1;
  }
  return firebaseOnline;
}
