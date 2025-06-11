#define pin_led1 8    // Definindo LED Verificação
#define pin_led2 9    // Definindo LED Liberado
#define pin_led3 10   // Definindo LED Lotado
#define pin_botaoA 2  // Definindo botão SEV
#define pin_botaoB 3  // Definindo botão SSV
#define pin_botaoC 4  // Definindo botão BOT

int cont = 3;         // Variável de contagem
int aux = 0;          // Variável auxiliar
int aux1 = 0;         // Variável auxiliar 1
int limite = 10;      // Variável do limite
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
  bool SEV = digitalRead(pin_botaoA);   // Abreviando o botão SEV
  bool SSV = digitalRead(pin_botaoB);   // Abreviando o botão SSV
  bool BOT = digitalRead(pin_botaoC);   // Abreviando o botão BOT
  // Contagem de número (UP)
  if (SEV == 1 && aux == 0) {
    cont += 1;
    aux += 1; 
  }
  if (SEV == 0) {
    aux = 0;
  }
  // Contagem de número (DOWN)
  if (SSV == 1 && aux1 == 0) {
    cont -= 1;
    aux1 += 1;
  }
  if (SSV == 0) {
    aux1 = 0;
  }
  // Sistema do sensor de entrada de veículo (SEV)
  if ((cont >= 1)&&(cont <= 9)) {
    Serial.println("Estacionamento livre.");
    digitalWrite(pin_led2, 1);
  } else {
    digitalWrite(pin_led2, 0);
  }
  // Sistema do sensor de saída de veículo (SSV)
  if (cont >= limite) {
    Serial.println("Estacionamento lotado.");
    digitalWrite(pin_led3, 1);
  } else {
    digitalWrite(pin_led3, 0);
    Serial.println(cont);
  }
  // Caso o último carro saia do estacionamento, o LED Verificação irá ligar, indicando que todas as vagas estão livres
  if (cont == 0) {
    Serial.println("Todas as vagas estão livres.");
    digitalWrite(pin_led1, 1);
  } else {
    digitalWrite(pin_led1, 0);
  }
  // Caso o botão BOT for pressionado, o contador zera e o LED Verificação irá apagar
  if (BOT==1) {
    cont = 0;
  }
}
