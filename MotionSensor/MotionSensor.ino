
#include "firebase.h"
#include "motion.h"
#include "wifi.h"
#define PATH "/MotionSensor-0/sensorState"

void setup() {
  initializeWiFi();
  initializeDatabase();
  initMotionSensor();
}

void loop() {
  int state = runMotionSensor();
  setValue(PATH,state);
  delay(10);
}
