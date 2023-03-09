const char * AP_SSID = "RST-2";
const char * AP_PASS = "12345678";
#define HOSTNAME "rst-2"


/* GPIO Setup for the Veyron
#define TURN_MOTOR D0
#define RIGHT_GPIO D1
#define LEFT_GPIO  D2

#define DRIVE_MOTOR   D4
#define FORWARD_GPIO  D5
#define REVERSE_GPIO  D6 */

//GPIO setup for the RST Racer-Mod
#define DRIVE_MOTOR   D1
#define FORWARD_GPIO  D2
#define REVERSE_GPIO  D3

#define TURN_MOTOR D0
#define RIGHT_GPIO D5
#define LEFT_GPIO  D6

/* GPIO setup for the Divo-MOD
#define DRIVE_MOTOR   D0
#define FORWARD_GPIO  D1
#define REVERSE_GPIO  D2

#define TURN_MOTOR D7
#define RIGHT_GPIO D6
#define LEFT_GPIO  D5 */


#define TURN_LEFT_CODE      0x41 //A
#define TURN_RIGHT_CODE     0x42 //B
#define RUN_FULL_TEST       0x43 
#define RETURN_TURNER_CODE  0x44 //D

#define FORWARD_DRIVE_CODE  0x31 //1
#define REVERSE_DRIVE_CODE  0x32 //2
#define RESET_CONTROLLER    0x33
#define STOP_DRIVE_CODE     0x34 //4
#define E_BOOST_DRIVE_MODE  0x35
#define SHUTDOWN_MOTORS     0x58

#define MAX_PWM_DRIVE 700
#define TEST_DELAY 500
#define MAX_LEN 2
#define SERVER_PORT 8888
