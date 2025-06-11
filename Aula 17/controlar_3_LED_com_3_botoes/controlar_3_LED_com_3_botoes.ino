#define pin_led1 8    // Definindo LED 1
#define pin_led2 9    // Definindo LED 2
#define pin_led3 10   // Definindo LED 3
#define pin_botaoA 2    // Definindo botão 1
#define pin_botaoB 3    // Definindo botão 2
#define pin_botaoC 4    // Definindo botão 3

void setup() {
  pinMode(pin_led1, OUTPUT);
  pinMode(pin_led2, OUTPUT);
  pinMode(pin_led3, OUTPUT);
  pinMode(pin_botaoA, INPUT);
  pinMode(pin_botaoB, INPUT);
  pinMode(pin_botaoC, INPUT);
  Serial.begin(9600);
}

void loop() {
  bool A = digitalRead(pin_botaoA);   // Abreviando o botão 1
  bool B = digitalRead(pin_botaoB);   // Abreviando o botão 2
  bool C = digitalRead(pin_botaoC);   // Abreviando o botão 3

  // Se o botão 1 for pressionado, o LED 1 irá ligar, e quando solto, o LED 1 irá apagar
  if (A==1) {
    digitalWrite(pin_led1, 1);
  } else {
    digitalWrite(pin_led1, 0);
  }
  // Se o botão 2 for pressionado, o LED 2 irá ligar, e quando solto, o LED 2 irá apagar
  if (B==1) {
    digitalWrite(pin_led2, 1);
  } else {
    digitalWrite(pin_led2, 0);
  }
  // Se o botão 3 for pressionado, o LED 3 irá ligar, e quando solto, o LED 3 irá apagar
  if (C==1) {
    digitalWrite(pin_led3, 1);
  } else {
    digitalWrite(pin_led3, 0);
  }
}
