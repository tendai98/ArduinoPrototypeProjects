#define AP_NAME "Bridge-T"
#define AP_PASS "command_access"

unsigned int UART_SPEED = 19200;
bool isEnabled = false;
unsigned short localPort =  2020;
unsigned short  Index = 0;
unsigned short  Index2 = 0;
unsigned short  PacketLen = 0;
char PACKET_BUF[UDP_TX_PACKET_MAX_SIZE];
char UPLOAD_BUFFER[]="";
String PARAM;
