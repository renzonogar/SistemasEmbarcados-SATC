#define pin_led1 8
#define pin_led2 9
#define pin_led3 10
#define pin_led4 11
#define pin_botaoA 2
#define pin_botaoB 3
int conta = 0;
int aux = 0;
int aux1 = 0;
void setup() {
  pinMode(pin_led1, OUTPUT);
  pinMode(pin_led2, OUTPUT);
  pinMode(pin_led3, OUTPUT);
  pinMode(pin_led4, OUTPUT);
  pinMode(pin_botaoA, INPUT);
  pinMode(pin_botaoB, INPUT);
  Serial.begin(9600);
}

void loop() {
  bool botaoA = digitalRead(pin_botaoA);
  bool botaoB = digitalRead(pin_botaoB);

  Serial.println(conta);
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

  digitalWrite(pin_led4, (conta >> 3) & 0x01);
  digitalWrite(pin_led3, (conta >> 2) & 0x01);
  digitalWrite(pin_led2, (conta >> 1) & 0x01);
  digitalWrite(pin_led1, (conta >> 0) & 0x01);
  Serial.println(conta);

  if (conta == 15) {
    conta = 0
  }
}
