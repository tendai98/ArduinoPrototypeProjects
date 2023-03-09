#include "wifi.h"
#include "client.h"
#include "oled-driver.h"

const char * ssid = "DHT11-0000";
const char * pass = "12345678";
char data1[16];
char data2[16];

void setup() {
  initOLED();
  setString("Connecting...", 8, 16);
  connectWiFiClient(ssid, pass);
  delay(2000);
}

void loop() {
  getTemperature(TMP_URL, data1);
  getHumidity(HMD_URL, data2);
  setString(data1, 8, 8);
  setString(data2, 8, 28);  
  delay(500);
  clearScreenBuffer();
}
