#include <Arduino.h>
#line 1 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino"
/****************************************
        AUTORA : MÁRCIA DE SÁ    
                ESP01-WiFi   
*****************************************/
#include <FS.h>
#include <Wire.h>
#include "Thread.h"
#include <ESP8266WiFi.h>
#include "ThreadController.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_ADS1X15.h>
#include "SSD1306Wire.h"

Adafruit_ADS1115 ads;
SSD1306Wire  display(0x3c, 0, 2);
/*---------------------------------------- 
    ######## Thread's Controll #########
------------------------------------------ */
ThreadController cpu;

Thread Sensores;
int lpg;

#line 24 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino"
void LeituraSensor();
#line 29 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino"
void mSerial();
#line 34 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino"
void setup();
#line 53 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino"
void loop();
#line 60 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino"
void telainicial();
#line 24 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino"
void LeituraSensor(){
    lpg = ads.readADC_SingleEnded(0);
    }
/*---------------------------------------- */
Thread MonitorSerial;
void mSerial(){
   Serial.print(F("NIVEL DE GÁS: "));
   Serial.print(lpg);
   Serial.println(F(" ppm "));
}
void setup() {
/*-----------------------------------
 ##### Inicialização -- begin #######  
------------------------------------*/ 
  Serial.begin(115200);
  display.init();/*Inicializar a tela */
  display.flipScreenVertically();

  ads.begin();
/*---------------------------------------- */
  MonitorSerial.setInterval(900);
  MonitorSerial.onRun(mSerial);
  Sensores.setInterval(900);
  Sensores.onRun(LeituraSensor);
/*---------------------------------------- */
  cpu.add(&Sensores);
  cpu.add(&MonitorSerial);
}
/*---------------------------------------- */
void loop() {
   cpu.run();
   telainicial();
}
/**|-------------------------------|
   |      DISPLAY OLED CONFIG      |
   |-------------------------------| */
void telainicial(){ 
/*--------Apaga o display-----*/
  display.clear();
  //Desenha as molduras
  display.drawRect(0, 0, 128, 16);
  display.drawRect(0, 16, 128, 48);
  display.drawLine(67, 16, 67, 63);
  display.drawLine(67, 40, 128, 40);
  //Atualiza informacoes da temperatura
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawString(64, 2, "Sistema IoT");
  display.setFont(ArialMT_Plain_24);
  display.drawString(32, 26, String(lpg)); //MQ2
  //display.drawCircle(52, 32, 2);
  display.display();
}


