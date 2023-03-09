#define SENSOR_URL "http://192.168.4.1/value"
#define BUFFER_MAX_LEN 8
#define MAX_SAMPLE_VALUE 1024

#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>

HTTPClient http;
WiFiClient client;

int errorCode = 0;
int level = 0;
String returnData;

// Send and get HTTP data

void httpGet(char * url, char * bufferPtr){
  
  http.begin(client, url);  // begin HTTP GET using given URL
  errorCode = http.GET(); // Send HTTP GET
  
  if(errorCode > 0){
     // Read return string
     // Change the value to int and perform mathmetial operation
     returnData = http.getString();  // Set the value with unit
     returnData.toCharArray(bufferPtr, BUFFER_MAX_LEN); // Pack value to give pointer
     
  }

  http.end();
}

int getValue(char * url){
  
  http.begin(client, url);  // begin HTTP GET using given URL
  errorCode = http.GET(); // Send HTTP GET
  
  if(errorCode > 0){
    
     returnData = http.getString(); // Read return string
     http.end();
     return returnData.toInt(); // Change the value to int and perform mathmetial operation
     
  }

  return -1;
}
