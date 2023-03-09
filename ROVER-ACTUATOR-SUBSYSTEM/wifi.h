#include <ESP8266WiFi.h>

#define AP_NAME "ROV3R"
#define AP_PASS "rover_connect"
#define HOSTNAME "ROV3R"
#define BLINK_LED D4

void blinkLED(short blinkDelay){
  digitalWrite(BLINK_LED, LOW);
  delay(blinkDelay);
  digitalWrite(BLINK_LED, HIGH);
  delay(blinkDelay);
}

void checkConnection(){
  while(WiFi.status() != WL_CONNECTED){
    blinkLED(250);
  }
  digitalWrite(BLINK_LED, HIGH);
}

void initWiFiConnection(){
  pinMode(BLINK_LED, OUTPUT);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(AP_NAME, AP_PASS);
  WiFi.hostname(HOSTNAME);
  checkConnection();
}
