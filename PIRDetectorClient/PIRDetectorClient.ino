#include "net.h"
#include "screen_driver.h"

const int getSensorOpCode = 0xFFFFFFF1; 
const int sensorStateHigh = 0x31; //49
const int sensorStateLow  = 0x30; //48

int retValue = 0;

void setup() {
   ready_screen();
   print_string("[*] Connecting...");
   wifi_connect();
   print_string("[+] Connected");
   delay(2000);

}

void loop() {
  
  send_data((char*) &getSensorOpCode);
  retValue = recv_data();

  switch(retValue){
    
      case sensorStateHigh:
            print_string("[!] Motion Alert");
            delay(2000);  
            break;
            
      case sensorStateLow:
            print_string("[*] Scanning...");
            delay(100);
            break;

      default:
            print_string("! No Sensor Data");
            delay(100);
            break;
            
  }

}
