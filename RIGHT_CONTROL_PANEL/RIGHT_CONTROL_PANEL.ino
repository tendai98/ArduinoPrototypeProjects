#define STICK_X_PIN  A6
#define STICK_Y_PIN  A7

#define STICK_SW_PIN 2
#define RADAR_PIN 3
#define TGP_PIN 4
#define AGM_MODE_PIN 5
#define AAM_MODE_PIN 6
#define TGP_SLEW_RATE A5

#define S_RADAR_MODE_PIN 7
#define FCR_RADAR_MODE_PIN 8
#define HARM_RADAR_MODE_PIN 9
#define WEAPON_RELEASE_PIN 10
#define CAPTURE_OR_TRIGGER_PIN 11

#define SLEW_UP_BUTTON A0
#define SLEW_LEFT_BUTTON A3
#define SLEW_RIGHT_BUTTON A2
#define SLEW_DOWN_BUTTON A4

int x,y,sw;
int radar_on, tgp_on, agm, aam, slewrate, s_radar, fcr_radar, harm_radar, weapon_release,trigger_btn;
int up, left, right, down;


void setup() {
  Serial.begin(9600);
  pinMode(STICK_SW_PIN, INPUT_PULLUP);
  pinMode(RADAR_PIN, INPUT_PULLUP);
  pinMode(TGP_PIN, INPUT_PULLUP);
  pinMode(AGM_MODE_PIN, INPUT_PULLUP);
  pinMode(AAM_MODE_PIN, INPUT_PULLUP);
  pinMode(S_RADAR_MODE_PIN, INPUT_PULLUP);
  pinMode(FCR_RADAR_MODE_PIN, INPUT_PULLUP);
  pinMode(HARM_RADAR_MODE_PIN, INPUT_PULLUP);
  pinMode(WEAPON_RELEASE_PIN, INPUT_PULLUP);
  pinMode(CAPTURE_OR_TRIGGER_PIN, INPUT_PULLUP);
}

void loop() {
  x = analogRead(STICK_X_PIN);
  y = analogRead(STICK_Y_PIN);
  sw = digitalRead(STICK_SW_PIN);

  radar_on = digitalRead(RADAR_PIN);
  tgp_on = digitalRead(TGP_PIN);
  agm = digitalRead(AGM_MODE_PIN);
  aam = digitalRead(AAM_MODE_PIN);
  slewrate = analogRead(TGP_SLEW_RATE);
  s_radar = digitalRead(S_RADAR_MODE_PIN);
  fcr_radar = digitalRead(FCR_RADAR_MODE_PIN);
  harm_radar = digitalRead(HARM_RADAR_MODE_PIN);
  weapon_release = digitalRead(WEAPON_RELEASE_PIN);
  trigger_btn = digitalRead(CAPTURE_OR_TRIGGER_PIN);

  up = analogRead(SLEW_UP_BUTTON);
  left = analogRead(SLEW_LEFT_BUTTON);
  right = analogRead(SLEW_RIGHT_BUTTON);  
  down = analogRead(SLEW_DOWN_BUTTON);

  Serial.print("RCP-SOD:");
  Serial.print(x);
  Serial.print(":");
  Serial.print(y);
  Serial.print(":");
  Serial.print(sw);
  Serial.print(":");
  
  Serial.print(radar_on);
  Serial.print(":");
  Serial.print(tgp_on);
  Serial.print(":");
  Serial.print(agm);
  Serial.print(":");
  Serial.print(aam);               
  Serial.print(":");
  Serial.print(slewrate); 
  Serial.print(":");
  Serial.print(s_radar); 
  Serial.print(":");
  Serial.print(fcr_radar);   
  Serial.print(":");
  Serial.print(harm_radar);   
  Serial.print(":");
  Serial.print(weapon_release);
  Serial.print(":");
  Serial.print(trigger_btn);
  Serial.print(":");
  Serial.print(up);  
  Serial.print(":");
  Serial.print(left);  
  Serial.print(":");
  Serial.print(right);  
  Serial.print(":");
  Serial.print(down);  
  Serial.println(":RCP-EOD");

}

float mapFloat(float x, float in_min, float in_max, float out_min, float out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
