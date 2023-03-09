#include "SoftwareSerial.h"

SoftwareSerial lora(D3,D2);

void setup() {
    lora.begin(9600);
    lora.println("-------------LORA NETLINK TEST------------");
    delay(5000);
}

void loop() {
  lora.printf("Time: %d\n", millis());
  delay(1000);
}
