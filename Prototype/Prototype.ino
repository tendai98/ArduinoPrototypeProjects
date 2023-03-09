#define LASER_GPIO 15

void setup() {
  pinMode(LASER_GPIO, OUTPUT);
  digitalWrite(LASER_GPIO, LOW);
}

void loop() {
  digitalWrite(LASER_GPIO, HIGH);
}
