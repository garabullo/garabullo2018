// 29 de marzo de 2018
// Programa de garabullo
// Toda la información en https://github.com/garabullo/garabullo2018/wiki/1-Home

#include "configuracion.h" // en la pestaña configuración.h está todo lo que se puede modificar
#include "configuracion_avanzado.h" // en configuración_avanzado.h todas las configuraciones iniciales que no se deberían modificar
int banderita = 1;
void setup(void) {
  limpia_eeprom(0); //función en la pestaña "juegos_comun" testea si es el primer uso del robot
  sonido_activado = EEPROM.read(0); // almacena el valor en una variable para no estar leyendo la EEPROM cada vez que se llame a funcion de sonido
  led.begin();
  apaga_leds();
  pantalla.initR(INITR_144GREENTAB);
  pantalla.setTextWrap(true); // Permite o no que el texto siga fuera de la pantalla o cambie de línea al llegar al borde
  pantalla.fillScreen(ST7735_BLACK);
  pantalla.setRotation(1);
  pinMode(IN1d, OUTPUT);
  pinMode(IN2d, OUTPUT);
  pinMode(IN3d, OUTPUT);
  pinMode(IN4d, OUTPUT);
  pinMode(IN1i, OUTPUT);
  pinMode(IN2i, OUTPUT);
  pinMode(IN3i, OUTPUT);
  pinMode(IN4i, OUTPUT);
  pinMode(buzzer, OUTPUT);
  presentacion();
}

void loop(void) {
  int boton = boton_pulsado();
  
  if (boton == 100)
  {
    if (banderita == 1)
    {
      pantalla.fillScreen(ST7735_BLACK);
      pantalla.setTextSize(5);
      pantalla.setTextColor(BLANCO);
      pantalla.setCursor(0, 0);
      pantalla.print("0");
      pantalla.setCursor(45, 0);
      pantalla.print("1");
      pantalla.setCursor(90, 0);
      pantalla.print("2");
      pantalla.setCursor(0, 45);
      pantalla.print("3");
      pantalla.setCursor(45, 45);
      pantalla.print("4");
      pantalla.setCursor(90, 45);
      pantalla.print("5");
      pantalla.setCursor(0, 90);
      pantalla.print("6");
      pantalla.setCursor(45, 90);
      pantalla.print("7");
      pantalla.setCursor(90, 90);
      pantalla.print("8");
      banderita = 0;
    }
  }
  else
  {
    pantalla.fillScreen(ST7735_BLACK);
    pantalla.setTextSize(7);
    pantalla.setTextColor(BLANCO);
    pantalla.setCursor(40, 40);
    pantalla.print(boton);
    banderita = 1;
    delay(2000);
  }
  delay(10);
}


