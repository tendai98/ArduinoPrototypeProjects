
#include "db.hpp"
#include "sensor.hpp"
#include "net.hpp"
#define DATABASE_VALUE_PATH "/LaserSensor"

void setup() {
  init_net();
  init_rdb();
  init_laser();
}

void loop() {
  int state = getSensorValue();
  set(DATABASE_VALUE_PATH,state);
  delay(10);
}
