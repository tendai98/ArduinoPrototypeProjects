#define INPUT_PIN A0
#define ADC_MAX_RESOLUTION 1024.0

float readRawValue(){
  return (float) analogRead(INPUT_PIN);
}

float readValue(){
  
  float analogSensorReading = analogRead(INPUT_PIN);
  float reading = ((ADC_MAX_RESOLUTION - analogSensorReading) / ADC_MAX_RESOLUTION) * 100.0;
  return reading;
   
}
