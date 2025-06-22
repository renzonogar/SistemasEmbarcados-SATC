#define pin_led1 8    // Definindo LED Válvula P
#define pin_led2 9    // Definindo LED Alarme AL
#define pin_led3 10   // Definindo LED bomba M1
#define pin_led4 11   // Definindo LED bomba M2
#define pin_botaoA 3  // Definindo sensor A
#define pin_botaoB 4  // Definindo sensor B
#define pin_botaoC 5  // Definindo sensor C
#define pin_botaoD 6  // Definindo sensor D
void setup() {
  pinMode(pin_led1, OUTPUT);
  pinMode(pin_led2, OUTPUT);
  pinMode(pin_led3, OUTPUT);
  pinMode(pin_led4, OUTPUT);
  pinMode(pin_botaoA, INPUT);
  pinMode(pin_botaoB, INPUT);
  pinMode(pin_botaoC, INPUT);
  pinMode(pin_botaoD, INPUT);
  Serial.begin(9600);
}

void loop() {
  bool A = digitalRead(pin_botaoA); // abreviando botaoA
  bool B = digitalRead(pin_botaoB); // abreviando botaoB
  bool C = digitalRead(pin_botaoC); // abreviando botaoC
  bool D = digitalRead(pin_botaoD); // abreviando botaoD

  if (A == 1) { //se o nível for "A", então fecha-se a válvula P e M1e M2 bombeiam
    digitalWrite(pin_led1, 0);
    digitalWrite(pin_led2, 0);
    digitalWrite(pin_led3, 1);
    digitalWrite(pin_led4, 1);
  }

  if ((C==1)||(D==1)) { // se o nível for inferior a "B", então abre-se a válvula P e somente M1 bombeia
    digitalWrite(pin_led1, 1);
    digitalWrite(pin_led2, 0);
    digitalWrite(pin_led3, 1);
    digitalWrite(pin_led4, 0);
  }

  if (D==1) { // abaixo de "C", soa o alarme 
    digitalWrite(pin_led1, 0);
    digitalWrite(pin_led2, 1);
    digitalWrite(pin_led3, 0);
    digitalWrite(pin_led4, 0);    
  }

  if ((A==0)&&(B==0)&&(C==0)&&(D==0)) {  // abaixo de "D", nenhuma das bombas deverá funcionar
    digitalWrite(pin_led1, 0);
    digitalWrite(pin_led2, 0);
    digitalWrite(pin_led3, 0);
    digitalWrite(pin_led4, 0); 
  }

}
