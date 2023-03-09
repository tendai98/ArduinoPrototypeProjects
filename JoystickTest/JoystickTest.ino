oint dX = 0;
int dY = 0;
int dS = 0;

#define X_PIN A6
#define Y_PIN A7
#define S_PIN A5

void setup() {
  Serial.begin(9600);
}

void loop() {

  dX = analogRead(X_PIN);
  dY = analogRead(Y_PIN);
  dS = analogRead(S_PIN);
      
  Serial.print("X: ");
  Serial.println(dX);
  Serial.print("Y: ");
  Serial.println(dY);
  Serial.print("S: ");
  Serial.println(dS);
  Serial.println();
  delay(250);
}
