//Projeto InCasa
//Includes
#include <Ethernet.h>
#include <DHT.h>

//Pinos
//1 - 
//2 - 
//3 - 
//4 - 
//5 - Sensor Temperatura
//6 - 
//7 - Rele
//8 - Rele
//9 - Rele
//10 - Rele
//11 - 
//12 - 
//13 - 
//A0 - LDR

//Definicoes de IP, mascara de rede e gateway
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,0,150);          //Define o endereco IP
IPAddress gateway(192,168,0,1);     //Define o gateway
IPAddress subnet(255, 255, 255, 0); //Define a mascara

// Pinos Rele
int rele1 = 7;
int rele2 = 8;
int rele3 = 9;
int rele4 = 10;

// Define pino e sensor DHT22
DHT dht(5, DHT22);

// Define o LDR
int ldrPin = 0; //LDR no pino analígico 8
int ldrValor = 0; //Valor lido do LDR

void setup() {
  //Inicializa a interface de rede
  Ethernet.begin(mac, ip, gateway, subnet);
  // Pinos rele para saida
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  pinMode(rele3, OUTPUT);
  pinMode(rele4, OUTPUT);
  dht.begin();
  
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

void Temperatura() {
  float temperatura     = dht.readTemperature();
}

void Umidade() {
  float umidade         = dht.readHumidity();
}

void Luminosidade(){
  //ler o valor do LDR
  ldrValor = analogRead(ldrPin); //O valor lido será entre 0 e 1023
}

}

