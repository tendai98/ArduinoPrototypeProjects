#define ESP_SSID              "Replace with your Server SSID"
#define ESP_PASS              "Replace with your Server Password"
#define BLINK_LED             D4
#define SCAN_DELAY            100

#include <ESP8266WiFi.h>

// Setup WIFI function

void setupWiFiClient(){
  
  WiFi.begin(ESP_SSID, ESP_PASS); // Run WIFI in client mode
  pinMode(BLINK_LED, OUTPUT);     // Control built-in LED using D4
  
  while (WiFi.status() != WL_CONNECTED){  // Blink LED while waiting to connect
    digitalWrite(BLINK_LED, HIGH);
    delay(SCAN_DELAY);
    digitalWrite(BLINK_LED, LOW);
    delay(SCAN_DELAY);
  }

  digitalWrite(BLINK_LED, HIGH);
  
}
