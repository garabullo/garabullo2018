


//****************ZONA DE CONFIGURACIONES QUE DEBERÍAN SER INVARIABLES****************************


/***************************Arrays derecho[] e izquierdo[]****************************************
   El array "derecho[]" almacena los pines del motor derecho IN1, IN2, IN3, IN4
   El array "izquierdo[]" almacena los pines del motor izquierdo IN1, IN2, IN3, IN4
*/
// Definimos los pines donde tenemos conectadas las bobinas
#define IN1d  3
#define IN2d  4
#define IN3d  5
#define IN4d  6

#define IN1i 7
#define IN2i 8
#define IN3i 9
#define IN4i 10

//el pin donde está conectado el buzzer
#define buzzer      2

//el pin donde está conectada la batería para ver el nivel
#define pin_bateria 19

//  pin donde están conectados los leds
#define PIN_leds    18
//el número de pixels del robot. 9 de la botonera más uno del nivel de batería
#define NUMPIXELS   10

//pines de la pantalla
#define TFT_CS      16
#define TFT_RST     15
#define TFT_DC      14

// pines analógicos de las dos partes de la botonera
#define botonera1   A6
#define botonera2   A7

// librerías necesarias para el funcionamiento del robot
#include <EEPROM.h>

#include <Adafruit_GFX.h>         // versión 1.4.8
#include <Adafruit_ST7735.h>      // versión 1.2.8
#include <SPI.h>

#include <Adafruit_NeoPixel.h>  // versión 1.1.8
#ifdef __AVR__
  #include <avr/power.h>
#endif


#define NEGRO    0x0000
#define AZUL     0x001F
#define ROJO      0xF800
#define VERDE    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define AMARILLO   0xFFE0
#define BLANCO    0xFFFF
//COLORES PROPIOS
//RRRRRGGGGGGBBBBB los primeros 5 bits son rojo, los 6 centrales verde y los cinco de menos peso azul... vaya lío
#define MARRON 0xFFE3
#define BEIS 0xC402
#define ROSA 0xF00F
#define GRIS 0x9999
#define CARNE 0xFCA5
#define NARANJA 0xFCE7
long colores_propios[] = {NEGRO, AZUL, ROJO, VERDE, CYAN, MAGENTA, AMARILLO, BLANCO, MARRON};



Adafruit_ST7735 pantalla = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);
int colores[] = {ST7735_RED, ST7735_GREEN, ST7735_BLUE, ST7735_WHITE, ST7735_MAGENTA, ST7735_YELLOW, ST7735_CYAN};
Adafruit_NeoPixel led = Adafruit_NeoPixel(NUMPIXELS, PIN_leds, NEO_GRB + NEO_KHZ800);

// uso de variables de la eeprom
// eeprom(0)  sonido activado

// eeprom(11) record magic tiles 1
// eeporm(12) record magic tiles 2
// eeprom(13) record sumas verdadero falso
// eeprom(14) simon
// eeprom(15) producto

// variables globales para el uso del robot
boolean sonido_activado; // la variable sonido activado se usa para volcar la eeprom y no tener que leer cada vez que se usa

// matriz pare el juego de baldosas... e o que cumpra
int matriz[9];
byte almacen [100]; // aquí se almacenan los movimientos del robot
byte puntero_almacen = 0;
boolean tiempo_suficiente;
long tiempo_juego;
long tiempo_actual;
long tiempo_inicio;
long tiempo_ultimo_evento;
long medida_tiempo;

byte muestras[9];

byte vidas;
int puntuacion;

int patas_oshwi = 0;
long tiempo_inicio_nota;
boolean cambio_nota;
int tiempo_espera_nota;
int nota_actual;
int noteDuration;
