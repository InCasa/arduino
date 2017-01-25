// Aciona determinado rele
void acionaRele(int canal) {
  switch (canal) {
    case 1:
      digitalWrite(pino_rele1, LOW);
      ligado_1 = false;
      break;
    case 2:
      digitalWrite(pino_rele2, LOW);
      ligado_2 = false;
      break;
    case 3:
      digitalWrite(pino_rele3, LOW);
      ligado_3 = false;
      break;
    case 4:
      digitalWrite(pino_rele4, LOW);
      ligado_4 = false;
      break;    
  }
}

//Desliga determinado rele
void desligaRele(int canal) {
  switch (canal) {
    case 1:
      digitalWrite(pino_rele1, HIGH);
      ligado_1 = true;
      break;
    case 2:
      digitalWrite(pino_rele2, HIGH);
      ligado_2 = true;
      break;
    case 3:
      digitalWrite(pino_rele3, HIGH);
      ligado_3 = true;
      break;
    case 4:
      digitalWrite(pino_rele4, HIGH);
      ligado_4 = true;
      break;
  }
}
