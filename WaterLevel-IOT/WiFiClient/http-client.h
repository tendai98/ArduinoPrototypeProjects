#define WATER_LEVEL_SENSOR_URL "http://192.168.4.1/data"
#define BUFFER_MAX_LEN 32

#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>

HTTPClient http;
WiFiClient client;

int errorCode = 0;
String returnData;
// Send and get HTTP data

void httpGet(char * url, char * bufferPtr){
  
  http.begin(client, url);  // begin HTTP GET using given URL
  errorCode = http.GET(); // Send HTTP GET
  
  if(errorCode > 0){
    
     returnData = "Moisture: "+http.getString()+ " %";  // Set the value with unit
     returnData.toCharArray(bufferPtr, BUFFER_MAX_LEN); // Pack value to give pointer
     
  }

  http.end();
}
