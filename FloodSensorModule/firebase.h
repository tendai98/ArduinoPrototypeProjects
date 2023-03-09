#include "FirebaseESP8266.h"

FirebaseData firebaseData;

void initializeFirebase(){
  
  Firebase.begin(FIREBASE_URL, DATABASE_SECRET);
  Firebase.reconnectWiFi(true);
  
  firebaseData.setBSSLBufferSize(1024, 1024);
  firebaseData.setResponseSize(1024);

  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
  
}

bool setFloatValue(float value){

  if(Firebase.setFloat(firebaseData ,path,value )){
    return true;
  }else{
    return false;
  }
 
}

bool setIntValue(int value){

  if(Firebase.setInt(firebaseData ,path,value )){
    return true;
  }else{
    return false;
  }
 
}
