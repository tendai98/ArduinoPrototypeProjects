#define ANALOG_SENSOR_PIN     A0
#define PIN_GPIO 7 // Trigger Pin of Ultrasonic Sensor
#define ECHO_GPIO 6; // Echo Pin of Ultrasonic Sensor

int getAnalogValue(){
  return analogRead(ANALOG_SENSOR_PIN);  // Ready analog pin
}


void initSonar(){
   pinMode(PIN_GPIO, OUTPUT);
   pinMode(ECHO_GPIO, INPUT);
}

int runSonar() {
   digitalWrite(PIN_GPIO, LOW);
   delayMicroseconds(2);
   digitalWrite(PIN_GPIO, HIGH);
   delayMicroseconds(10);
   digitalWrite(PIN_GPIO, LOW);
   long duration = pulseIn(ECHO_GPIO, HIGH);
   delay(100);
   return microsecondsToCentimeters(duration);
}

int microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
