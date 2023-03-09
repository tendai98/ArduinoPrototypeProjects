#define RELAY_PIN 13

void initRelay(){
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
}

void relayOn(){
  digitalWrite(RELAY_PIN, HIGH);
}

void relayOff(){
  digitalWrite(RELAY_PIN, LOW);
}
