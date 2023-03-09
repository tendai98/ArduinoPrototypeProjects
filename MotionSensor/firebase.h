#include "FirebaseESP8266.h"
#define FIREBASE_URL "https://iona-engine.firebaseio.com/"
#define DATABASE_SECRET "sNSKLlWvHFn7JtGJtOX09lgjI3eRuzYtBZegmfuV"

FirebaseData firebaseData;

void initializeDatabase(){

  Firebase.begin(FIREBASE_URL, DATABASE_SECRET);
  Firebase.reconnectWiFi(true);

  firebaseData.setBSSLBufferSize(1024, 1024);
  firebaseData.setResponseSize(1024);

  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");

}

bool setValue(String path, int value){

  if(Firebase.setInt(firebaseData ,path,value )){
    return true;
  }else{
    return false;
  }
}
