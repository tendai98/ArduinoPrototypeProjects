#include <Wire.h>
#include <U8g2lib.h>
#include <Adafruit_MLX90614.h>

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);
int ambientTemperature = 0;
int objectTemperature = 0;

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

String d = "";
char  b[4];
      
void setup(){
  
  pinMode(D0, OUTPUT);
  pinMode(D3, INPUT);

  digitalWrite(D0, LOW);

  
  mlx.begin();
  delay(5000);
  
  u8g2.begin();
  u8g2.setFont(u8g2_font_profont29_mr);
  u8g2.clearBuffer();
 

  Serial.begin(115200);
}

void loop(){
  
   if(digitalRead(D3)){
    
      int a = (int) mlx.readAmbientTempC(); //analogRead(A0);
      d = String(a);
      d.toCharArray(b, 4);
      u8g2.drawStr(24, 24, b);

      ambientTemperature = (int) mlx.readAmbientTempC();
      objectTemperature = (int) mlx.readObjectTempC();

      Serial.println(ambientTemperature);
      Serial.println(objectTemperature);
      
      digitalWrite(D0, LOW);

   }else{
      u8g2.drawStr(16, 24, "ACTIVE");
      digitalWrite(D0, HIGH);    
   }

  

   u8g2.sendBuffer();
   delay(100);
   u8g2.clearBuffer();
}
