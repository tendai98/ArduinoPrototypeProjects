#include "ESP8266WiFi.h"

#define AP "test"
#define PSK  "1234567890"

void setup(){
    WiFi.begin(AP, PSK);
    pinMode(D4, OUTPUT);
    
    while(WiFi.status() != WL_CONNECTED){
        delay(100);
        digitalWrite(D4, LOW);
        delay(100);
        digitalWrite(D4, HIGH);  
    }

}


void loop(){

}
