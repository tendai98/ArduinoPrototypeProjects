#include <WiFi.h>

#define AP_SSID "TrackZER"
#define AP_PASS "tracker@2021"

void startWiFi(){
  WiFi.begin(AP_SSID, AP_PASS);
}

bool checkConnection(){
    return (WiFi.status() == WL_CONNECTED);
}
