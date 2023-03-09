#define OK_STATE_LED D0
#define ER_STATE_LED D1
#define ER_LED 1
#define OK_LED 2

void init_leds(){
  pinMode(OK_STATE_LED,OUTPUT);
  pinMode(ER_STATE_LED,OUTPUT);
  digitalWrite(OK_STATE_LED,HIGH);
  digitalWrite(ER_STATE_LED,HIGH);
  delay(2000);
  digitalWrite(OK_STATE_LED,LOW);
  digitalWrite(ER_STATE_LED,LOW);
}

void toggle_leds(byte ledType,byte state){
  
  switch(ledType){
      case ER_LED:
        digitalWrite(ER_STATE_LED,state);
        break;

      case OK_LED:
        digitalWrite(OK_STATE_LED,state);
        break;
  }
  
}
