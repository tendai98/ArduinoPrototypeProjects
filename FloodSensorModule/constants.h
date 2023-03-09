#define SERIAL_BAUDRATE 9600

#define AP_SSID0 "Grid-0"
#define AP_PASS0 "iot_sensors"
#define AP_SSID1 "SNS-0"
#define AP_PASS1 "sensor-0"

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
