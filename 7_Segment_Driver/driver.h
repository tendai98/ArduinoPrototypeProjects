// 7 Segment Connection Map
/* 7 Segment Connection Map
 *      __   ____   __
 *     |  | |_9__| |  |
 *     |5_|  ____  |8_| 
 *      __  |_3__|  __
 *     |  |  ____  |  |
 *     |7_| |_10_| |4_|
 */

#define LOOP_MODE 108
#define PRINT_MODE 112
#define PIN_COUNT 7
#define CHARACTER_ENCODINGS 33
#define ACTIVE_CHARACTER_ENCODINGS CHARACTER_ENCODINGS

const uint8_t pins[PIN_COUNT] = {3, 4, 5, 7, 8, 9, 10};

const uint8_t states[CHARACTER_ENCODINGS][PIN_COUNT] = {
  
   {0, 4, 5, 7, 8, 9, 10},    // 0
   {0, 4, 0, 0, 8, 0, 0},     // 1
   {3, 0, 0, 7, 8, 9, 10},    // 2
   {3, 4, 0, 0, 8, 9, 10},    // 3
   {3, 4, 5, 0, 8, 0, 0},     // 4
   {3, 4, 5, 0, 0, 9, 10},    // 5
   {3, 4, 5, 7, 0, 9, 10},    // 6
   {0, 4, 0, 0, 8, 9, 0},     // 7
   {3, 4, 5, 7, 8, 9, 10},    // 8
   {3, 4, 5, 0, 8, 9, 0},    // 9
   
   {3, 4, 5, 7, 8, 9, 0},    // A
   {3, 4, 5, 7, 0, 0, 10},  // b
   {0, 0, 5, 7, 0, 9, 10},  // C
   {3, 0, 0, 7, 0, 0, 10},  // c
   {3, 4, 0, 7, 8, 0, 10},  // d
   {3, 0, 5, 7, 0, 9, 10},  // E
   {3, 0, 5, 7, 0, 9, 0},   // F
   {3, 4, 5, 0, 8, 9, 10},   // g
   {3, 4, 5, 7, 8, 0, 0},  // H
   {3, 4, 5, 7, 0, 0, 0},  // h
   {0, 4, 0, 0, 0, 0, 0}, // i
   
   {0, 4, 0, 0, 8, 0, 10}, // j
   {0, 0, 5, 7, 0, 0, 10},  // L
   {0, 0, 5, 7, 0, 0, 0},  // l 
   {3, 4, 0, 7, 0, 0, 0},  // n
   {3, 4, 0, 7, 0, 0, 10}, // o
   {3, 0, 5, 7, 8, 9, 0}, // P
   {3, 0, 0, 7, 0, 0, 0}, // r
   {3, 4, 5, 0, 0, 9, 10}, // s
   
   {3, 0, 5, 7, 0, 0, 10}, // t
   {0, 4, 5, 7, 8, 0, 10}, // U
   {0, 4, 0, 7, 0, 0, 10}, // u
   {3, 4, 5, 0, 8, 0, 10} // y
};

const char chars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'C', 'c', 'd', 'e', 'f', 'g', 'H', 'h', 'i', 'j', 'L', 'l', 'n', 'o', 'p', 'r', 's', 't', 'U', 'u', 'y'};

void init7SegmentDriver(){
  for(int index=0; PIN_COUNT>index; index++){
    pinMode(pins[index], OUTPUT);
    digitalWrite(pins[index], LOW);
  }
}


uint8_t setSystemMode(){
  char mode = 0;
  while(!mode){
    mode = Serial.available() ? Serial.read() : 0;
  }
  switch(mode){
    case LOOP_MODE:
      Serial.println("\nLoop Mode: Active");
      break;

    case PRINT_MODE:
      Serial.println("\nPrint Mode : Active");
      break;
  }

  return mode; 
}

void clearDisplay(){
  for(int index=0; PIN_COUNT>index; index++){
    digitalWrite(pins[index], LOW);
  }  
}

void loopMode(){
  for(int index=0; ACTIVE_CHARACTER_ENCODINGS>index; index++){
    for(int x=0; PIN_COUNT>x; x++){
      if(states[index][x] > 0){
        digitalWrite(states[index][x], HIGH);
      }
    }
    delay(1000);
    clearDisplay();
  }
}

int printChar(char code){
  clearDisplay();     
  Serial.print("\nInput a character: > ");
  for(int index=0; ACTIVE_CHARACTER_ENCODINGS>index; index++){
    if(chars[index] == code){
      for(int y=0; PIN_COUNT>y; y++){
        if(states[index][y]){
          digitalWrite(states[index][y], HIGH);
        }
      }
    }
  }

  return 0;
}
