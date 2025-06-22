#define pin_led1 8    // Definindo LED 1
#define pin_botaoA 2  // Definindo botão A
int cont = 0;         // Variável de contagem

void setup() {
  pinMode(pin_led1, OUTPUT);
  pinMode(pin_botaoA, INPUT);
}

void loop() {
  bool A = digitalRead(pin_botaoA);   // Abreviando o botão A
  
  if (A == 1) {
    cont += 1;
  }
  if (cont % 2 == 0) { // se o modulo do contador for igual a 2, ele deve ligar
    digitalWrite(pin_led1, 1);
  } else {
    digitalWrite(pin_led1, 0); // caso o contrario deve desligar
  }
 
}
