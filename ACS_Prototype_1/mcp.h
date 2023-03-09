#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define ONEWIRE_SENSOR 5
#define SENSOR_TYPE DHT11

DHT_Unified dht(ONEWIRE_SENSOR, SENSOR_TYPE);
sensor_t sensor;
sensors_event_t event;

int currentTemp = 0,  currentHumidity = 0, currentInterval = 0, t = 0, h = 0;
int tempSetting = 0, humiditySetting = 0 , activationTimeSetting = 0;
int programDelay = 0;
bool relay1State = false, relay2State = false, relay3State = false;
bool tempValidation = false, humidityValidation = false;

String data;

void initMCP(){

	dht.begin();
	dht.temperature().getSensor(&sensor);
	dht.humidity().getSensor(&sensor);
  programDelay = sensor.min_delay / 1000;
}

void renderCurrentData(){
  if(relay1State){
        data = String(" Temp [C]: ")+String(currentTemp)+String(" | ")+String(tempSetting);
  }else{
        data = String("-Temp [C]: ")+String(currentTemp)+String(" | ")+String(tempSetting);
  }
  lcdPrintAt(data, 1, 0);
    
  if(relay2State){
        data = String(" Hdty [%]: ")+String(currentHumidity)+String(" | ")+String(humiditySetting);
  }else{
        data = String("-Hdty [%]: ")+String(currentHumidity)+String(" | ")+String(humiditySetting);
  }  
  lcdPrintAt(data, 1, 1);

  if(relay3State){
    data = String("-Timr [M]: ON| ")+String(activationTimeSetting);
  }else{
    data = String(" Timr [M]:OFF| ")+String(activationTimeSetting);
  }
  lcdPrintAt(data, 1, 2);
}


void actuatorControlSub(){
  
  if(relay1State){
     digitalWrite(RELAY1_PIN, LOW);
  }else{
     digitalWrite(RELAY1_PIN, HIGH); 
  }
  
  if(relay2State){
         digitalWrite(RELAY2_PIN, LOW);
  }else{
         digitalWrite(RELAY2_PIN, HIGH);
  }

  if(relay3State){
         digitalWrite(RELAY3_PIN, HIGH);
  }else{
         digitalWrite(RELAY3_PIN, LOW);
  }

}

void loadPresets(){
  EEPROM.get(TEMPERATURE_PRESET_ADDRESS, tempSetting);
  EEPROM.get(HUMIDITY_PRESET_ADDRESS, humiditySetting);
  EEPROM.get(TIMER_CTRL_PRESET_ADDRESS, activationTimeSetting);
}

void mainControlSub(){

	dht.temperature().getEvent(&event);
  t = event.temperature;

  dht.humidity().getEvent(&event);
  h = event.relative_humidity;

  tempValidation = (currentTemp >= TEMP_LOW_LIMIT && TEMP_HIGH_LIMIT >= currentTemp);
  humidityValidation = (currentHumidity >= HUMIDITY_LOW_LIMIT && HUMIDITY_HIGH_LIMIT >= currentHumidity);

  currentInterval = 0; //(currentInterval >= activationTimeSetting*1000) ? 0 : millis();
  relay3State = (currentInterval >= activationTimeSetting*1000);
        
	if(!(isnan(t) || isnan(h))){

    currentTemp = t;
    currentHumidity = h;

    if( tempValidation && humidityValidation){
      relay1State = (currentTemp >= tempSetting);
      relay2State = (currentHumidity >= humiditySetting);
    }
      renderCurrentData();
	}

  actuatorControlSub();
  delay(programDelay);
  
}
