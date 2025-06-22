
const int pin_led1 = 2;
const int pin_led2 = 3;
const int pin_led3 = 4;
const int pin_led4 = 5;
const int botaoA = 6;  


unsigned long tempoantes = 0;
int atualestado = 0;
bool seqdireta = true;
bool seqativa = false;
bool botaoapertado = false;

void setup() {
  pinMode(pin_led1, OUTPUT);
  pinMode(pin_led2, OUTPUT);
  pinMode(pin_led3, OUTPUT);
  pinMode(pin_led4, OUTPUT);
  pinMode(botaoA, INPUT_PULLUP);
  
  digitalWrite(pin_led1, LOW);
  digitalWrite(pin_led2, LOW);
  digitalWrite(pin_led3, LOW);
  digitalWrite(pin_led4, LOW);
}

void loop() {
  unsigned long tempodepois = millis();
  

  if (digitalRead(botaoA) == LOW && !botaoapertado) {
    botaoapertado = true;
    seqdireta = !seqdireta;
    seqativa = true;
    atualestado = 0;
    tempoantes = tempodepois;
    
   
    digitalWrite(pin_led1, LOW);
    digitalWrite(pin_led2, LOW);
    digitalWrite(pin_led3, LOW);
    digitalWrite(pin_led4, LOW);
  }
  
  if (digitalRead(botaoA) == HIGH) {
    botaoapertado = false;
  }

  
  if (seqativa) {
    if (seqdireta) {
      if (atualestado == 0) {
        digitalWrite(pin_led1, HIGH);
        tempoantes = tempodepois;
        atualestado = 1;
      }
      
      if (atualestado == 1 && tempodepois - tempoantes >= 125) {
        digitalWrite(pin_led2, HIGH);
        tempoantes = tempodepois;
        atualestado = 2;
      }
      
      if (atualestado == 2 && tempodepois - tempoantes >= 250) {
        digitalWrite(pin_led3, HIGH);
        tempoantes = tempodepois;
        atualestado = 3;
      }
      
      if (atualestado == 3 && tempodepois - tempoantes >= 500) {
        digitalWrite(pin_led4, HIGH);
        tempoantes = tempodepois;
        atualestado = 4;
      }
      
      if (atualestado == 4 && tempodepois - tempoantes >= 500) {
        digitalWrite(pin_led1, LOW);
        digitalWrite(pin_led2, LOW);
        digitalWrite(pin_led3, LOW);
        digitalWrite(pin_led4, LOW);
        seqativa = false;
      }
      
    } else {
      if (atualestado == 0) {
        digitalWrite(pin_led4, HIGH);
        tempoantes = tempodepois;
        atualestado = 1;
      }
      
      if (atualestado == 1 && tempodepois - tempoantes >= 125) {
        digitalWrite(pin_led3, HIGH);
        tempoantes = tempodepois;
        atualestado = 2;
      }
      
      if (atualestado == 2 && tempodepois - tempoantes >= 250) {
        digitalWrite(pin_led2, HIGH);
        tempoantes = tempodepois;
        atualestado = 3;
      }
      
      if (atualestado == 3 && tempodepois - tempoantes >= 500) {
        digitalWrite(pin_led1, HIGH);
        tempoantes = tempodepois;
        atualestado = 4;
      }
      
      if (atualestado == 4 && tempodepois - tempoantes >= 500) {
        digitalWrite(pin_led1, LOW);
        digitalWrite(pin_led2, LOW);
        digitalWrite(pin_led3, LOW);
        digitalWrite(pin_led4, LOW);
        seqativa = false;
      }
    }
  }
}
