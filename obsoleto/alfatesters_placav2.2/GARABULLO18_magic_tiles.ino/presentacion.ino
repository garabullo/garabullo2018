void presentacion()
{
  pantalla.fillScreen(ST7735_BLACK);
  pantalla.setCursor(0,0);
  pantalla.setTextSize(4);
  pantalla.setTextColor(ST7735_WHITE, ST7735_BLUE);
  pantalla.print("GARA BULLO 2018");
  pantalla.setTextColor(ST7735_WHITE);
  pantalla.setCursor(40,115);
  pantalla.setTextSize(1);
  pantalla.setTextColor(ST7735_WHITE);
  pantalla.print("by DiegoLale");
  int tiempo = millis();
  while(tiempo + 5000 > millis())
  {
    apaga_leds();
    led.setPixelColor(random(9), led.Color(0, 120, 0));
    led.show();
    delay(10);
  }
  apaga_leds();
}

