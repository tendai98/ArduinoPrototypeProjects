#define TEST_OPTION_1 0
#define TEST_OPTION_2 1
#define TEST_OPTION_3 2
#define OPTION_MAX 2

int showTestMenu(){
  
  clearScreen();
  setLCDCursor(4,0);
  lcdPrint("  [R1 TEST]");
  setLCDCursor(4,1);
  lcdPrint("  [R2 TEST]");  
  setLCDCursor(4,2);
  lcdPrint("  [R3 TEST]");
  renderControls();

  return OPTION_MAX;
}

void runTestMenu(int selector){
  switch(selector){
        
        case TEST_OPTION_1:
          ringBuzzer();
          clearScreen();
          lcdPrint("[+]  RELAY TEST 1");
          digitalWrite(RELAY1_PIN, HIGH);
          delay(1000);
          digitalWrite(RELAY1_PIN, LOW);
          clearScreen();
          showTestMenu();
          break;
          
        case TEST_OPTION_2:
          ringBuzzer();
          clearScreen();
          lcdPrint("[+]  RELAY TEST 2");
          digitalWrite(RELAY2_PIN, HIGH);
          delay(1000);
          digitalWrite(RELAY2_PIN, LOW);
          clearScreen();
          showTestMenu();
          break; 

        case TEST_OPTION_3:
          ringBuzzer();
          clearScreen();
          lcdPrint("[+]  RELAY TEST 3");
          digitalWrite(RELAY3_PIN, HIGH);
          delay(1000);
          digitalWrite(RELAY3_PIN, LOW);
          clearScreen();
          showTestMenu();
          break;                                       
    }
}
