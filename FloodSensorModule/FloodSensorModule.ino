#include "constants.h"
#include "sensor.h"
#include "net.h"
#include "firebase.h"

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  initializeWiFi();
  initializeFirebase();
}

void loop() {
  
  sensorValue = readValue();
  rawValue = readRawValue();
  timestamp = millis();
  
  path = DATA_PATH + String(timestamp);
  setFloatValue(sensorValue);
  
  path = CURRENT_VALUE_PATH;
  setFloatValue(sensorValue);
  
  path = RAW_DATA_PATH + String(timestamp);
  setFloatValue(rawValue);
  
  path = CURRENT_RAW_VALUE;
  setFloatValue(rawValue);
  
  path = SENSOR_ID_PATH;
  setIntValue(SENSOR_ID);
  
  delay(1000);
  
}
