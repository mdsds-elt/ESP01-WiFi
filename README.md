<p align="center">
 <h2 align="center">Módulo WiFi ESP8266-ESP01
</h2>   
</p>
  
  <p align='center'>
   <a href="https://twitter.com/MarciaMdsds"><img src="https://raw.githubusercontent.com/vinitshahdeo/Water-Monitoring-System/master/assets/twitter.png" width="32px" height="32px"></a> <a href="https://www.linkedin.com/in/mdsds/"><img src="https://raw.githubusercontent.com/vinitshahdeo/Water-Monitoring-System/master/assets/linkedin.png" width="32px" height="32px"></a>   
   </a>&nbsp;&nbsp;&nbsp;&nbsp;
 
 <hr>

* O Módulo ESP8266 WiFi Serial, desenvolvido especialmente para conectar projetos robóticos ou de automação residencial com s (Internet). Ele é composto pelo chip ESP8266 preparado para comunicação sem fio de baixa potência, operando com a rede Wi-Fi em frequência de 2.4GHz, possuindo suporte a WPA e WPA2.


<p align="center">
<img src="https://user-images.githubusercontent.com/81829451/134835552-66031de8-da34-489c-99f2-8f4d7e2534dd.png" width="500" height="200">
</p>

 <hr>
 
 `ESPECIFICAÇÕES:`
 
- [ ] Chip Principal: ESP8266;
    - [ ] Tensão de alimentação: 3.3V;
    - [ ] Potência de saída: +20dBm no modo 802.11b;
    - [ ] Alcance: ~90 metros;
    - [ ] Taxa de dados: 250kbps a 2mbit;
    - [ ] Suporte à redes: 802.11 b/g/n;
    - [ ] Consumo em Standby: <1.0mW;
    - [ ] Processador: 32-bit CPU de baixa potência;
    - [ ] Comunicação: Serial (TX/RX);
    - [ ] Comunicação: TCP e UDP;
    - [ ] Segurança: OPEN/WEP/WPA_PSK/WPA2_PSK/WPA_WPA2_PSK
    - [ ] Temperatura de trabalho: -40 a 125ºC;
    - [ ] Peso: 2g.
   
<p align="center">
<h2 align="center">PROJETOS COM ESP8266-ESP01 WiFi
</h2>   
</p>
   
  <hr>
  
[ESP01 WITH MQ2-OLED](https://github.com/mdsds-elt/ESP01-WiFi/tree/main/ESP01%20WITH%20MQ2-OLED)

* O projeto irá exibir na tela Oled as informações do sensor-MQ2.Como o ESP01-8266 tem poucas portas(GPIO's), utilizei o Módulo ADS1115 para que o sensor MQ2 possa sair de um sinal analógico para um estado do protocolo I2C. Então, tanto o Oled é o sensor MQ2 ficam na mesma rede I2C.

```bash

                           /-------------\      
                          |              |     
              |\/\/\/|   /   THANK YOU   \        
              |      |   |               |    
              | (o)(o)   \_   ___________/     
              c      _)    | /                               
               | '___|    <_/                    
               |   /                          
              /____\                          
             /      \                                           
  
  ```
  
