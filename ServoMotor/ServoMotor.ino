#include <Servo.h>

Servo turner;

void setup() {
  turner.attach(D3);
}

void loop() {
  turner.write(180);
  delay(2000);
  
  turner.write(68);
  delay(2000);
}
