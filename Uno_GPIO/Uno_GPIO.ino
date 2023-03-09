void setup() {
  //pinMode(2, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  Serial.println(analogRead(A0));
  delay(100);
}
