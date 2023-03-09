#define MENU_OPTION_1 0
#define MENU_OPTION_2 1
#define OPTION_LIMIT 1

int mainMenu(){
  
  setLCDCursor(2,0);
  lcdPrint("[ SYSTEM SETUP ]");  
  setLCDCursor(2,1);
  lcdPrint("[ REPLAY  TEST ]");

  return OPTION_LIMIT;
}
