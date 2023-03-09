void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void loop() {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(1000);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(1000);
}
