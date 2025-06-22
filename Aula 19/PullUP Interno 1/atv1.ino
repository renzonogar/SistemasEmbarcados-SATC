#define pin_led1 8
#define botaoA 2


bool stateled = false;
bool botaoApertado = false;
unsigned long tempoAntes = 0;
const long intervalo = 500;

void setup() {
  pinMode(pin_led1, OUTPUT);
  pinMode(botaoA, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(botaoA) == LOW && !botaoapertado) {
    botaoapertado = true;
    stateled = !stateled;
  } else if (digitalRead(botaoA) == HIGH) {
    botaoapertado = false;
  }

  if (stateled) {
    unsigned long tempoDepois = millis();
    if (tempoDepois - tempoAntes >= intervalo) {
      tempoAntes = tempoDepois;
      digitalWrite(pin_led1, !digitalRead(pin_led1));
    }
  } else {
    digitalWrite(pin_led1, LOW);
  }
}
