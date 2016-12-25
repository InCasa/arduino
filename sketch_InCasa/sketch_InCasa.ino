//Projeto InCasa
//https://github.com/incasa
//Includes
#include <Ethernet.h>
#include <DHT.h>
#include <SPI.h>

String readString;

//Pinos     
//1 -
//2 -
//3 -
//4 -
//5 - Sensor Temperatura
//6 - Sensor Presenca
//7 - Rele
//8 - Rele
//9 -
//10 -
//11 -
//12 -
//13 -
//A0 - LDR

//Definicoes de IP, mascara de rede e gateway
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 192, 168, 1, 150 };
byte gateway[] = { 192, 168, 1, 1 };
byte subnet[] = { 255, 255, 255, 0 };

EthernetServer server(80);

// Pinos Rele
int pino_rele1 = 7;
int pino_rele2 = 8;

boolean ligado_1 = true;
boolean ligado_2 = true;

//Presenca
int pinopir = 6;  //Pino do sensor
int movimento;  //Variavel para guardar valor do sensor de presenca

// Define pino e sensor DHT22
DHT dht(5, DHT22);

// Define o LDR
int ldrPin = 0; //LDR no pino analígico 8
int ldrValor = 0; //Valor lido do LDR

void setup() {

  Serial.begin(9600);
  pinMode(pino_rele1, OUTPUT);
  pinMode(pino_rele2, OUTPUT);

  //Inicializa Ethernet Shield
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();

  Serial.println("InCasa - Automacao Residencial");

  dht.begin();

  pinMode(pinopir, INPUT); //Define o pino sensor de presenca como entrada

  //Desliga os dois reles
  digitalWrite(pino_rele1, HIGH);
  digitalWrite(pino_rele2, HIGH);
}

void loop() {
  servidor();
}
