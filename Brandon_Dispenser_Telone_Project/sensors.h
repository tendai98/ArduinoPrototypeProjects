#include <Wire.h>
#include <Adafruit_MLX90614.h>

#define BUZZER D0
#define IR D6

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void initMLX() {
  mlx.begin();
  pinMode(IR, INPUT);
}


int getTemp() {
  return mlx.readObjectTempC();
}

int getProx(){
  return !digitalRead(IR);
}

void buzz(int tone){
  analogWrite(BUZZER, tone);
  delay(200);
  analogWrite(BUZZER, 0);
  delay(200);
}
