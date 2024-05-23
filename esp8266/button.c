int button_status = 0;

void setup() {
  // put your setup code here, to run once:
    pinMode(D2, OUTPUT); // выход светодиод
    pinMode(D3, INPUT_PULLUP); // пин кнопки вход подтянут к питанию    
}

void loop() {
  // put your main code here, to run repeatedly:
    button_status = digitalRead(D3);
    if (button_status == LOW) {
      digitalWrite(D2, HIGH);
      delay(1000);
      digitalWrite(D2, LOW);
    }
}
