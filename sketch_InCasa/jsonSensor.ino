void jsonTemperatura() {
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: application/json");
  client.println();
  
  client.print("('{");
  client.print("\"valor");
  client.print("\": ");
  client.print(temperatura);
  client.println("}')");
  break;
}

void jsonUmidade() {
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: application/json");
  client.println();
  
  client.print("('{");
  client.print("\"valor");
  client.print("\": ");
  client.print(umidade);
  client.println("}')");
  break;
}

void jsonLuminosidade() {
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: application/json");
  client.println();
  
  client.print("('{");
  client.print("\"valor");
  client.print("\": ");
  client.print(luminosidade);
  client.println("}')");
  break;
}

void jsonMovimento() {
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: application/json");
  client.println();
  
  client.print("('{");
  client.print("\"valor");
  client.print("\": ");
  client.print(movimento);
  client.println("}')");
  break;
}
