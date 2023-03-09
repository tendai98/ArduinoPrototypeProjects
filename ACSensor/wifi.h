#include <ESP8266WiFi.h>
#define AP_SSID "INET"
#define AP_PASS "root12345"

void initWiFi(){

  WiFi.begin(AP_SSID,AP_PASS);
  
  while (WiFi.status() != WL_CONNECTED){
    Serial.print("."); 
    delay(500);
  }
  
  Serial.print("[+] Connected -> IPADRESS: ");
  Serial.println(WiFi.localIP());
}
