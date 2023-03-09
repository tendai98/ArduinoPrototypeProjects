
#include <WiFi.h>
#include <Arduino.h>
#include <FirebaseESP32.h>
#include <HTTPClient.h>
#include <base64.h>
#include "DHTesp.h"
#include "Ticker.h"


#define IMG_URL "http://192.168.4.2/capture"
#define FIREBASE_URL "https://cloud-resource-0.firebaseio.com/"
#define FIREBASE_SECRET "lgKOLADR17SpdZlZ0jnTpdO0Q8Qv9MbFbn0PwloQ"
#define AP_SSID1 "COMBINED"
#define AP_PASS1 "combined@2018"

#define AP_SSID2 "SN-0"
#define AP_PASS2 "subnet-0"

#define GAS_SENSOR_ANALOG_PIN 36
#define MOISTURE_SENSOR_PIN 39
#define DHT11_SENSOR_PIN 16
#define ADC_MAX 2047

HTTPClient http;
DHTesp dht;
Ticker tempTicker;
TempAndHumidity sensorData;
bool tasksEnabled = false;
bool gotNewTemperature = false;
FirebaseData firebaseData;
FirebaseJson frameJSONObject;
TaskHandle_t tempTaskHandle = NULL;

String payload , ePayload ,epoch;
int gasSensorAnalogValue, gasSensorCalculatedValue , moistureSensorAnalogValue, moistureSensorCalculatedValue;

void tempTask(void *pvParameters) {
  Serial.println("tempTask loop started");
  while (1) // tempTask loop
  {
    if (tasksEnabled && !gotNewTemperature) { // Read temperature only if old data was processed already
      // Reading temperature for humidity takes about 250 milliseconds!
      // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
      sensorData = dht.getTempAndHumidity();  // Read values from sensor 1
      gotNewTemperature = true;
    }
    vTaskSuspend(NULL);
  }
}

void triggerGetTemp() {
  if (tempTaskHandle != NULL) {
     xTaskResumeFromISR(tempTaskHandle);
  }
}

void setup() {

    Serial.begin(115200);
    dht.setup(DHT11_SENSOR_PIN, DHTesp::DHT11);
    WiFi.begin(AP_SSID1, AP_PASS1);
    WiFi.softAP(AP_SSID2,AP_PASS2);

    xTaskCreatePinnedToCore(
        tempTask,                      /* Function to implement the task */
        "tempTask ",                    /* Name of the task */
        4000,                          /* Stack size in words */
        NULL,                          /* Task input parameter */
        5,                              /* Priority of the task */
        &tempTaskHandle,                /* Task handle. */
        1);                            /* Core where the task should run */
    
    if (tempTaskHandle == NULL) {
      Serial.println("[ERROR] Failed to start task for temperature update");
    } else {
      // Start update of environment data every 30 seconds
      tempTicker.attach(30, triggerGetTemp);
    }
    
    while((WiFi.status() == WL_CONNECTED)){
      Serial.println(".");
      delay(100);
    }

    Firebase.begin(FIREBASE_URL,FIREBASE_SECRET);
    Firebase.reconnectWiFi(true);
    Firebase.setReadTimeout(firebaseData,60000);
    Firebase.setwriteSizeLimit(firebaseData,"tiny");
    tasksEnabled = true;
}

void loop() {
  
  http.begin(IMG_URL); //HTTP
  int httpCode = http.GET();
  
  if(httpCode > 0) {
    Serial.printf("[HTTP] GET... code: %d\n", httpCode);
  
    if(httpCode == HTTP_CODE_OK) {
      epoch = String(millis());
      
      payload = http.getString();
      ePayload = base64::encode(payload);
      gasSensorAnalogValue = analogRead(GAS_SENSOR_ANALOG_PIN);
      moistureSensorAnalogValue = analogRead(MOISTURE_SENSOR_PIN);
      gasSensorCalculatedValue = (gasSensorAnalogValue * 100 ) / 3200;
      moistureSensorCalculatedValue = ((200 - moistureSensorAnalogValue) * 100) / 220;
      moistureSensorCalculatedValue = (moistureSensorCalculatedValue * 100) / 11;
      frameJSONObject.add("jpeg",ePayload);
      
      Firebase.setJSON(firebaseData,"/frame",frameJSONObject);
      Firebase.setJSON(firebaseData,"/frames/"+epoch,frameJSONObject);
      Firebase.setInt(firebaseData,"/gasSensorAnalogReading",gasSensorAnalogValue);
      Firebase.setInt(firebaseData,"/gasSensorAnalogReadings/"+epoch,gasSensorAnalogValue);
      Firebase.setInt(firebaseData,"/gasSensorValue",gasSensorCalculatedValue);
      Firebase.setInt(firebaseData,"/gasSensorValues/"+epoch,gasSensorCalculatedValue);
      Firebase.setInt(firebaseData,"/moistureSensorAnalogReading",moistureSensorAnalogValue);
      Firebase.setInt(firebaseData,"/moistureSensorAnalogReadings/"+epoch,moistureSensorAnalogValue);
      Firebase.setInt(firebaseData,"/moistureSensorValue",moistureSensorCalculatedValue);
      Firebase.setInt(firebaseData,"/moistureSensorValues/"+epoch,moistureSensorCalculatedValue);
      
    }
  } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  if (gotNewTemperature) {
    
    int humidity = sensorData.humidity;
    int temperature = sensorData.temperature;
    
    if (humidity <= 100 && temperature <= 100){
      Firebase.setInt(firebaseData,"/humidityValue",((int) humidity));
      Firebase.setInt(firebaseData,"/temperatureValue",((int) temperature));
      Firebase.setInt(firebaseData,"/humidityValues/"+epoch,((int) humidity));
      Firebase.setInt(firebaseData,"/temperatureValues/"+epoch,((int) temperature));
      gotNewTemperature = false;
    }else{
      humidity = 0;
      temperature = 0;
    
      Firebase.setInt(firebaseData,"/humidityValue",((int) humidity));
      Firebase.setInt(firebaseData,"/temperatureValue",((int) temperature));
      Firebase.setInt(firebaseData,"/humidityValues/"+epoch,((int) humidity));
      Firebase.setInt(firebaseData,"/temperatureValues/"+epoch,((int) temperature));
      gotNewTemperature = false;  
    }
  }

  http.end();
  frameJSONObject.clear();
  delay(100);
  
}
