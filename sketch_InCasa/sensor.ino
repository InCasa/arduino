void Movimento() {
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
