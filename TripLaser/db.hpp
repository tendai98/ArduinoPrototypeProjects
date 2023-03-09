#include "FirebaseESP8266.h"
#define DB_URL "https://database-00.firebaseio.com/"
#define SECRET "OP9495B0TW4feUenCJ5aOnlbkCnXs6lQxsiZmzEO"

FirebaseData firebaseData;

void init_rdb(){

  Firebase.begin(DB_URL, SECRET);
  Firebase.reconnectWiFi(true);

  firebaseData.setBSSLBufferSize(1024, 1024);
  firebaseData.setResponseSize(1024);

  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");

}

bool set(String path, int value){

  if(Firebase.setInt(firebaseData ,path,value )){
    return true;
  }else{
    return false;
  }
}
