char c;

void setup(){
  Serial.begin(9600);
}


void loop(){
  while (Serial.available()){
    c = Serial.read();
    Serial.print(c);
  }

  delay(1000);
}
