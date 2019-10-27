// programa para probar la BOTONERA de garabullo
// 17 enero de 2018
// escrito por Diegolale
// basado en los ejemplos de adafruit

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN            17


#define NUMPIXELS      9

#define TFT_CS     10
#define TFT_RST    8
#define TFT_DC     9
byte brillo = 10;
int lectura_A_anterior = 5;
int lectura_B_anterior = 5;

Adafruit_ST7735 pantalla = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);
int colores[] = {ST7735_RED, ST7735_GREEN, ST7735_BLUE, ST7735_WHITE, ST7735_MAGENTA, ST7735_YELLOW, ST7735_CYAN};
Adafruit_NeoPixel led = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup(void) {
  led.begin();
  pantalla.initR(INITR_144GREENTAB);
  pantalla.setTextWrap(true); // Permite o no que el texto siga fuera de la pantalla o cambie de línea al llegar al borde
  pantalla.fillScreen(ST7735_BLACK);
  pantalla.setRotation(3);
}

void loop(void) {
  menu();
  delay(20000);
}


