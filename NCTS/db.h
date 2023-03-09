#include "FirebaseESP8266.h"
#define DB_URL "https://ncts-0000.firebaseio.com/"
#define SECRET "7UuJ8u7ix9CLVHKgVbODfxI6LklruHf2no0jdGvt"

FirebaseData firebaseData;

void initDatabase(){

  Firebase.begin(DB_URL, SECRET);
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

int extractData(FirebaseData &firebaseDataPtr){
  return firebaseDataPtr.intData();
}

int getValue(String path){  
  Firebase.getInt(firebaseData, path);
  return extractData(firebaseData);
}
