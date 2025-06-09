#define pin_led1 8           //definir que o pino 8 se chama pin_led1
#define pin_led2 9           //definir que o pino 9 se chama pin_led2
#define pin_led3 10          //definir que o pino 10 se chama pin_led3
#define pin_led4 11          //definir que o pino 11 se chama pin_led4
#define pin_botao 2

void setup() {
  pinMode(pin_led1, OUTPUT);        //definir o pin_led1 como output
  pinMode(pin_led2, OUTPUT);        //definir o pin_led2 como output
  pinMode(pin_led3, OUTPUT);        //definir o pin_led3 como output
  pinMode(pin_led4, OUTPUT);        //definir o pin_led4 como output
  pinMode(pin_botao, INPUT);

}
void loop() {
  bool estado = digitalRead(pin_botao);
  if (estado == 1) {
    digitalWrite(pin_led1, HIGH);
    digitalWrite(pin_led2, LOW);
    digitalWrite(pin_led3, HIGH);
    digitalWrite(pin_led4, LOW);
  } else{
    digitalWrite(pin_led1, LOW);
    digitalWrite(pin_led2, HIGH);
    digitalWrite(pin_led3, LOW);
    digitalWrite(pin_led4, HIGH);
  }
}


