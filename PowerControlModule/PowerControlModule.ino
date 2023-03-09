#include "acs.h"
#include "wifi.h"
#include "firebase.h"
#include "server.h"

unsigned int opcode;

void setup(){
    Serial.begin(115200);
    Serial.println("[+] Starting....");
    initACS();
    initWiFi();
    startServer();
    startFirebaseIO();
    clearCommand();
}

void loop(){

      scanServerData();
      setDoubleData(currentReading());
      opcode = getData();
      systemControl(opcode); 
      delay(100);
}
