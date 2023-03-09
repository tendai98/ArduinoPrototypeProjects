#define IR_SENSOR_GPIO D0

void initSensor(){
  pinMode(IR_SENSOR_GPIO, INPUT); 
}

int readSensorState(){
  return !digitalRead(IR_SENSOR_GPIO);
}
