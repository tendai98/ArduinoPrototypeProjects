#define SERVER_URL "http://192.168.92.1/sensor"
#define BUFFER_MAX_LEN 8
#define MAX_SAMPLE_sensorValue 1024

#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>

HTTPClient http;
WiFiClient client;

int errorCode = 0;
int sensorValue = 0;
String returnData;

// Send and get HTTP data

void httpGet(char * url, char * bufferPtr){
  
  http.begin(client, url);  // begin HTTP GET using given URL
  errorCode = http.GET(); // Send HTTP GET
  
  if(errorCode > 0){
    
     returnData = http.getString(); // Read return string
     
     sensorValue = ((returnData.toInt()*100) / MAX_SAMPLE_sensorValue); // Change the sensorValue to int and perform mathmetial operation
     returnData = String(sensorValue);  // Set the sensorValue with unit
     returnData.toCharArray(bufferPtr, BUFFER_MAX_LEN); // Pack sensorValue to give pointer
     
  }

  http.end();
}
