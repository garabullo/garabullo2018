void presentacion()
{
  pantalla.fillScreen(ST7735_BLACK);
  pantalla.setCursor(0, 0);
  pantalla.setTextSize(4);
  pantalla.setTextColor(ST7735_WHITE, ST7735_BLUE);
  pantalla.print("GARA BULLO 2018");
  pantalla.setTextColor(ST7735_WHITE);
  pantalla.setCursor(40, 115);
  pantalla.setTextSize(1);
  pantalla.setTextColor(ST7735_WHITE);
  pantalla.print(owner);
  int tiempo = millis();
  while (tiempo + 2000 > millis())
  {
    apaga_leds();
    led.setPixelColor(random(9), led.Color(0, 120, 0));
    led.show();
    delay(10);
  }
  apaga_leds();
  for (byte color = 0; color < 9; color++)
  {
    for (byte i = 0; i < 65; i++)
    {
      pantalla.drawRect(64 - i, 64 - i, i * 2, i * 2, colores_propios[color]);
      delay(3);
    }
  }
  pantalla.fillScreen(NEGRO);
}

