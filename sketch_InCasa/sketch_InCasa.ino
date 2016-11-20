//Projeto InCasa
//Includes
#include <Ethernet.h>
#include <DHT.h>
#include <SPI.h>

//Pinos
//1 -
//2 -
//3 -
//4 -
//5 - Sensor Temperatura
//6 - Sensor Presenca
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
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 150);       //Define o endereco IP
IPAddress gateway(192, 168, 1, 1);  //Define o gateway
IPAddress subnet(255, 255, 255, 0); //Define a mascara

// Pinos Rele
int rele1 = 7;
int rele2 = 8;
int rele3 = 9;
int rele4 = 10;

//Presenca
int pinopir = 6;  //Pino do sensor
int movimento;  //Variavel para guardar valor do sensor de presenca

// Define pino e sensor DHT22
DHT dht(5, DHT22);

// Define o LDR
int ldrPin = 0; //LDR no pino analígico 8
int ldrValor = 0; //Valor lido do LDR

// Definições das requests

// server
char serverName[] = "192.168.1.5";

// port
int serverPort = 80;

// page server
char pageName[] = "/backend/index.php";

EthernetClient client;
int totalCount = 0; 
char params[32];

// Tempo de delay

#define delayMillis 30000UL

unsigned long thisMillis = 0;
unsigned long lastMillis = 0;

void setup() {
  //Inicializa a interface de rede
  Ethernet.begin(mac, ip, gateway, subnet);
  // Pinos rele para saida
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  pinMode(rele3, OUTPUT);
  pinMode(rele4, OUTPUT);
  dht.begin();

  pinMode(pinopir, INPUT); //Define o pino sensor de presenca como entrada

  Serial.begin(9600);

  // Configuração inicial ethernet
  // disable SD SPI
  pinMode(4,OUTPUT);
  digitalWrite(4,HIGH);

  Serial.print(F("Starting ethernet"));
  if(!Ethernet.begin(mac)) Serial.println(F("failed"));
  else Serial.println(Ethernet.localIP());

  delay(2000);
  Serial.println(F("Ready"));

}

void loop() {
  request();
}

// Metodos
// Aciona determinado rele
void acionaRele(int canal) {
  switch (canal) {
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
  switch (canal) {
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

void Movimento(){
  movimento = digitalRead(pinopir); //Le o valor do sensor de presenca
}

void Temperatura() {
  float temperatura = dht.readTemperature();
}

void Umidade() {
  float umidade = dht.readHumidity();
}

void Luminosidade() {
  //ler o valor do LDR
  ldrValor = analogRead(ldrPin); //O valor lido será entre 0 e 1023
}

void request() {  
  thisMillis = millis();

  if(thisMillis - lastMillis > delayMillis) {
    lastMillis = thisMillis;

    // parâmetros
    sprintf(params,"temp1=%i",totalCount);     
    if(!postPage(serverName,serverPort,pageName,params)) Serial.print(F("Fail "));
    else Serial.print(F("Pass "));
    totalCount++;
    Serial.println(totalCount,DEC);
  }    

}

byte postPage(char* domainBuffer,int thisPort,char* page,char* thisData) {
  int inChar;
  char outBuf[64];

  Serial.print(F("Conectando"));

  if(client.connect(domainBuffer,thisPort) == 1) {
    Serial.println(F("Conectado"));

    // cabeçalho requisição
    sprintf(outBuf,"POST %s HTTP/1.1",page);
    client.println(outBuf);
    sprintf(outBuf,"Host: %s",domainBuffer);
    client.println(outBuf);
    client.println(F("Connection: close\r\nContent-Type: application/x-www-form-urlencoded"));
    sprintf(outBuf,"Content-Length: %u\r\n",strlen(thisData));
    client.println(outBuf);

    // body
    client.print(thisData);
  } else {
    Serial.println(F("Falha"));
    return 0;
  }

  int connectLoop = 0;

  while(client.connected()) {
    while(client.available()) {
      inChar = client.read();
      Serial.write(inChar);
      connectLoop = 0;
    }

    delay(1);
    connectLoop++;
    if(connectLoop > 10000) {
      Serial.println();
      Serial.println(F("Timeout"));
      client.stop();
    }
  }

  Serial.println();
  Serial.println(F("Desconectando"));
  client.stop();
  return 1;
}
