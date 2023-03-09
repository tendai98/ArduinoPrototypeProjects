#define LED_GROUP_0 0x100
#define LED_GROUP_1 0x200
#define LED_GROUP_2 0x300

#define GROUP_0_PIN D0
#define GROUP_1_PIN D2
#define GROUP_2_PIN D4

#define PIR_SENSOR_PIN D7
#define LUX_CONTROL 4
#define DHT_SENSOR_PIN D5

#include "DHT.h"

DHT dht(DHT_SENSOR_PIN,  DHT11);

void controlGroup(int group){
  
  int level = 0;
  
  switch(group){

      case LED_GROUP_0:
         path = String(LAMP_ID GROUP_0);
         level = get(path);
         analogWrite(GROUP_0_PIN, level);
         break;

      case LED_GROUP_1:
         path = String(LAMP_ID GROUP_1);
         level = get(path);
         analogWrite(GROUP_1_PIN, level);
         break;

      case LED_GROUP_2:
         path = String(LAMP_ID GROUP_2);
         level = get(path);
         analogWrite(GROUP_2_PIN, level);
         break;     
    
  }
  
}

void activateLampDeviceNode(){
  path = String(LAMP_ID GROUP_0);
  set(path, MAX_INTENSITY);

  path = String(LAMP_ID GROUP_1);
  set(path, MAX_INTENSITY);

  path = String(LAMP_ID GROUP_2);
  set(path, MAX_INTENSITY);
  
  path = String(LAMP_ID COMMAND);
  set(path, NO_OPERATION);
  
  path = String(LAMP_ID MODE);
  set(path, LOCK_MODE);
  
  path = String(LAMP_ID NODE_STATUS);
  set(path, 1);
  
  path = String(LAMP_ID COMMAND);  
  set(path, NO_OPERATION);
}

void activateLampDevice(){
  controlGroup(LED_GROUP_0);
  controlGroup(LED_GROUP_1);
  controlGroup(LED_GROUP_2);  
}

void checkNodeStatus(){
  
  path = String(LAMP_ID NODE_STATUS);
  int value = get(path);
  if(!value){
    activateLampDeviceNode();
  }
  activateLampDevice();
}

void lampOn(){
  controlGroup(LED_GROUP_0);
  controlGroup(LED_GROUP_1);
  controlGroup(LED_GROUP_2);
}

void lampOff(){
   analogWrite(GROUP_0_PIN, 0);
   analogWrite(GROUP_1_PIN, 0);
   analogWrite(GROUP_2_PIN, 0);
}

void lampDim(){
   path = String(LAMP_ID GROUP_0);
   int group_level0, group_level1, group_level2;
   group_level0 = get(path) / LUX_CONTROL;

   path = String(LAMP_ID GROUP_1);
   group_level1 = get(path) / LUX_CONTROL;

   path = String(LAMP_ID GROUP_0);
   group_level2 = get(path) / LUX_CONTROL;
   
   analogWrite(GROUP_0_PIN, group_level0);
   analogWrite(GROUP_1_PIN, group_level1);
   analogWrite(GROUP_2_PIN, group_level2);
}


int getPIRTrigger(int pirSensor){
    return digitalRead(pirSensor);
}

void uploadDHT11Data(){
  
  int humidity, temp;
  
  path = String(LAMP_ID TEMP);
  temp = dht.readTemperature(); 
  set(path, temp);

  path = String(LAMP_ID HUMIDITY);
  humidity = dht.readHumidity(); 
  set(path, humidity);
  
}

void fullLampOn(){
   analogWrite(GROUP_0_PIN, MAX_INTENSITY);
   analogWrite(GROUP_1_PIN, MAX_INTENSITY);
   analogWrite(GROUP_2_PIN, MAX_INTENSITY);  
}
