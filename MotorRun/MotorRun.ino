int pin = 11;

void setup() {
 pinMode(pin, OUTPUT);
}


void drive(int t){
  digitalWrite(pin, HIGH);
  delay(t);
  digitalWrite(pin, LOW);
  delay(t);
}

void loop() {
  drive(1000);
}
