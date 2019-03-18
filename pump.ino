#define UP_PIN 4
#define DN_PIN 5
#define ALARM_PIN 6

#define RELAY_PIN 2

#define LED_ON 13
#define LED_PUMP A0
#define LED_ALARM A1
#define BUZZER_PIN 10

void setup() {
  pinMode(UP_PIN, INPUT);
  pinMode(DN_PIN, INPUT);
  pinMode(ALARM_PIN, INPUT);

  pinMode(RELAY_PIN, OUTPUT);

  pinMode(LED_ON, OUTPUT);
  pinMode(LED_PUMP, OUTPUT);
  pinMode(LED_ALARM, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_ON, HIGH);
}

void loop() {
  if (digitalRead(ALARM_PIN) == 0) {
    digitalWrite(LED_ALARM, HIGH);
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(LED_PUMP, LOW);
    tone(BUZZER_PIN, 80);
    delay(1000);
    noTone(BUZZER_PIN);
  } else {
    digitalWrite(LED_ALARM, LOW);
    if ((digitalRead(UP_PIN) == true) && (digitalRead(DN_PIN) == true)) {
      digitalWrite(LED_PUMP, LOW);
      digitalWrite(RELAY_PIN, LOW);
    }
    if ((digitalRead(UP_PIN) == false) && (digitalRead(DN_PIN) == false)) {
      digitalWrite(LED_PUMP, HIGH);
      digitalWrite(RELAY_PIN, HIGH);
    }
  }
  delay(1000);
}
