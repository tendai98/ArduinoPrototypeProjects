#include "FirebaseESP8266.h"
#define FIREBASE_URL "https://flood-sensors.firebaseio.com/"
#define DATABASE_SECRET "WAuoI0NfTFjyxyCEqdXEpesSCMSHntDihmpiHOym"

FirebaseData firebaseData;

void initializeFirebase(){
  
  Firebase.begin(FIREBASE_URL, DATABASE_SECRET); //Configure Firebase instance
  Firebase.reconnectWiFi(true);
  
  firebaseData.setBSSLBufferSize(1024, 1024); // Allocate Memory for SSL Buffer
  firebaseData.setResponseSize(1024); // Allocate Response Buffer Size 

  Firebase.setReadTimeout(firebaseData, 1000 * 60); //Set readtimeout
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
