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
          client.println("<script type='text/javascript' src='https://cdn.rawgit.com/InCasa/arduino/master/js/app.js'></script>");
          client.println("</head>");
          
          client.println("<body>"); 
                   
          client.println("<div id='div1'>Rele 1</div>");
          client.println("<div id='div2'>Rele 2</div>");
          
          client.print("<div id='rele_1'></div><div id='estado_1' style='visibility: hidden;'>");
          client.print(ligado_1);
          client.println("</div>");
          
          client.println("<div id='botao_1'></div>");
          client.println("<div id='botao_2'></div>");
          
          client.print("<div id='rele_2'></div><div id='estado_2' style='visibility: hidden;'>");
          client.print(ligado_2);
          client.println("</div>");
          
          client.println("<script>AlteraRele1()</script>");
          client.println("<script>AlteraRele2()</script>");          
          
          client.println("</body>");
          
          client.println("</head>");

          delay(1);
          client.stop();
        }
      }
    }
  }
}
