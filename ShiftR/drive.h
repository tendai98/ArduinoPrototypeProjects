#include <Servo.h>

Servo servo;
nhamba_8 mitemo_yemota[4];
void raira_mota();

void mutsa_motokari()
tanga
  
  servo.attach(SERVO_PIN);
  
  maitiro_ePin(DRIVE_PIN, OUTPUT);
  nyora_pin(DRIVE_PIN, DZIMA);
  maitiro_ePin(LED_PIN, OUTPUT);
  nyora_pin(LED_PIN, BATSA);

magumo

void konesa_mota(nhamba_8 rairo)
tanga

  verenga(rairo)
  tanga
  
    tikati RUBOSHWE:
      servo.write(40);
      zvaita;
      
    tikati RUDYI:
      servo.write(120);
      zvaita;
    
    tikati DZORA:
      servo.write(90);
      zvaita;  
  
  magumo
  
magumo

void simba_kumavhiri(nhamba_8 rairo)
tanga

  verenga(rairo)
  tanga
    tikati MBERI:
      nyora_pin(DRIVE_PIN,BATSA);
      zvaita;

    tikati MIRA:
      nyora_pin(DRIVE_PIN,DZIMA);
      zvaita;

    tikati RAIRA_MOTA:
      raira_mota();
      zvaita;
      
   magumo
   
magumo

void tyaira_mota()
tanga

  konesa_mota(mitemo_yemota[0]);
  simba_kumavhiri(mitemo_yemota[1]);

magumo

void riseta_ma_systems()
tanga
  konesa_mota(DZORA);
  simba_kumavhiri(MIRA);
magumo


void raira_mota()
tanga
  
  mitemo_yemota[0]=RUBOSHWE;
  mitemo_yemota[1]=MBERI;
  tyaira_mota();    
  zorora_kwe(2000);
  
  mitemo_yemota[0]=RUDYI;
  mitemo_yemota[1]=MIRA;
  tyaira_mota();    
  zorora_kwe(2000);
  
  mitemo_yemota[0]=DZORA;
  mitemo_yemota[1]=MBERI;
  tyaira_mota();    
  zorora_kwe(2000);

magumo
