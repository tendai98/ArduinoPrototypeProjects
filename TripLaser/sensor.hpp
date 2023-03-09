#define SENSOR A0
#define LASER_GPIO D2
#define TRIPPED_LASER 0x0
#define NOT_TRIPPED_LASER 0xf

void init_laser(){
  pinMode(LASER_GPIO,OUTPUT);
  digitalWrite(LASER_GPIO,HIGH);
}

int getSensorValue(){
   int sensorValue = analogRead(SENSOR);
   return sensorValue;
}
