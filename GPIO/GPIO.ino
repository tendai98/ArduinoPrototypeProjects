#define ENABLE_RB0 0B00000001     //
#define ENABLE_RB1 0B00000010
#define ENABLE_RB2 0B00000000

void setup() {
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);

  /*digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);
  digitalWrite(D5, LOW);*/      // RB0 Control Mode

  /*digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH);
  digitalWrite(D5, LOW);*/        // RB1 Control Mode

  digitalWrite(D3,HIGH);
  digitalWrite(D4,HIGH);
  digitalWrite(D5,HIGH);      // RB2 Control Mode
  
}

void loop() {
}
