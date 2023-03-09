#define AP_NAME "IDAR"
#define AP_PASS "12345678"

#include <ESP8266WiFi.h>

void startWifi(){
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(AP_NAME, AP_PASS); 

  while(WiFi.status() != WL_CONNECTED){
    digitalWrite(D4, HIGH);
    delay(200);
    digitalWrite(D4, LOW);
    delay(200);
  }

  digitalWrite(D4, HIGH);
}
