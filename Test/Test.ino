  #define AP "Control-Relay-Unit:0"
#define PSK "12345678"

#include <ESP8266WiFi.h>

void wifiOnline(char * ssid, char * password){
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password); 
}

void setup() {
  Serial.begin(9600);
  pinMode(0, OUTPUT);
  wifiOnline(AP, PSK);
}

void loop() {
 //Serial.printf("Time: %ld",millis());
 //Serial.println("Serial Message");
 digitalWrite(0, HIGH);
 delay(50);
 digitalWrite(0, LOW);
 delay(50);
}
