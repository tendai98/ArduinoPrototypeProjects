#define HMD_URL "http://192.168.4.1/humidity"
#define TMP_URL "http://192.168.4.1/temperature"

#define BUFFER_MAX_LEN 16
#define MAX_SAMPLE_VALUE 1024

#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>

HTTPClient http;
WiFiClient client;

int errorCode = 0;
String returnData;

void getTemperature(char * url, char * bufferPtr){
  
  http.begin(client, url);  // begin HTTP GET using given URL
  errorCode = http.GET(); // Send HTTP GET
  
  if(errorCode > 0){
     returnData = "Temp: "+http.getString()+"    *C";  // Set the value with unit
     returnData.toCharArray(bufferPtr, BUFFER_MAX_LEN); // Pack value to give pointer
     
  }

  http.end();
}

void getHumidity(char * url, char * bufferPtr){
  
  http.begin(client, url);  // begin HTTP GET using given URL
  errorCode = http.GET(); // Send HTTP GET
  
  if(errorCode > 0){
     returnData = "HMD: "+http.getString()+"     %";  // Set the value with unit
     returnData.toCharArray(bufferPtr, BUFFER_MAX_LEN); // Pack value to give pointer
  }

  http.end();
}
