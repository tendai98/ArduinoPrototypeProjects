#include <ESP8266WiFi.h>

#define INDICATOR_LED D4
#define CONNECT_DELAY 50

void blink_led() {
  digitalWrite(INDICATOR_LED, HIGH);
  delay(CONNECT_DELAY);
  digitalWrite(INDICATOR_LED, LOW);
  delay(CONNECT_DELAY);
}

void initializeWiFi(){
  
  WiFi.begin(AP_SSID0,AP_PASS0); //Connect to hotspot with give ESSID and password
  WiFi.softAP(AP_SSID1,AP_PASS1); // Create a hotspot with give ESSID and passwd
  pinMode(INDICATOR_LED,OUTPUT); // Set D4 to OUTPUTMODE
  
  while (WiFi.status() != WL_CONNECTED){ //Check if we have connected to Wifi
    blink_led();
  }

  digitalWrite(INDICATOR_LED,HIGH); //Deactivate LED
  Serial.print("[IP Address] -> "); // Print IP Address
  Serial.println(WiFi.localIP());  
}
