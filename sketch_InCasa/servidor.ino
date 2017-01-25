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
            digitalWrite(pino_rele1, LOW);
            Serial.println("Rele 1 Ligado");
            ligado_1 = false;
          }
          else
          {
            //Desliga o Rele 1
            if (readString.indexOf("?1_desligar") > 0)
            {
              digitalWrite(pino_rele1, HIGH);
              Serial.println("Rele 1 Desligado");
              ligado_1 = true;
            }
          }

          //Controle do rele 2
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

          //Controle do rele 3
          Serial.println(readString);
          //Liga o Rele 3
          if (readString.indexOf("?3_ligar") > 0)
          {
            digitalWrite(pino_rele3, LOW);
            Serial.println("Rele 3 Ligado");
            ligado_3 = false;
          }
          else
          {
            //Desliga o Rele 3
            if (readString.indexOf("?3_desligar") > 0)
            {
              digitalWrite(pino_rele3, HIGH);
              Serial.println("Rele 3 Desligado");
              ligado_3 = true;
            }
          }

          //Controle do rele 4
          Serial.println(readString);
          //Liga o Rele 4
          if (readString.indexOf("?4_ligar") > 0)
          {
            digitalWrite(pino_rele4, LOW);
            Serial.println("Rele 4 Ligado");
            ligado_4 = false;
          }
          else
          {
            //Desliga o Rele 4
            if (readString.indexOf("?4_desligar") > 0)
            {
              digitalWrite(pino_rele4, HIGH);
              Serial.println("Rele 4 Desligado");
              ligado_4 = true;
            }
          }

          //Retorno do Json de temperatura          
          Serial.println(readString);
          //Liga o Rele 4
          if (readString.indexOf("?temperatura") > 0)
          {
            jsonTemperatura();
            Serial.println(jsonTemperatura);            
          }

          //Retorno do Json de umidade          
          Serial.println(readString);
          //Liga o Rele 4
          if (readString.indexOf("?umidade") > 0)
          {
            jsonUmidade();
            Serial.println(jsonUmidade());            
          }

          //Retorno do Json de luminosidade          
          Serial.println(readString);
          //Liga o Rele 4
          if (readString.indexOf("?luminosidade") > 0)
          {
            jsonLuminosidade();
            Serial.println(jsonLuminosidade());            
          }

          //Retorno do Json de movimento          
          Serial.println(readString);
          //Liga o Rele 4
          if (readString.indexOf("?movimento") > 0)
          {
            jsonMovimento();
            Serial.println(jsonMovimento());            
          }
                    
          readString = "";

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

          delay(1);
          client.stop();
        }
      }
    }
  }
}
