#include "dht11.h"
#define NO_VALUES_STR "{t:-1,h:-1}"

void setup() {
  Serial.begin(57600);
  initSensor(1000);
}

void sendParameters(float temp, float humidity ){
  String info = "<"+String(temp)+":"+String(humidity)+">";
  Serial.print(info);
}

void loop() {
  float temperature = readTemperature();
  float humidity = readHumidity();
 
  if (!(isnan(temperature) && isnan(humidity))){
    sendParameters(temperature,humidity);
  }else{
    Serial.print(NO_VALUES_STR);
  }
  
}
