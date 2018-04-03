


//****************ZONA DE CONFIGURACIONES QUE DEBERÍAN SER INVARIABLES****************************


/***************************Arrays derecho[] e izquierdo[]****************************************
   El array "derecho[]" almacena los pines del motor derecho IN1, IN2, IN3, IN4
   El array "izquierdo[]" almacena los pines del motor izquierdo IN1, IN2, IN3, IN4
*/
// Definimos los pines donde tenemos conectadas las bobinas
#define IN1d  4
#define IN2d  5
#define IN3d  6
#define IN4d  7

#define IN1i  2
#define IN2i 12
#define IN3i 14
#define IN4i 15






//el pin donde está conectado el buzzer
#define buzzer      3
//el pin donde está conectada la batería para ver el nivel
#define bateria     16
// 
#define PIN         17
//el número de pixels del robot. 9 de la botonera más uno del nivel de batería
#define NUMPIXELS   10

#define TFT_CS     10
#define TFT_RST    8
#define TFT_DC     9

#define botonera1  A6
#define botonera2  A7


#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

Adafruit_ST7735 pantalla = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);
int colores[] = {ST7735_RED, ST7735_GREEN, ST7735_BLUE, ST7735_WHITE, ST7735_MAGENTA, ST7735_YELLOW, ST7735_CYAN};
Adafruit_NeoPixel led = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

