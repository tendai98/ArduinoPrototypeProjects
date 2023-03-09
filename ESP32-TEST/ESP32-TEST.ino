void setup() {
  Serial.begin(115200);
}

void loop() {
 Serial.printf("[Time: %d]\n", millis());
 delay(1000);
}
