#include "firebase.h"
#include "wifi.h"
#define BUFFER_MAX 10
  
String numberString;
char data_buffer[BUFFER_MAX];O
int value;
  
void setup(){
    Serial.begin(9600);
    Serial.println("[+] Starting....");
    initWiFi();
    initFirebase();
}

int serialReceiveInt(){

  int index = 0; 
  
  while (Serial.available()){
    data_buffer[index] = Serial.read();
    index++;
  }

  numberString = String(numberString+data_buffer);
  return numberString.toInt();
  
}

void clearBuffer(){
  for(int i=0;i<BUFFER_MAX;i++){
    data_buffer[i]=0;
  }
  numberString="";
}

void loop(){
  
    value = serialReceiveInt();
    
    if(value){
      Serial.println(value);
      setIntData(value);
      setDataLog(value);
    }

    clearBuffer();
    delay(100);
    
}
