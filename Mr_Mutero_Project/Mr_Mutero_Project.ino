#include <ESP8266WiFi.h>
#include "http.h"
#include "oled-driver.h"

#define AP "Fish-Tank-Sensor"
#define PS "1234567890"

char buff[120];
String data = "";

void zero(char * b, int s){
  for(int i=0; s>i; i++){
    buff[i]=0;
  }
}

void startWiFi(){
  WiFi.mode(WIFI_AP);
  WiFi.softAP(AP, PS);
}

void setup() {
  initOLED();
  startSonar();
  startWiFi();
  setupServer();
}

void loop() {
  delay(100);
  data = String("Level: ")+String(getDistance())+String(" cm");
  data.toCharArray(buff, 120);
  setString(buff, 4, 8);
  delay(1);
  zero(buff, 120);
  delay(1);
  data = String("Temp: ")+String(getTempValue())+String(" *C");
  data.toCharArray(buff, 120);
  setString(buff, 4, 24);
  delay(5);
  zero(buff, 120);
  delay(1);
  serverHandler();
  delay(100);
  clearScreenBuffer();
}
