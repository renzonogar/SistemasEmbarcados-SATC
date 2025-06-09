#define pin_botaoA 2
#define pin_botaoB 3
int conta = 0;
int aux = 0;
int aux1 = 0;
int limite = 50;
void setup() {
  pinMode(pin_botaoA, INPUT);
  pinMode(pin_botaoB, INPUT);
  Serial.begin(9600);
}

void loop() {
  bool botaoA = digitalRead(pin_botaoA);
  bool botaoB = digitalRead(pin_botaoB);

  if (botaoA == 1) {
    if (aux == 0) {
      conta++;
      aux = 1;
    }
  } else {
    aux = 0;
  }

  if (botaoB == 1) {
    if (aux1 == 0) {
      conta--;
      aux1 = 1;
    }
  } else {
    aux1 = 0;
  }

  if (conta >= limite) {
    Serial.println("Limite atingido.");
  } else {
    Serial.println(conta);
  }

}
