#define SENSOR_ANALOG_PIN A0
#define MAX_ADC 1024.0

float getRawSensorReading(){
  return analogRead(SENSOR_ANALOG_PIN);
}
