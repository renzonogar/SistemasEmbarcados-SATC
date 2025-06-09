#define pin_led1 8           //definir que o pino 8 se chama pin_led1
#define pin_led2 9           //definir que o pino 9 se chama pin_led2
#define pin_led3 10          //definir que o pino 10 se chama pin_led3
#define pin_led4 11          //definir que o pino 11 se chama pin_led4

void setup() {
  Serial.begin(9600);
  pinMode(pin_led1, OUTPUT);        //definir o pin_led1 como output
  pinMode(pin_led2, OUTPUT);        //definir o pin_led2 como output
  pinMode(pin_led3, OUTPUT);        //definir o pin_led3 como output
  pinMode(pin_led4, OUTPUT);        //definir o pin_led4 como output

}

void loop() {
  if (Serial.available() == 1) {
    char i = Serial.read();
    Serial.print(i);
  }
  Serial.println("Liga led");
  digitalWrite(pin_led1, HIGH);        //definir o pin_led1 como ligado
  digitalWrite(pin_led2, HIGH);        //definir o pin_led2 como ligado
  digitalWrite(pin_led3, HIGH);        //definir o pin_led3 como ligado
  digitalWrite(pin_led4, HIGH);        //definir o pin_led4 como ligado
  delay(1000);      //um pequeno atraso de 1 segundo
  Serial.println("Desliga led");
  digitalWrite(pin_led1, LOW);        //definir o pin_led1 como desligado
  digitalWrite(pin_led2, LOW);        //definir o pin_led2 como desligado
  digitalWrite(pin_led3, LOW);        //definir o pin_led3 como desligado
  digitalWrite(pin_led4, LOW);        //definir o pin_led4 como desligado
  delay(1000);      //um pequeno atraso de 1 segundo 
 
}
