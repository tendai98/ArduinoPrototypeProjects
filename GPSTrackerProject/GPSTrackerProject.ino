#include "const.h"
#include "wifi.h"
#include "gps.h"
#include "client.h"

String data;

void setup(){
  startSerial(DEFAULT_BITRATE);
  startWiFi(NET_SSID, NET_PASS);
}

void loop(){
  data = String("/api?longitude=")+String(getLongitude());
  data += String("&latitude=")+String(getLatitude());
  data += String("&id=")+String(TRACKER_NODE_ID);
  
  char buff[data.length()];
  data.toCharArray(buff, data.length());
  httpGet(HOST, buff);
  delay(50);
}
