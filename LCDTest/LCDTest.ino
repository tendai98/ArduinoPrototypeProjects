int pin[] = {2,4,7,12,13};
int pwm[]= {3,5,6};

void setup() {
  for(int i=0; sizeof(pin)/sizeof(int) > i; i++){
    pinMode(pin[i], OUTPUT);
    digitalWrite(pin[i], HIGH);
  }

  for(int i=0; sizeof(pwm)/sizeof(int) > i; i++){
    analogWrite(pwm[i], 500);
  }

}

void loop() {

}
