#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define SENSOR_PIN 3
#define SENSOR_TYPE DHT11

DHT_Unified dht(SENSOR_PIN, SENSOR_TYPE);
sensor_t sensor;
sensors_event_t event;

void initDHT(){
 dht.begin();
 dht.temperature().getSensor(&sensor);
}

int getTemperature(){
  dht.temperature().getEvent(&event);
  return event.temperature - 1;
}
