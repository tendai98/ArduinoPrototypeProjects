#define SENSOR_PIN     D0

void getSensorValue() {
  int value = digitalRead(SENSOR_PIN);  // Ready analog pin
  webServer.send(HTTP_200_SCSS, CONTENT_TYPE_TEXT, String(value)); 
}

void getUptimeMS(){
  int time_ms = millis(); // Get current milliseconds since boot
  webServer.send(HTTP_200_SCSS, CONTENT_TYPE_TEXT, String(time_ms)); 
}


void notImplementedRoute(){
  webServer.send(HTTP_501_CODE, CONTENT_TYPE_TEXT, HTTP_501_MESSAGE);
}

void notFound(){
  webServer.send(HTTP_404_CODE, CONTENT_TYPE_TEXT, HTTP_404_MESSAGE);  
}
