#include <U8g2lib.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHT_PIN 13
#define SDA_PIN 14
#define SCL_PIN 15


DHT_Unified dht(DHT_PIN, DHT11);
sensors_event_t data;
U8G2_SSD1306_128X32_UNIVISION_F_SW_I2C u8g2(U8G2_R0, SCL_PIN, SDA_PIN, U8X8_PIN_NONE);   // Adafruit Feather ESP8266/32u4 Boards + FeatherWing OLED

int GLOBAL_TEMP = 0.0;
int GLOBAL_HMD = 0.0;
char * buff1, buff2;
String msg1, msg2;

int getHumidity(){
  dht.humidity().getEvent(&data);
  return data.relative_humidity;
}

int getTemperature(){
  dht.temperature().getEvent(&data);
  return data.temperature;
}

void setup(void) {
  dht.begin();
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_tenthinguys_tf);
  
}

void loop(void) {
  
  GLOBAL_HMD = getHumidity();
  GLOBAL_TEMP = getTemperature();
  msg1 = "--> tC: "+String(GLOBAL_TEMP);
  msg2 = "--> h%: "+String(GLOBAL_HMD);

  u8g2.drawStr(30, 12, msg1.c_str());	
  u8g2.drawStr(30, 28, msg2.c_str());  
  u8g2.sendBuffer();
  delay(1000);  
}
