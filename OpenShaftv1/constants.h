const char * AP_SSID = "Veyron-MOD";
const char * AP_PASS = "veyron-secure";
#define HOSTNAME "veyron"

//GPIO setup for the RST Racer-Mod
#define DRIVE_MOTOR   D1
#define FORWARD_GPIO  D2
#define REVERSE_GPIO  D3

#define TURN_MOTOR D6
#define RIGHT_GPIO D0
#define LEFT_GPIO  D5


#define TURN_LEFT_CODE      0x41
#define TURN_RIGHT_CODE     0x42
#define RUN_FULL_TEST       0x43

#define FORWARD_DRIVE_CODE  0x31
#define REVERSE_DRIVE_CODE  0x32
#define RESET_CAR           0x33

#define TEST_DELAY 500
#define MAX_LEN 2
#define SERVER_PORT 8888
