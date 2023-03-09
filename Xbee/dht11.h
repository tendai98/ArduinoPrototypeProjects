#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define SENSOR_PIN 4
#define SENSOR_TYPE DHT11
DHT_Unified dht(SENSOR_PIN,SENSOR_TYPE);

short delayTime = 0;

void initSensor(short time){
	dht.begin();
	delayTime = time;
}

float readTemperature(){
  delay(delayTime);
	sensors_event_t event;
	dht.temperature().getEvent(&event);
	return (!isnan(event.temperature)) * event.temperature;
}

float readHumidity(){
  delay(delayTime);
	sensors_event_t event;
	dht.humidity().getEvent(&event);
	return (!isnan(event.relative_humidity)) * event.relative_humidity;
}
