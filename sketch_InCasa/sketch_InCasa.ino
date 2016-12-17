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
//9 - Rele
//10 - Rele
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
int pino_rele3 = 9;
int pino_rele4 = 10;

boolean ligado = true;
boolean ligado_2 = true;
boolean ligado_3 = true;
boolean ligado_4 = true;

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
  
  // Pinos rele para saida
  pinMode(pino_rele1, OUTPUT);
  pinMode(pino_rele2, OUTPUT);
  pinMode(pino_rele3, OUTPUT);
  pinMode(pino_rele4, OUTPUT);
  dht.begin();

  pinMode(pinopir, INPUT); //Define o pino sensor de presenca como entrada

  //Desliga os dois reles
  digitalWrite(pino_rele1, HIGH);
  digitalWrite(pino_rele2, HIGH);
  digitalWrite(pino_rele3, HIGH);
  digitalWrite(pino_rele4, HIGH);

}

void loop() {
  servidor();
}

// Metodos
// Aciona determinado rele
void acionaRele(int canal) {
  switch (canal) {
    case 1:
      digitalWrite(pino_rele1, LOW);
      break;
    case 2:
      digitalWrite(pino_rele2, LOW);
      break;
    case 3:
      digitalWrite(pino_rele3, LOW);
      break;
    case 4:
      digitalWrite(pino_rele4, LOW);
      break;
  }
}

//Desliga determinado rele
void desligaRele(int canal) {
  switch (canal) {
    case 1:
      digitalWrite(pino_rele1, HIGH);
      break;
    case 2:
      digitalWrite(pino_rele2, HIGH);
      break;
    case 3:
      digitalWrite(pino_rele3, HIGH);
      break;
    case 4:
      digitalWrite(pino_rele4, HIGH);
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

void servidor() {  
  EthernetClient client = server.available();
  if (client) {
    while (client.connected())
    {
      if (client.available())
      {
        char c = client.read();
        if (readString.length() < 100) {
          readString += c;
        }
        if (c == '\n')
        {
          //Controle do rele1
          Serial.println(readString);
          //Liga o Rele 1
          if (readString.indexOf("?ligar") > 0)
          {
            digitalWrite(pino_rele1, LOW);
            Serial.println("Rele 1 Ligado");
            ligado = false;
          }
          else
          {
            //Desliga o Rele 1
            if (readString.indexOf("?desligar") > 0)
            {
              digitalWrite(pino_rele1, HIGH);
              Serial.println("Rele 1 Desligado");
              ligado = true;
            }
          }
 
          //Controle do rele2
          Serial.println(readString);
          //Liga o Rele 2
          if (readString.indexOf("?2_ligar") > 0)
          {
            digitalWrite(pino_rele2, LOW);
            Serial.println("Rele 2 Ligado");
            ligado_2 = false;
          }
          else
          {
            //Desliga o Rele 2
            if (readString.indexOf("?2_desligar") > 0)
            {
              digitalWrite(pino_rele2, HIGH);
              Serial.println("Rele 2 Desligado");
              ligado_2 = true;
            }
          }
          readString = "";
 
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
          client.println("<html>");
          client.println("<head>");
          client.println("<title>InCasa</title>");
          client.println("<meta http-equiv='Content-Type' content='text/html; charset=ISO-8859-1'>");
          client.println("<meta name='viewport' content='width=720, initial-scale=0.5' />");
          client.println("<link rel='stylesheet' type='text/css' href='http://img.filipeflop.com/files/download/automacao/automacao_residencial.css' />");
          client.println("<script type='text/javascript' src='http://img.filipeflop.com/files/download/automacao/automacao_residencial.js'></script>");
          client.println("</head>");
          client.println("<body>");
          client.println("<div id='wrapper'><img alt='FILIPEFLOP' src='http://img.filipeflop.com/files/download/automacao/logoFF.jpg'/><br/>");
          client.println("<div id='div1'>Rele 1</div>");
          client.println("<div id='div2'>Rele 2</div>");
          client.print("<div id='rele'></div><div id='estado' style='visibility: hidden;'>");
          client.print(ligado);
          client.println("</div>");
          client.println("<div id='botao'></div>");
          client.println("<div id='botao_2'></div>");
          client.print("<div id='rele_2'></div><div id='estado_2' style='visibility: hidden;'>");
          client.print(ligado_2);
          client.println("</div>");
          client.println("</div>");
          client.println("<script>AlteraRele1()</script>");
          client.println("<script>AlteraRele2()</script>");
          client.println("</div>");
          client.println("</body>");
          client.println("</head>");
 
          delay(1);
          client.stop();
        }
      }
    }
  }   
}
