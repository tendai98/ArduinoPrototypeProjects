#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg1;
struct can_frame canMsg2;

MCP2515 mcp2515(D8);


void setup() {
  canMsg1.can_id  = 0x0F6;
  canMsg1.can_dlc = 8;
  canMsg1.data[0] = 0xCA;
  canMsg1.data[1] = 0xFE;
  canMsg1.data[2] = 0xBA;
  canMsg1.data[3] = 0xBE;
  canMsg1.data[4] = 0x00;
  canMsg1.data[5] = 0xBE;
  canMsg1.data[6] = 0xBE;
  canMsg1.data[7] = 0x00;

  canMsg2.can_id  = 0x036;
  canMsg2.can_dlc = 8;
  canMsg2.data[0] = 0xDE;
  canMsg2.data[1] = 0xAD;
  canMsg2.data[2] = 0xBE;
  canMsg2.data[3] = 0xEF;
  canMsg2.data[4] = 0x00;
  canMsg2.data[5] = 0xBE;
  canMsg2.data[6] = 0xBE;
  canMsg2.data[7] = 0x00;
  
  Serial.begin(115200);
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS);
  mcp2515.setNormalMode();
  
  Serial.println("Example: Write to CAN");
}

void loop() {
  mcp2515.sendMessage(&canMsg1);
  mcp2515.sendMessage(&canMsg2);

  Serial.println("Messages sent");
  
  delay(100);
}
