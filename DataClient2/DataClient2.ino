#include "wifi.h"
#include "client.h"
#include "oled-driver.h"

#define ssid "WLS-0"
#define pass "1234567890"

char  ptr[32];

void getSensorData(char * ptr){
  Serial.println(ptr);
}

void setup() {
  initOLED();
  printString("Connecting...");
  connectWiFiClient(ssid, pass);
  printString("Connected");
  delay(2000);
  Serial.println(9600);
}

void loop() {
  httpGet(WATER_LEVEL_SENSOR_URL, ptr);
  printString(ptr);
  delay(50);
}
