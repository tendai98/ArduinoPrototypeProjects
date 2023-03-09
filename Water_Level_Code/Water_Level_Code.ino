#define DEVICE_BAUDRATE 9600  // Set speed for our serial to 9600 bits/sec
#define SENSOR_GPIO_PIN A0    // Set analog pin to A0
#define MAX_ADC_SAMPLE 1024   // Set the maximum sample count (ESP8266 is 1024)
 
int sensorValue = 0;  // Variable to store raw analog reading
int actualReading = 0; // Varible to store calculated value

void setup() {
  Serial.begin(DEVICE_BAUDRATE); // Initialize Serial interface
}

void loop() {
  sensorValue = analogRead(SENSOR_GPIO_PIN); // Get and store current serial reading
  actualReading = ((1024 - sensorValue) * MAX_ADC_SAMPLE) / 100;
  Serial.println(actualReading);  // Send value to serial interface
  delay(100); // Sleep for 100 milliseconds (Just for human sanity)
}
