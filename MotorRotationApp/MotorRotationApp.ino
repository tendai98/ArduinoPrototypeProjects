#include <ESP8266WiFi.h>
#include <EEPROM.h>
#include <ESP8266WebServer.h>

#define CONTROLLER_ID           "MTD:0000000000000000"
#define CONTROLLER_KEY          "2b3c3afaea63d2f7f26a"
#define MIME_TYPE               "text/plain"
#define SERVER_PORT             9600
#define FORWARD_ROTATION        2
#define REVERSE_ROTATION        3 
#define GPIO_1                  0
#define GPIO_2                  2
#define ROTATION_PRESET_ADDRESS 0

ESP8266WebServer server(SERVER_PORT);

short state = 0, lastState = 0, counter = 0, limit = 5000, lastValue = 0;
bool manualOverride = false, configMode = false;
String data;

void directControl(){
  if(manualOverride){
    manualOverride = false;
    server.send(200, MIME_TYPE, "Auto-Mode");
  }else{
    manualOverride = true;
    server.send(200, MIME_TYPE, "Manual-Mode"); 
  }
}

void engageForward(){
   if(manualOverride){
     digitalWrite(GPIO_1, LOW);
     digitalWrite(GPIO_2, LOW);
     server.send(200, MIME_TYPE, "Forward-Mode");
   }else{
     server.send(200, MIME_TYPE, "Enable Manual-Mode");
   }
}

void engageReverse(){
  if(manualOverride){
      digitalWrite(GPIO_1, HIGH);
      digitalWrite(GPIO_2, HIGH);
      server.send(200, MIME_TYPE, "Reverse-Mode");
  }else{
     server.send(200, MIME_TYPE, "Enable Manual-Mode");
  }
}

void setRotation(){
  configMode = true;
  limit = server.arg(0).toInt();
  server.send(200, MIME_TYPE, String(limit));
}

void runControl(){
    configMode = manualOverride = false;
    server.send(200, MIME_TYPE, "Online");
}

void savePreset(){
  if(limit != lastValue){
    EEPROM.put(ROTATION_PRESET_ADDRESS, limit);
    EEPROM.commit();
    lastValue = limit;
    configMode = manualOverride = false;
    server.send(200, MIME_TYPE, "Set"); 
  }else{
    server.send(200, MIME_TYPE, "Value is set");     
  }
}

void currentStatus(){
   server.send(200, MIME_TYPE, String(state));
}

void currentLimit(){
  server.send(200, MIME_TYPE, String(limit));
}

void currentMode(){
  server.send(200, MIME_TYPE, String(manualOverride));
}

void error(){
    server.send(404, MIME_TYPE, "Not Found");
}

int getState(int state){
  switch(state){
      case REVERSE_ROTATION:
        counter--;
        return state;

      case FORWARD_ROTATION:
        counter++;
        return state;
   }
}

void computeState(){
  delay(limit);
  if(!manualOverride){
    state = ((counter >= 0) && !(counter > limit)) ? getState(REVERSE_ROTATION) : getState(FORWARD_ROTATION); 
  }
}

void controlRelay(){
   switch(state){
      case FORWARD_ROTATION:
         digitalWrite(GPIO_1, LOW);
         digitalWrite(GPIO_2, LOW);
         break;

      case REVERSE_ROTATION:
         digitalWrite(GPIO_1, HIGH);
         digitalWrite(GPIO_2, HIGH);
         break;
   }
}

void systemReset(){
  ESP.reset();
}

void load_preset(){
  EEPROM.get(ROTATION_PRESET_ADDRESS, limit);
}

void setup(){

  EEPROM.begin(256);
  load_preset();
  
  WiFi.mode(WIFI_AP);
  WiFi.softAP(CONTROLLER_ID, CONTROLLER_KEY);

  server.on("/control", directControl);
  server.on("/config", setRotation);
  server.on("/status", currentStatus);
  server.on("/forward", engageForward);
  server.on("/reverse", engageReverse);
  server.on("/mode", currentMode);
  server.on("/limit", currentLimit);
  server.on("/save", savePreset);
  server.on("/run", runControl);
  server.on("/reset", systemReset);
  server.onNotFound(error);
  server.begin();
  
  pinMode(GPIO_1, OUTPUT);
  pinMode(GPIO_2, OUTPUT);
}

void loop(){
    server.handleClient();
    if(!(configMode || manualOverride)){
      computeState();
      controlRelay();
    }else{
      delay(10);
    }
}
