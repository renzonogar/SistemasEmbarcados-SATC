const int pin_led1 = 2;
const int pin_led2 = 3;
const int pin_led3 = 4;
const int pin_led4 = 5;

unsigned long tempoAntes = 0;
int atualestado = 0;

void setup() {
  pinMode(pin_led1, OUTPUT);
  pinMode(pin_led2, OUTPUT);
  pinMode(pin_led3, OUTPUT);
  pinMode(pin_led4, OUTPUT);

  digitalWrite(pin_led1, LOW);
  digitalWrite(pin_led2, LOW);
  digitalWrite(pin_led3, LOW);
  digitalWrite(pin_led4, LOW);
}

void loop() {
  unsigned long atualestado = millis();

  if (atualestado == 0) {
    digitalWrite(pin_led1, HIGH);
    tempoAntes = tempoDepois;
    atualestado = 1;
  }

  if (atualestado == 1) {
    if (tempoDepois - tempoAntes >= 125) {
      digitalWrite(pin_led2, HIGH);
      tempoAntes = tempoDepois;
      atualestado = 2;
    }
  }

  if (atualestado == 2) {  
    if (tempoDepois - tempoAntes >= 250) {
      digitalWrite(pin_led3, HIGH);
      tempoAntes = tempoDepois;
      atualestado = 3;
    }
  }
  if (atualestado == 3) { 
    if (tempoDepois - tempoAntes >= 500) {
      digitalWrite(pin_led4, HIGH);
      tempoAntes = tempoDepois;
      atualestado = 4;
    }
  }
  if (atualestado == 4) {  
    if (tempoDepois - tempoAntes >= 500) {
      digitalWrite(pin_led1, LOW);
      digitalWrite(pin_led2, LOW);
      digitalWrite(pin_led3, LOW);
      digitalWrite(pin_led4, LOW);
      tempoAntes = tempoDepois;
      atualestado = 0;  
    }
  }
}