#define R_GPIO 2
#define A_GPIO 14
#define G_GPIO 15

void setup(){
  pinMode(R_GPIO, OUTPUT);
  pinMode(A_GPIO, OUTPUT);
  pinMode(G_GPIO, OUTPUT);

    digitalWrite(R_GPIO, LOW);
    digitalWrite(A_GPIO, LOW);
    digitalWrite(G_GPIO, LOW);
}

void loop(){
    digitalWrite(R_GPIO, HIGH);
    digitalWrite(A_GPIO, LOW);
    digitalWrite(G_GPIO, LOW);
    delay(100);
    digitalWrite(R_GPIO, LOW);
    digitalWrite(A_GPIO, HIGH);
    digitalWrite(G_GPIO, LOW);
    delay(100);
    digitalWrite(R_GPIO, LOW);
    digitalWrite(A_GPIO, LOW);
    digitalWrite(G_GPIO, HIGH);

    delay(100);
}
 
