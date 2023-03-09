
#include <OneWire.h>
#include <DallasTemperature.h>

const int oneWireBus = D3;     

OneWire oneWire(oneWireBus);
DallasTemperature sensor(&oneWire);

void initTemp() {
  sensor.begin();
}

float getTempValue() {
  sensor.requestTemperatures(); 
  return sensor.getTempCByIndex(0);
}
