#define OUTPUT_PIN 23

void setup() {
  Serial.begin(115200);
  Serial.println("Starting...");
  pinMode(OUTPUT_PIN,OUTPUT);
  digitalWrite(OUTPUT_PIN,HIGH);
}

void loop() {
  if(Serial.available()){
    char c = Serial.read();
    
    switch(c){
      case 'h':
        digitalWrite(OUTPUT_PIN,HIGH);
        Serial.println("[+] LED OFF");
        break;
      case 'l':
        digitalWrite(OUTPUT_PIN,LOW);
        Serial.println("[+] LED ON");
          break;    
    }
  }
  
  delay(1000);
}
