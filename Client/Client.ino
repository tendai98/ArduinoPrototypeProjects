#define INIT_MSG "Wait..."
#define READY_MSG "READY"
#define REBOUND_DELAY 50

#include "oled.h"
#include "wifi.h"
#include "http_client.h"


char miniBuffer[BUFFER_MAX_LEN];

void setup(void) {
  
  initOLED();  
  oledPrint(INIT_MSG, 8, 29); 
  setupWiFiClient();
  oledPrint(READY_MSG, 20, 29);
  delay(2000);
     
}

void loop(void) {

  httpGet(SERVER_URL, miniBuffer);
  oledPrint(miniBuffer, 30, 29); // Render output to OLED
  delay(REBOUND_DELAY);   // Rebound loop delay just to give the server a break
  
}
