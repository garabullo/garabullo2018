// programa de prueba de leds de garabullo
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
// el pin al que están unidos los leds
// en la versión preliminar de la placa es el pin 12
//#define PIN 17
#define PIN 12
#define LEDS 9

Adafruit_NeoPixel leds = Adafruit_NeoPixel(LEDS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 50; // delay for half a second

void setup(void) {
  leds.begin();
  leds.show();
}
void loop(void) {
  int luz = 30;
  for (int i = 0; i < LEDS; i++) {
    leds.setPixelColor(i, leds.Color(0, 0, 0));
    leds.show();
  }
  tone(3, 500, 100);
  delay(1000);
  for (int i = 0; i < LEDS; i++) {
    leds.setPixelColor(i, leds.Color(luz, 0, 0));
    leds.show();
  }

  tone(3, 500, 100);
  delay(1000);
  for (int i = 0; i < LEDS; i++) {
    leds.setPixelColor(i, leds.Color(0, luz, 0));
    leds.show();
  }
  tone(3, 500, 100);
  delay(1000);

  for (int i = 0; i < LEDS; i++) {
    leds.setPixelColor(i, leds.Color(0, 0, luz));
    leds.show();
  }
  tone(3, 500, 100);
  delay(1000);
  for (int i = 0; i < LEDS; i++) {
    leds.setPixelColor(i, leds.Color(luz, luz, 0));
    leds.show();
  }
  tone(3, 500, 100);
  delay(1000);
  for (int i = 0; i < LEDS; i++) {
    leds.setPixelColor(i, leds.Color(0, luz, luz));
    leds.show();
  }
  tone(3, 500, 100);
  delay(1000);
  for (int i = 0; i < LEDS; i++) {
    leds.setPixelColor(i, leds.Color(luz, 0, luz));
    leds.show();
  }
  tone(3, 500, 100);
  delay(1000);
  for (int i = 0; i < LEDS; i++) {
    leds.setPixelColor(i, leds.Color(luz, luz, luz));
    leds.show();
  }
  tone(3, 500, 100);
  delay(1000);
}

