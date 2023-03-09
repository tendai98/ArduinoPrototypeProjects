rvoid setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.print("CPU Time: ");
    Serial.println(millis());
    delay(100);
}
