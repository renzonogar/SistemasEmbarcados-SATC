#define pin_led1 10                    // Definindo LED 1
#define pin_led2 11                    // Definindo LED 2
#define pin_botaoA 2                  // Definindo botão A
#define pin_botaoB 3                  // Definindo botão B

void setup() {
  pinMode(pin_led1, OUTPUT);
  pinMode(pin_led2, OUTPUT);
  pinMode(pin_botaoA, INPUT);
  pinMode(pin_botaoB, INPUT);
}

void loop() {
  bool A = digitalRead(pin_botaoA);   // Abreviando o botão A
  bool B = digitalRead(pin_botaoB);   // Abreviando o botão B

  if (A==1) { // caso o botaoA esteja ligado, ele liga o LED1 e desliga o LED2
  digitalWrite(pin_led1, 1);
  digitalWrite(pin_led2, 0);
  } 
  if (B==1) { // caso o botaoB esteja ligado, ele liga o LED2 e desliga o LED1
  digitalWrite(pin_led1, 0);
  digitalWrite(pin_led2, 1);    
  }



}
