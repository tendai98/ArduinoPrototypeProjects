#include <Servo.h>

Servo turner;

void setup() {
  turner.attach(12);
}

void loop() {
  turner.write(90);
  delay(2000);
  
  turner.write(0);
  delay(2000);
}
