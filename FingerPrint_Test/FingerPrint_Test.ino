#include <Adafruit_Fingerprint.h>

#define mySerial Serial1

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void blinkLED(int d){
  digitalWrite(D4, LOW);
  delay(d);
  digitalWrite(D4, HIGH);
  delay(d);      
}

void setup()
{
  pinMode(D4, OUTPUT);
  digitalWrite(D4, LOW);
  
  finger.begin(57600);
  blinkLED(1000);
  
  if (finger.verifyPassword()) {
    while (1) { blinkLED(100); }
  } else {
    while (1) { blinkLED(50); }
  }
}

void loop(){
}
