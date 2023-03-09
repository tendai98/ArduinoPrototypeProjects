#include "wifi.h"
#include "client.h"
#include "oled-driver.h"

const char * ssid = "Server-0000";
const char * pass = "iot_dev_";
char  data[16];

void setup() {
  initOLED();
  printString("[---]");
  connectWiFiClient(ssid, pass);
  delay(2000);
}

void loop() {
  httpGet(WATER_LEVEL_SENSOR_URL, data);
  printString(data);
  clearScreenBuffer();  
  delay(50);
}
