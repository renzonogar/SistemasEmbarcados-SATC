#define pin_botao1 2
#define pin_botao2 3
int cont = 0;
int tic1 = 0;
int tic2 = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool botaoA = digitalRead(pin_botao1);
  bool botaoB = digitalRead(pin_botao2);

  Serial.println(cont);
 if (botaoA == 1 && tic1 == 0 && cont<50) {
    cont += 1;
    tic1 += 1;
  }
  if (botaoA == 0) {
    tic1 = 0;
  }
    
  if (botaoB == 1 && tic2 == 0 && cont>0) {
    cont -= 1;
    tic2 += 1;
  }
  if (botaoB == 0) {
    tic2 = 0;
  }
}
