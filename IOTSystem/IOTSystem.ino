#include <Adafruit_MLX90614.h>
#include <ESP8266WiFi.h>
#include <Wire.h>

#define WIFI_DELAY 100
#define HTTPS_PORT 443
#define LIMIT 1037
#define LED_PIN D4

#define HOSTNAME "iot-system-0.herokuapp.com"
#define WIFI_PSK "1234567890"
#define WIFI_SSID "SensorNet"

bool sensorDataValidationCheck = false;
int ambientTemperature  = 0;
int objectTemperature = 0;

Adafruit_MLX90614 mlxSensor = Adafruit_MLX90614();
WiFiClientSecure client;
String url;
  
void setup() {
  
  WiFi.begin(WIFI_SSID, WIFI_PSK);
  pinMode(LED_PIN, OUTPUT);
  mlxSensor.begin();
  
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED_PIN, HIGH);
    delay(WIFI_DELAY);
    digitalWrite(LED_PIN, LOW);
    delay(WIFI_DELAY);
  }

  client.setInsecure(); 
  
}

void loop() {

  ambientTemperature = (int) mlxSensor.readAmbientTempC();
  objectTemperature = (int) mlxSensor.readObjectTempC();

  sensorDataValidationCheck = !(ambientTemperature >= LIMIT && objectTemperature >= LIMIT);

  if(sensorDataValidationCheck){
      if (client.connect(HOSTNAME, HTTPS_PORT)) { 
      
          url="/api";
          url += "?ambientTemperature="+String(ambientTemperature);
          url += "&objectTemperature="+String(objectTemperature);
          
          client.print(
                    String("GET ") + url + " HTTP/1.1\r\n" +
                    "Host: " + HOSTNAME + "\r\n" + 
                    "Connection: close\r\n\r\n");  
      }
  }
  delay(10);
  
}
