#define SYSTEM_AP_SSID "ACS"
#define SYSTEM_AP_PASS "acrimacsACS#001"
#define CLIENT_AP_SSID "ACS"
#define CLIENT_AP_PASS "acs_control19#45664"
#define DEVICE_NAME "ACS-0"
#define WIFI_LED D4
#define MANAGED_MODE 0x10
#define MASTER_MODE 0x11
#define LED_BLINK 0x22
#define LED_OFF 0x23

#include <ESP8266WiFi.h>
byte led_state = LOW;
byte current_wlan_mode = 0;

void toggle_led(byte led_mode){
  switch(led_mode){
    
    case LED_BLINK:
          if(led_state == LOW){
             digitalWrite(WIFI_LED,led_state);
             led_state = HIGH;
          }else{
             digitalWrite(WIFI_LED,led_state);
             led_state = LOW;    
          } 
          break;
          
     case LED_OFF:
          digitalWrite(WIFI_LED,LOW);
  }
}

void connect_delay_loop(){
  while(WiFi.status() != WL_CONNECTED){
      toggle_led(LED_BLINK);
      toggle_leds(ER_LED,HIGH);
      delay(100);
      toggle_leds(ER_LED,LOW);
      delay(100);
  }
  toggle_led(LED_OFF);
  Serial.println(WiFi.localIP());
}

void init_wlan_mode(byte wlan_mode){
    
    pinMode(WIFI_LED,OUTPUT);
    current_wlan_mode = wlan_mode;
    wifi_station_set_hostname(DEVICE_NAME);
    
    switch(wlan_mode){
        case MANAGED_MODE:
            WiFi.begin(CLIENT_AP_SSID,CLIENT_AP_PASS);
            connect_delay_loop();
            break;

        case MASTER_MODE:
            WiFi.softAP(SYSTEM_AP_SSID,SYSTEM_AP_PASS);
            break;
    }
    
}
