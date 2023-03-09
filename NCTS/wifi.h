#include <ESP8266WiFi.h>
#define AP_SSID "ConnectHUB"
#define AP_PASS "12345678"
#define INDICATOR_LED D4
#define CONNECT_DELAY 50

void blink_led() {
  digitalWrite(INDICATOR_LED, HIGH);
  delay(CONNECT_DELAY);
  digitalWrite(INDICATOR_LED, LOW);
  delay(CONNECT_DELAY);
}

void initNetwork() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(AP_SSID, AP_PASS);
  pinMode(INDICATOR_LED, OUTPUT);

  while (WiFi.status() != WL_CONNECTED) {
    blink_led();
  }

  digitalWrite(INDICATOR_LED, HIGH);
}
