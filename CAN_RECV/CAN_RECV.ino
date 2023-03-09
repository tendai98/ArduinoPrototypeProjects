#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg;
MCP2515 mcp2515(D8);


void setup() {
  Serial.begin(115200);
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS);
  mcp2515.setLoopbackMode();
  
  Serial.println("------- CAN Read ----------");
  Serial.println("ID  DLC   DATA");

  canMsg.can_id  = 0x0F6;
  canMsg.can_dlc = 8;
  canMsg.data[0] = 0x8E;
  canMsg.data[1] = 0x87;
  canMsg.data[2] = 0x32;
  canMsg.data[3] = 0xFA;
  canMsg.data[4] = 0x26;
  canMsg.data[5] = 0x8E;
  canMsg.data[6] = 0xBE;
  canMsg.data[7] = 0x86;
}

void loop() {
  mcp2515.sendMessage(&canMsg);
  delay(2000);
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {
    Serial.print(canMsg.can_id, HEX); // print ID
    Serial.print(" "); 
    Serial.print(canMsg.can_dlc, HEX); // print DLC
    Serial.print(" ");
    
    for (int i = 0; i<canMsg.can_dlc; i++)  {  // print the data
      Serial.print(canMsg.data[i],HEX);
      Serial.print(" ");
    }

    Serial.println();      
  }
}
