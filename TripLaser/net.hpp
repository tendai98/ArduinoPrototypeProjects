#include <ESP8266WiFi.h>
#define AP_SSID "Inno"
#define AP_PASS "qwertyui"
#define INDICATOR_LED D4
#define CONNECT_DELAY 50

void blink_led() {
  digitalWrite(INDICATOR_LED, HIGH);
  delay(CONNECT_DELAY);
  digitalWrite(INDICATOR_LED, LOW);
  delay(CONNECT_DELAY);
}

void init_net() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(AP_SSID, AP_PASS);
  pinMode(INDICATOR_LED, OUTPUT);

  while (WiFi.status() != WL_CONNECTED) {
    blink_led();
  }

  digitalWrite(INDICATOR_LED, HIGH);
}
