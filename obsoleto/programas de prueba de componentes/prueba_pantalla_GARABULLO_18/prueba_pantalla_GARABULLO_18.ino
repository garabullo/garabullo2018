// programa para probar la pantalla de garabullo y el buzzer
// 14 enero de 2018 
// escrito por Diegolale
// basado en los ejemplos de adafruit

#include <Adafruit_GFX.h> 
#include <Adafruit_ST7735.h>
#include <SPI.h>



int delayval = 50; // delay for half a second


#define TFT_CS     10
#define TFT_RST    8
#define TFT_DC     9
//colores

#define rojo 0b1111100000000000
#define verde 0b0000011111100000
#define azul 0b0000000000011111
// blanco es: ST7735_WHITE
// negro es: ST7735_BLACK

Adafruit_ST7735 pantalla = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);
int colores[] = {ST7735_RED, ST7735_GREEN, ST7735_BLUE, ST7735_WHITE, ST7735_BLACK, ST7735_YELLOW};

void setup(void) {



  pantalla.initR(INITR_144GREENTAB);

  pantalla.setTextWrap(true); // Permite o no que el texto siga fuera de la pantalla o cambie de línea al llegar al borde
  pantalla.fillScreen(ST7735_BLACK);
  pantalla.setRotation(3);

}

void loop(void) {


  for (int cruce = 0; cruce < 4; cruce++)
  {
    pantalla.drawFastVLine(cruce * 36 + 10, 10, 108, verde);
    pantalla.drawFastHLine(10, cruce * 36 + 10, 108, verde);
  }
  int temp_beep = 100;
  int DIA = 12;
  int luz = 30;
  delay(1000);
  pantalla.fillCircle(64, 64, DIA, ST7735_YELLOW);
  tone(3, 500, temp_beep);
  delay(1000);
  pantalla.fillCircle(64 - 36, 64 - 36, DIA, ST7735_CYAN);
  tone(3, 1000, temp_beep);
  delay(1000);
  pantalla.fillCircle(64 + 36, 64 - 36, DIA, ST7735_YELLOW);
  tone(3, 500, temp_beep);
  delay(1000);
  pantalla.fillCircle(64 - 36, 64 + 36, DIA, ST7735_CYAN);
  tone(3, 1000, temp_beep);
  delay(1000);
  pantalla.fillCircle(64 - 36, 64, DIA, ST7735_YELLOW);
  tone(3, 500, temp_beep);
  delay(1000);
  pantalla.fillCircle(64 + 36, 64, DIA, ST7735_CYAN);
  tone(3, 1000, temp_beep);
  delay(1000);
  pantalla.fillScreen(ST7735_BLACK);


}

