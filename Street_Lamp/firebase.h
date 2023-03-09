#include "FirebaseESP8266.h"

FirebaseData firebaseData;
String path;

int extractIntData(FirebaseData &firebaseDataPtr);

void initializeFirebase(){
  
  Firebase.begin(FIREBASE_URL, DATABASE_SECRET);
  Firebase.reconnectWiFi(true);
  
  firebaseData.setBSSLBufferSize(1024, 1024);
  firebaseData.setResponseSize(1024);

  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
  
}

bool set(String &path, int value){

  if(Firebase.setInt(firebaseData ,path,value )){
    return true;
  }else{
    return false;
  }
 
}

int get(String &path){
   Firebase.getInt(firebaseData, path);
   return extractIntData(firebaseData);
}

int extractIntData(FirebaseData &firebaseDataPtr){
  return firebaseDataPtr.intData();
}
