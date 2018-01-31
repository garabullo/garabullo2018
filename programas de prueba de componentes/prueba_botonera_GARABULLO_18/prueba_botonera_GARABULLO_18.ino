// programa para probar la BOTONERA de garabullo
// 17 enero de 2018
// escrito por Diegolale
// basado en los ejemplos de adafruit

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS     10
#define TFT_RST    8
#define TFT_DC     9

int lectura_A_anterior = 5;
int lectura_B_anterior = 5;

Adafruit_ST7735 pantalla = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);
int colores[] = {ST7735_RED, ST7735_GREEN, ST7735_BLUE, ST7735_WHITE, ST7735_MAGENTA, ST7735_YELLOW, ST7735_CYAN};

void setup(void) {
  pantalla.initR(INITR_144GREENTAB);
  pantalla.setTextWrap(true); // Permite o no que el texto siga fuera de la pantalla o cambie de línea al llegar al borde
  pantalla.fillScreen(ST7735_BLACK);
  pantalla.setRotation(3);
}

void loop(void) {
  int lectura_A = analogRead(A6);
  int lectura_B = analogRead(A7);
  if (lectura_A_anterior != lectura_A || lectura_B_anterior != lectura_B)
  {
    pantalla.fillScreen(0);
    pantalla.setCursor(5, 58);
    pantalla.setTextColor(ST7735_WHITE);
    pantalla.setTextSize(3);
    pantalla.println(lectura_A);
    pantalla.setCursor(64, 58);
    pantalla.setTextColor(ST7735_BLUE);
    pantalla.setTextSize(3);
    pantalla.println(lectura_B);
  }
  delay(100);
  lectura_A_anterior = lectura_A;
  lectura_B_anterior = lectura_B;
}


