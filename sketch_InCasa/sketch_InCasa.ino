// Pinos Rele
int rele1 = 7;
int rele2 = 8;
int rele3 = 9;
int rele4 = 10;


void setup() {
  // Pinos rele para saida
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  pinMode(rele3, OUTPUT);
  pinMode(rele4, OUTPUT);
  
}

void loop() {
  
}

// Metodos
// Aciona determinado rele
void acionaRele(int canal) {
  switch(canal){
    case 1:
      digitalWrite(rele1, LOW);
    break;
    case 2:
      digitalWrite(rele2, LOW);
    break;
    case 3:
      digitalWrite(rele3, LOW);
    break;
    case 4:
      digitalWrite(rele4, LOW);
    break;  
  }  
}

//Desliga determinado rele
void desligaRele(int canal) {
  switch(canal){
    case 1:
      digitalWrite(rele1, HIGH);
    break;
    case 2:
      digitalWrite(rele2, HIGH);
    break;
    case 3:
      digitalWrite(rele3, HIGH);
    break;
    case 4:
      digitalWrite(rele4, HIGH);
    break;  
  }  
}

