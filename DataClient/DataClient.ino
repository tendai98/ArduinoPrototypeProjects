#include "wifi.h"
#include "oled.h"
#include "http.h"
//#include "udp.h"

#define SERVER_URL "http://192.168.4.1/value"
char dataBuffer[16];
int value = 0;

void setup(){
  //initOLED();
  //startWiFi();
  Serial.begin(9600);
}

void loop() {
  /*httpGet(SERVER_URL, dataBuffer);
  printString(dataBuffer);
  clearScreenBuffer();
  Serial.println(dataBuffer);
  delay(100);*/
  Serial.println(analogRead(A0));
}
