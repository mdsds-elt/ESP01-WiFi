# 1 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino"
/****************************************
        AUTORA : MÁRCIA DE SÁ    
                ESP01-WiFi   
*****************************************/
# 6 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino" 2
# 7 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino" 2
# 8 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino" 2
# 9 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino" 2
# 10 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino" 2
# 11 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino" 2
# 12 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino" 2
# 13 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino" 2

Adafruit_ADS1115 ads;
SSD1306Wire display(0x3c, 0, 2);
/*---------------------------------------- 
    ######## Thread's Controll #########
------------------------------------------ */
ThreadController cpu;

Thread Sensores;
int lpg;

void LeituraSensor(){
    lpg = ads.readADC_SingleEnded(0);
    }
/*---------------------------------------- */
Thread MonitorSerial;
void mSerial(){
   Serial.print(((reinterpret_cast<const __FlashStringHelper *>(
# 30 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino" 3
               (__extension__({static const char __pstr__[] __attribute__((__aligned__(4))) __attribute__((section( "\".irom0.pstr." "ESP01WIFI-MQ2.ino" "." "30" "." "12" "\", \"aSM\", @progbits, 1 #"))) = (
# 30 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino"
               "NIVEL DE GÁS: "
# 30 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino" 3
               ); &__pstr__[0];}))
# 30 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino"
               ))));
   Serial.print(lpg);
   Serial.println(((reinterpret_cast<const __FlashStringHelper *>(
# 32 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino" 3
                 (__extension__({static const char __pstr__[] __attribute__((__aligned__(4))) __attribute__((section( "\".irom0.pstr." "ESP01WIFI-MQ2.ino" "." "32" "." "13" "\", \"aSM\", @progbits, 1 #"))) = (
# 32 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino"
                 " ppm "
# 32 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino" 3
                 ); &__pstr__[0];}))
# 32 "c:\\Users\\mdsds\\OneDrive\\Documentos\\ESP-01\\PROJETO-2\\ESP01WIFI-MQ2.ino"
                 ))));
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
