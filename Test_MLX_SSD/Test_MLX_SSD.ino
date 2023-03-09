#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_MLX90614.h>
 
 // For the SSD1306 I2C supported Oled Display Module
#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 32    // OLED display height, in pixels
#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
 
 
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
 
double temp_amb;
double temp_obj;
 
void setup()
{
  Serial.begin(9600);
  mlx.begin();         //Initialize MLX90614
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //initialize with the I2C addr 0x3C (128x64)
 
  Serial.println("MLX90614 Infrared Temperature and Oled display with Arduino");
 
  display.clearDisplay();
  display.setCursor(25,5);  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Temp Monitor:");
  display.setCursor(25,35);
  display.setTextSize(1);
  display.print("Initializing");
  display.display();
  delay(5000);
}
 
void loop()
{
 
  temp_amb = mlx.readAmbientTempC();
  temp_obj = mlx.readObjectTempC();
 
 
  display.clearDisplay();
  display.setCursor(25,5);  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Temp:");
  display.setCursor(25,15);
  display.setTextSize(2);
  display.print(temp_obj);
  display.print((char)247);
  display.print("C");
  display.display();
 
  delay(1000);
}
