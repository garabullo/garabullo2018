// Prueba de leds de garabullo
//basado en el ejemplo de la librería adafruit neopixel llamado "simple"

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(10, 18, NEO_GRB + NEO_KHZ800);

int delayval = 100;

void setup()
{
  pixels.begin();
}

void loop()
{
  for (int i = 0; i < 10; i++)
  {
    pixels.setPixelColor(i, pixels.Color(150, 0, 0));
    pixels.show();
    delay(delayval);
  }
  apaga();
  delay(delayval);
  
  for (int i = 0; i < 10; i++)
  {
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels.show();
    delay(delayval);
  }
  apaga();
  delay(delayval);
  for (int i = 0; i < 10; i++)
  {
    pixels.setPixelColor(i, pixels.Color(0, 0, 150));
    pixels.show();
    delay(delayval);
  }
  apaga();
  delay(delayval);
}
void apaga()
{
  for (int i = 0; i < 10; i++)
  {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
  pixels.show();
}

