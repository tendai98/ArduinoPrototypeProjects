#include <WiFi.h>
#define D4 2

void startWiFi(char * ssid, char * password){
  WiFi.mode(WIFI_STA);
  pinMode(D4, OUTPUT);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    digitalWrite(D4, LOW);
    delay(100);
    digitalWrite(D4, HIGH);
    delay(100);
  }

  pinMode(D4, HIGH);
}
