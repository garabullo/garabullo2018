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
  pantalla.print("by DiegoLale");
  int tiempo = millis();
  while (tiempo + 2000 > millis())
  {
    apaga_leds();
    led.setPixelColor(random(9), led.Color(0, 120, 0));
    led.show();
    delay(10);
  }
  apaga_leds();
  for (byte color = 0; color < 7; color++)
  {
    for (byte i = 0; i < 65; i++)
    {
      pantalla.drawRect(64 - i, 64 - i, i * 2, i * 2, colores_propios[color]);
      delay(3);
    }
  }
  pantalla.fillScreen(NEGRO);
  delay(1000);
  cargando(10);
}

void cargando(int tiempo)
{
  pantalla.fillScreen(NEGRO);
  pantalla.setCursor(15, 40);
  pantalla.setTextSize(1);
  pantalla.setTextColor(CYAN);
  pantalla.print("CARGANDO...");
  pantalla.drawRect(0, 59, 128, 7, VERDE);
  delay(1000);
  for (int i = 0; i < 128; i ++)
  {
    pantalla.drawRect(0, 60, i, 5, VERDE);
    delay(tiempo);
    if (i < 34 || i == 42 || i == 86 || i > 100)
      delay(tiempo * 5);
  }



}

