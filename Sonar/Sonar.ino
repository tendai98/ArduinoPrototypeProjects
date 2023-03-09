const int pingPin = 23; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 22; // Echo Pin of Ultrasonic Sensor

void setup() {
   pinMode(pingPin, OUTPUT);
   pinMode(echoPin, INPUT);
   Serial.begin(9600);
}

long centimeters(long microseconds) {
   return microseconds / 29 / 2;
}

long distance() {
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(2);
   digitalWrite(pingPin, LOW);
   long duration = pulseIn(echoPin, HIGH);
   return centimeters(duration);
}

void loop(){
  Serial.println(distance());
  delay(10);
}
