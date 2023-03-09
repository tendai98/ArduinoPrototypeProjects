#include <DHT.h>
#include <DHT_U.h>
#define DHT_PIN D3

DHT_Unified dht(DHT_PIN, DHT11);
sensors_event_t data;

int GLOBAL_TEMP = 0.0;
int GLOBAL_HMD = 0.0;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

int getHumidity(){
  dht.humidity().getEvent(&data);
  Serial.print("Humidity: ");
  Serial.print(data.relative_humidity);
  Serial.print(" % ");
  return data.relative_humidity;
}

int getTemperature(){
  dht.temperature().getEvent(&data);
  Serial.print("Temperature: ");
  Serial.print(data.temperature);
  Serial.println(" *C");
  return data.temperature;
}

void loop() {
  GLOBAL_HMD = getHumidity();
  GLOBAL_TEMP = getTemperature();
  if(GLOBAL_TEMP > 38){
    Serial.println("HEATER OFF");
  }
  delay(1);
}
