// programa para probar la BOTONERA de garabullo
// 17 enero de 2018
// escrito por Diegolale
// basado en los ejemplos de adafruit
#include "configuracion.h"
#include "configuracion_avanzado.h"

void setup(void) {
  led.begin();
  apaga_leds();
  pantalla.initR(INITR_144GREENTAB);
  pantalla.setTextWrap(true); // Permite o no que el texto siga fuera de la pantalla o cambie de línea al llegar al borde
  pantalla.fillScreen(ST7735_BLACK);
  pantalla.setRotation(3);
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
  juego_baldosas();
  //tone(buzzer, 500,500);
  //adelante();
  //tone(buzzer, 5000,500);
  //atras();
  //apaga_motores();
  
}


