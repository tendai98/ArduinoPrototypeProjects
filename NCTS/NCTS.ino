#include "wifi.h"
#include "db.h"
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#define AMBIENT_TEMP "ambientTemp"
#define OBJECT_TEMP "objectTemp"
#define OUTPUTS "output"

#define LED D5
#define BUZZER D6

int ambientTemperature = 0;
int objectTemperature = 0;

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void controlOutputs(){
  if(getValue(OUTPUTS)){
   digitalWrite(LED,HIGH);
   digitalWrite(BUZZER,LOW);
 }else{
   digitalWrite(LED,LOW); 
   digitalWrite(BUZZER,HIGH); 
 }
}

void setup() {
  mlx.begin();
  pinMode(LED,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  digitalWrite(BUZZER,HIGH );
  initNetwork();
  initDatabase();
  setValue(OUTPUTS,0);
}


void loop() {
 
 ambientTemperature = (int) mlx.readAmbientTempC();
 objectTemperature = (int) mlx.readObjectTempC();
 setValue(AMBIENT_TEMP,ambientTemperature);
 setValue(OBJECT_TEMP,objectTemperature);
 controlOutputs();
 delay(1000);
}
