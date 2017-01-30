int val;
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
          //Controle do rele 1
          Serial.println(readString);
          //Liga o Rele 1
          if (readString.indexOf("?1_ligar") > 0)
          {
            acionaRele(1);
            Serial.println("Rele 1 Ligado");            
          }
          else
          {
            //Desliga o Rele 1
            if (readString.indexOf("?1_desligar") > 0)
            {
              desligaRele(1);
              Serial.println("Rele 1 Desligado");              
            }
          }

          //Controle do rele 2
          Serial.println(readString);
          //Liga o Rele 2
          if (readString.indexOf("?2_ligar") > 0)
          {
            acionaRele(2);
            Serial.println("Rele 2 Ligado");            
          }
          else
          {
            //Desliga o Rele 2
            if (readString.indexOf("?2_desligar") > 0)
            {
              desligaRele(2);
              Serial.println("Rele 2 Desligado");              
            }
          }

          //Controle do rele 3
          Serial.println(readString);
          //Liga o Rele 3
          if (readString.indexOf("?3_ligar") > 0)
          {
            acionaRele(3);
            Serial.println("Rele 3 Ligado");            
          }
          else
          {
            //Desliga o Rele 3
            if (readString.indexOf("?3_desligar") > 0)
            {
              desligaRele(3);
              Serial.println("Rele 3 Desligado");              
            }
          }

          //Controle do rele 4
          Serial.println(readString);
          //Liga o Rele 4
          if (readString.indexOf("?4_ligar") > 0)
          {
            acionaRele(4);
            Serial.println("Rele 4 Ligado");            
          }
          else
          {
            //Desliga o Rele 4
            if (readString.indexOf("?4_desligar") > 0)
            {
              desligaRele(4);
              Serial.println("Rele 4 Desligado");              
            }
          }

          //Retorno do Json de temperatura          
          Serial.println(readString);
          //Liga o Rele 4
          if (readString.indexOf("?temperatura") > 0)
          {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: application/json");
            client.println();
            
            client.print('{');
            client.print("\"valor");
            client.print("\": ");
            client.print(temperatura);
            client.print(",");
            client.print("\"porta");
            client.print("\": ");
            client.print(pinoDHT);
            client.println('}');        
          }

          //Retorno do Json de umidade          
          Serial.println(readString);
          
          if (readString.indexOf("?umidade") > 0)
          {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: application/json");
            client.println();
            
            client.print('{');
            client.print("\"valor");
            client.print("\": ");
            client.print(umidade);
            client.print(",");
            client.print("\"porta");
            client.print("\": ");
            client.print(pinoDHT);
            client.println('}');                      
          }

          //Retorno do Json de luminosidade          
          Serial.println(readString);
          
          if (readString.indexOf("?luminosidade") > 0)
          {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: application/json");
            client.println();
            
            client.print('{');
            client.print("\"valor");
            client.print("\": ");
            client.print(luminosidade);
            client.print(",");
            client.print("\"porta");
            client.print("\": ");
            client.print('"');
            client.print(pinoLDR);
            client.print('"');
            client.println('}');             
          }

          //Retorno do Json de movimento          
          Serial.println(readString);
          
          if (readString.indexOf("?movimento") > 0)
          {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: application/json");
            client.println();
            
            client.print('{');
            client.print("\"valor");
            client.print("\": ");
            client.print(movimento);            
            client.print(",");
            client.print("\"porta");
            client.print("\": ");
            client.print(pinopir);
            client.println('}');         
          }

          if (readString.indexOf("?rele/1") > 0)
          {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: application/json");
            client.println();
            
            client.print('{');
            client.print("\"valor");
            client.print("\": ");
            val = digitalRead(pino_rele1);  // ler o valor de entrada
            if (val == HIGH) {                       
              client.print(false);  
            } else {
              client.print(true);
            }
            client.print(",");
            client.print("\"porta");
            client.print("\": ");
            client.print(pino_rele1);
            client.println('}');        
          }

           if (readString.indexOf("?rele/2") > 0)
          {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: application/json");
            client.println();
            
            client.print('{');
            client.print("\"valor");
            client.print("\": ");
            val = digitalRead(pino_rele2);  // ler o valor de entrada
            if (val == HIGH) {                       
              client.print(false);  
            } else {
              client.print(true);
            }            
            client.print(",");
            client.print("\"porta");
            client.print("\": ");
            client.print(pino_rele2);
            client.println('}');            
          }

           if (readString.indexOf("?rele/3") > 0)
          {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: application/json");
            client.println();
            
            client.print('{');
            client.print("\"valor");
            client.print("\": ");
           val = digitalRead(pino_rele3);  // ler o valor de entrada
            if (val == HIGH) {                       
              client.print(false);  
            } else {
              client.print(true);
            }            
            client.print(",");
            client.print("\"porta");
            client.print("\": ");
            client.print(pino_rele3);
            client.println('}');        
          }

           if (readString.indexOf("?rele/4") > 0)
          {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: application/json");
            client.println();
            
            client.print('{');
            client.print("\"valor");
            client.print("\": ");
            val = digitalRead(pino_rele4);  // ler o valor de entrada
            if (val == HIGH) {                       
              client.print(false);  
            } else {
              client.print(true);
            }            
            client.print(",");
            client.print("\"porta");
            client.print("\": ");
            client.print(pino_rele4);
            client.println('}');          
          }
                    
          readString = "";
          /*
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
          client.println("<html>");
          
          client.println("<head>");
          client.println("<title>InCasa</title>");
          client.println("<meta http-equiv='Content-Type' content='text/html; charset=UTF-8'>");                 
          client.println("</head>");
          
          client.println("<body>");                  

          client.println("Sistema Arduino");     
           
          client.println("</body>");         
          client.println("</html>");
          */
          delay(1);
          client.stop();
          
        }
      }
    }
  }
}
