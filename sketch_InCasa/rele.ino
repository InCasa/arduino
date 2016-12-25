// Aciona determinado rele
void acionaRele(int canal) {
  switch (canal) {
    case 1:
      digitalWrite(pino_rele1, LOW);
      break;
    case 2:
      digitalWrite(pino_rele2, LOW);
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
  }
}
