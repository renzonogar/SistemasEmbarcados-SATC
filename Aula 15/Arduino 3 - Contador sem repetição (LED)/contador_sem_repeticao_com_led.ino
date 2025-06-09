#define pin_led1 8
#define pin_led2 9
#define pin_led3 10
#define pin_led4 11
#define pin_botao1 2
#define pin_botao2 3
int cont1 = 0;
int cont2 = 0;
int cont3 = 0;
int cont4 = 0;
int tic1 = 0;
int tic2 = 0;
void setup() {
  pinMode(pin_led1, OUTPUT);
  pinMode(pin_led2, OUTPUT);
  pinMode(pin_led3, OUTPUT);
  pinMode(pin_led4, OUTPUT);
  pinMode(pin_botao1, INPUT);
  pinMode(pin_botao2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool botaoA = digitalRead(pin_botao1);
  bool botaoB = digitalRead(pin_botao2);


if (botaoA == 1 && tic1 == 0) {
    cont1 += 1;
    tic1 += 1;
 }
if(cont1 == 2){
cont1 -= 2;
cont2 += 1;
    }
if(cont2 == 2){
cont2 -= 2;
cont3 += 1;
}
if(cont3 == 2){
cont3 -= 2;
 cont4 += 1;
 }
if(cont4 == 2){
cont1 = 1;
cont2 = 1;
cont3 = 1;
cont4 = 1;
}
  
if (botaoA == 0) {
    tic1 = 0;
}
    
if (botaoB == 1 && tic2 == 0) {
    cont4 -= 1;
    tic2 += 1;
 }
if(cont4 == -1){
cont4 += 1;
cont1 -= 1;
    }
if(cont3 == -1){
cont3 += 1;
cont2 -= 1;
}
if(cont2 == -1){
cont2 += 1;
 cont1 -= 1;
 }
if(cont1 == 2){
cont1 = 0;
cont2 = 0;
cont3 = 0;
cont4 = 0;
}
  
if (botaoB == 0) {
    tic2 = 0;
}
 





  
  if (botaoB == 0) {
    tic2 = 0;
  }
  if (cont1 == 1){
    digitalWrite(pin_led1, 1);
  }else{
    digitalWrite(pin_led1, 0);
  }
  if (cont2 == 1){
    digitalWrite(pin_led2, 1);
  }else{
    digitalWrite(pin_led2, 0);
  }
  if (cont3 == 1){
    digitalWrite(pin_led3, 1);
  }else{
    digitalWrite(pin_led3, 0);
  }
  if (cont4 == 1){
    digitalWrite(pin_led4, 1);
  }else{
    digitalWrite(pin_led4, 0);
  }
}
