// 2 de abril de 2019
// ELIMINADA FUNCIÓN "CARGANDO" PARA AHORRAR ESPACIO
//
// Programa de garabullo
// Toda la información en https://github.com/garabullo/garabullo2018/wiki/1-Home
#include "configuracion.h" // en la pestaña configuración.h está todo lo que se puede modificar
#include "configuracion_avanzado.h" // en configuración_avanzado.h todas las configuraciones iniciales que no se deberían modificar
void setup(void) {
  limpia_eeprom(0); //función en la pestaña "juegos_comun" testea si es el primer uso del robot
  sonido_activado = EEPROM.read(0); // almacena el valor en una variable para no estar leyendo la EEPROM cada vez que se llame a funcion de sonido
  led.begin();  
  //apaga_leds(1); 
  pantalla.initR(INITR_144GREENTAB);
  pantalla.setTextWrap(true); // Permite o no que el texto siga fuera de la pantalla o cambie de línea al llegar al borde
  
  pantalla.fillScreen(NEGRO);
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
  tiempo_ultimo_evento = millis();
}
void loop(void) {
 menu();

}
