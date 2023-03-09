#define serial Serial

void setup() {
  serial.begin(9600);
}

void loop() {
  char c;
  while(serial.available()){
     c = Serial.read();
     Serial.print(c);
  }
}
