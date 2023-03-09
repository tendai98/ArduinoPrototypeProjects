#include "net.h"
#include "http-client.h"
#include "oled.h"

#define AP_NAME "Moisture-Sensor"
#define AP_PASS "12345678"

char dataBuffer[32];

void setup() {
  initOLED();
  setString("System Loading", 8, 24);
  connectWiFiClient(AP_NAME, AP_PASS);
  delay(2000);
  clearScreenBuffer();
}

void loop() {
  httpGet(WATER_LEVEL_SENSOR_URL, dataBuffer);
  setString(dataBuffer, 2, 24);
  delay(500);
  clearScreenBuffer();
}
