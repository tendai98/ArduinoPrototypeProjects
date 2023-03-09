#include "wifi.h"
#include "firebase.h"

// Masvingo

#define DEVICE_TAG         "PARKING-BAY:0"
#define VAL        "/sensorValue"

String path;
int val;

void setup() {
  
  Serial.begin(9600);
  initNet();
  initFirebase();
  path = String(DEVICE_TAG VAL);
  setValue(path, 0);
  
}

void loop() {

    path = String(DEVICE_TAG VAL);
    val = analogRead(A0);
    if(1022 > val){
      
    }else{
      
    }
    setValue(path, val);    
    delay(100);
}
