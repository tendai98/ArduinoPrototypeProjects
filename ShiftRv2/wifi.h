#include <ESP8266WiFi.h>

void init_wifi(){
  WiFi.softAP(AP_NAME,AP_PASS);
}
