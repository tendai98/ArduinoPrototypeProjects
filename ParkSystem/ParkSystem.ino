#include "db.h"
#include "driver.h"
#include "wifi.h"

void setup() {
  initNetwork();
  initDatabase();
  initSystem();
  setValue("opcode",0);
}

void loop() {
  setValue("sensors",getSensors());
  int code = getValue("opcode");
  executeRequest(code);
  delay(1000);
}
