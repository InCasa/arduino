void Movimento() {
  movimento = digitalRead(pinopir); //Le o valor do sensor de presenca
}

void Temperatura() {
  temperatura = dht.readTemperature(); //Le o valor do sensor de temperatura
}

void Umidade() {
  umidade = dht.readHumidity(); //Le o valor do sensor de umidade
}

void Luminosidade() {
  luminosidade = analogRead(ldrPin); //Le o valor do sensor de luminosidade(O valor lido será entre 0 e 1023)
}
