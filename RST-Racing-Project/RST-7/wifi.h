#include <WiFi.h>

void startWiFi(const char * ap_ssid, const char * ap_pass, const char * host_name){
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ap_ssid, ap_pass);
    WiFi.hostname(host_name);
}

/*void connectWiFi(const char * ap_ssid, const char * ap_pass, const char * host_name){
  WiFi.begin(ap_ssid, ap_pass);
  WiFi.hostname(host_name);
  while(WiFi.status() != WL_CONNECTED){
    delay(100);
  }
   
  //Serial.begin(9600);
  //Serial.println(WiFi.localIP());
}*/
