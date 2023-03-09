#include <ESP8266WiFi.h>

#define ESSID   "Harare_Council"
#define PSK "12345678"
#define RETRY_DELAY 100

void initNet(){
    
  WiFi.mode(WIFI_STA);
  WiFi.begin(ESSID, PSK);
  pinMode(D4, OUTPUT);
  
  while (WiFi.status() != WL_CONNECTED){
    digitalWrite(D4, HIGH);
    delay(250);
    digitalWrite(D4, LOW);
    delay(250);
        
  }

  digitalWrite(D4, HIGH);

}
