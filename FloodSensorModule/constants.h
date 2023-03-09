#define SERIAL_BAUDRATE 9600

#define AP_SSID "Grid-0"
#define AP_PASS "iot_sensors"
#define SENSOR_ID 1001
#define CONNECT_DELAY 500

#define FIREBASE_URL "https://flood-sensors.firebaseio.com"
#define DATABASE_SECRET "WAuoI0NfTFjyxyCEqdXEpesSCMSHntDihmpiHOym"

#define DATA_PATH "/data/"
#define RAW_DATA_PATH "/rawAnalogValues/"
#define CURRENT_VALUE_PATH "/currentValue/"
#define CURRENT_RAW_VALUE "/rawValue/"
#define RESET_VALUE "/reset"
#define SENSOR_ID_PATH "/sensorID/"

#define RESET 0xBEBE

String path;
float sensorValue , rawValue;
int timestamp;
bool c;
