void setup() {
  pinMode(D7, OUTPUT);
  pinMode(D5, OUTPUT);
}

void loop() {
  digitalWrite(D7, HIGH);
  digitalWrite(D5, HIGH);
  delay(1000);
  digitalWrite(D7, LOW);
  digitalWrite(D5, LOW);
  delay(1000);
}
