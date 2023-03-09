#define KEYCOUNT 3  

int readKeypad(){
  for (int index = 0; KEYCOUNT > index; index++){
    if(!digitalRead(keypadPins[index])){
      digitalWrite(keypadPins[index], HIGH);
      return keyMap[index];
    }
  }

  return 0;
}
