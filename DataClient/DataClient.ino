#include "wifi.h"
#include "client.h"
#include "oled-driver.h"

const char * ssid = "Server-R181455H";
const char * pass = "Tinaye2011";
char value[16];

void setup() {
  initOLED();
  connectWiFiClient(ssid, pass);
  printString("Connected");
  delay(2000);
}

void loop() {
  httpGet(SENSOR_URL, value);
  printString(value);
  delay(100);
}
