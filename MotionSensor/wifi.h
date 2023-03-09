#include <ESP8266WiFi.h>
#define AP_SSID "NET"
#define AP_PASS "12345678"
#define IP_ADDR_BANNER "\n[Local IP Address] -> "
#define INDICATOR_LED D0
#define CONNECT_DELAY 50

void blinkLED(){
    digitalWrite(INDICATOR_LED,HIGH);
    delay(CONNECT_DELAY);
    digitalWrite(INDICATOR_LED,LOW);
    delay(CONNECT_DELAY);
}

void initializeWiFi(){
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(AP_SSID,AP_PASS);
  pinMode(INDICATOR_LED,OUTPUT);

  while (WiFi.status() != WL_CONNECTED){
    blinkLED();
  }

  digitalWrite(INDICATOR_LED,LOW);
  Serial.print(IP_ADDR_BANNER);
  Serial.println(WiFi.localIP());
}
