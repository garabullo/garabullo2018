void juego_producto()
{
  pantalla.fillScreen(NEGRO);
  pantalla.setCursor(0, 0);
  pantalla.setTextSize(2);
  pantalla.setTextColor(VERDE);
  pantalla.print("29 de mayo");
  pantalla.setTextColor(ST7735_WHITE);
  pantalla.setCursor(0, 50);
  pantalla.setTextSize(1);
  pantalla.print("www.github.com/garabullo/garabullo18/wiki");
  pantalla.setCursor(80, 110);
  pantalla.setTextSize(1);
  pantalla.setTextColor(ROJO);
  pantalla.print("SALIR");
  boolean salida = 0;
  apaga_leds(0);
  led.setPixelColor(8, led.Color(brillo, 0, 0));
  led.show();
  while (!salida)
  {
    test_alive();
    byte boton = boton_pulsado();
    switch (boton)
    {
      case 8:
        salida = 1;
        break;
    }
  }
  
}

