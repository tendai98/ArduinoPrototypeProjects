#define X_AXIS_PORT 34
#define Y_AXIS_PORT 35
#define BTN_PORT 32

#define MIN_ADC 0
#define MAX_ADC 4095
#define MIN_ANGLE 0
#define MAX_ANGLE 180

#define X_AXIS_OFFSET 119
#define Y_AXIS_OFFSET 116

String GLOBAL_CONTROL_DATA;

int dx, dy, xAnalog, yAnalog, button;

void readJoyStickState(){
  
  xAnalog = analogRead(X_AXIS_PORT);
  yAnalog = analogRead(Y_AXIS_PORT);
  button = analogRead(BTN_PORT);
  dx = map(xAnalog, MIN_ADC, MAX_ADC, MIN_ANGLE, MAX_ANGLE);
  dy = map(yAnalog, MIN_ADC, MAX_ADC, MIN_ANGLE, MAX_ANGLE);

  dx -= X_AXIS_OFFSET;
  dy -= Y_AXIS_OFFSET;
   
  GLOBAL_CONTROL_DATA = String(dx)+","+String(dy)+","+String(button);
}
