#define SERIAL_BAUDRATE 9600

#define AP_SSID "Fifi's Network"
#define AP_PASS "!123#$F1fi&"

#define FIREBASE_URL "https://system-0000-default-rtdb.firebaseio.com/"
#define DATABASE_SECRET "vio8zEQIojN8W5z2q2wW1hgcpyHysjsWFv0k69ky"

#define LAMP_ID "LAMP-ID:0000000000000000"
#define NODE_STATUS "/nodeStatus"
#define GROUP_0 "/groupIntensity:0"
#define GROUP_1 "/groupIntensity:1"
#define GROUP_2 "/groupIntensity:2"
#define LED_GROUP_0_DATA "/ledGroup0AnalogData/"
#define LED_GROUP_0_ANALOG_VALUE "/groupAnalogValue:0"
#define TARGET_GROUP "/targetGroup"
#define HUMIDITY "/humidity"
#define TEMP "/temp"
#define COMMAND "/command"
#define MODE "/mode"

#define CONNECT_DELAY 500
#define MAX_INTENSITY 1023

#define TRIG_MODE 0x11
#define AUTO_MODE 0x15
#define LOCK_MODE 0x0

#define NO_OPERATION  0x00
#define GROUP_CTL     0x30
#define SET_MODE      0x31
#define LAMP_ON       0x32
#define LAMP_OFF      0x33
#define FULL_LAMP     0x34
#define RESET_MODULE  0xFF
