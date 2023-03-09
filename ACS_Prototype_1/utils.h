#define BUZZER_PIN 11

void ringBuzzer(){
    analogWrite(BUZZER_PIN, 204);
    delay(1000);
    analogWrite(BUZZER_PIN, 0);
}
