#include "FirebaseESP8266.h"

#define DB_URL        "https://myproject-5e970-default-rtdb.firebaseio.com"
#define SECRET     "hP4UNGnzat1kpeSilI7syb3sTj4OPyQEVD1adE4Y"

FirebaseData fb;

void initFirebase(){
  
  Firebase.begin(DB_URL, SECRET);
  Firebase.reconnectWiFi(true);
  
  fb.setBSSLBufferSize(1024, 1024);
  fb.setResponseSize(1024);

  Firebase.setReadTimeout(fb, 1000 * 60);
  Firebase.setwriteSizeLimit(fb, "tiny");
  
}

bool setValue(String &path, int value){

  if(Firebase.setInt(fb ,path, value)){
    return true;
  }else{
    return false;
  }
 
}
