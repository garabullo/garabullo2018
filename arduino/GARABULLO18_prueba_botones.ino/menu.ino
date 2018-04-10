String menu_principal[] = {"ROBOT", "JUEGOS", "RECORDS", "AJUSTES"};

void menu()
{
  pantalla.fillScreen(ST7735_BLACK);
  pantalla.setTextSize(2);
  pantalla.setTextColor(BLANCO);
  pantalla.setCursor(0, 0);
  pantalla.write(168);
  pantalla.print("QUE VAMOS A HACER?");
  bateria();
  pantalla.setTextSize(2);
  pantalla.setTextColor(AMARILLO);
  pantalla.setCursor(0, 60);
  pantalla.print(menu_principal[0]);
  pantalla.setTextColor(CYAN);
  pantalla.setCursor(56, 75);
  pantalla.print(menu_principal[1]);
  pantalla.setTextColor(VERDE);
  pantalla.setCursor(0, 90);
  pantalla.print(menu_principal[2]);
  pantalla.setTextColor(ROJO);
  pantalla.setCursor(44, 105);
  pantalla.print(menu_principal[3]);
  apaga_leds();
  led.setPixelColor(3, led.Color(brillo / 2, brillo, 0));
  led.setPixelColor(5, led.Color(0, brillo, brillo));
  led.setPixelColor(6, led.Color(0, brillo, 0));
  led.setPixelColor(8, led.Color(brillo, 0, 0));
  led.show();
  delay(1000);
  boolean salida = 0;
  while (!salida)
  {
    byte boton = boton_pulsado();
    switch (boton)
    {
      case 3:
        salida = 1;
        cuadros();
        break;
      case 5:
        salida = 1;
        cargando(8);
        juegos();
        break;
      case 6:
        salida = 1;
        cargando(4);
        records();
        break;
      case 8:
        salida = 1;
        cargando(3);
        ajustes();
        break;
    }
  }
}
void ajustes()
{
  {
    apaga_leds();
    leds_ajustes();
    pantalla.fillScreen(ST7735_BLACK);
    pantalla.setTextSize(3);
    pantalla.setTextColor(ROJO);
    pantalla.setCursor(0, 0);
    pantalla.print("-");
    pantalla.setTextColor(CYAN);
    pantalla.setCursor(30, 0);
    pantalla.print("LEDS");
    pantalla.setCursor(110, 0);
    pantalla.setTextColor(VERDE);
    pantalla.print("+");
    pantalla.setCursor(10, 50);
    pantalla.setTextColor(AZUL);
    pantalla.print("SONIDO");
    if (!sonido_activado)
    {
      pantalla.drawLine(10, 50, 110, 68, ROJO);
      pantalla.drawLine(10, 68, 110, 50, ROJO);
    }

    boolean salida = 0;
    while (!salida)
    {
      byte boton = boton_pulsado();
      switch (boton)
      {
        case 0:
          if (brillo > 15)
          {
            brillo -= 10;
          }
          else
          {
            sonido_fail();
          }
          leds_ajustes();
          break;
        case 2:
          if (brillo < 240)
          {
            brillo += 10;
          }
          else
          {
            sonido_fail();
          }
          leds_ajustes();
          break;
        case 4:
          sonido_activado = !sonido_activado;
          pantalla.setCursor(10, 50);
          pantalla.setTextColor(AZUL);
          pantalla.fillRect(0,49,128,20,NEGRO);
          pantalla.print("SONIDO");
          if (!sonido_activado)
          {
            pantalla.drawLine(10, 50, 113, 68, ROJO);
            pantalla.drawLine(10, 68, 113, 50, ROJO);
          }
          else pita();//viene de no hacer el pitido porque acaba de cambiar
          break;
        case 8:
          salida = 1;
          break;
      }
    }
  }
}
void leds_ajustes()
{
  led.setPixelColor(0, led.Color(brillo, 0, 0));
  led.setPixelColor(2, led.Color(0, brillo, 0));
  led.setPixelColor(4, led.Color(0, 0, brillo));
  led.setPixelColor(8, led.Color(brillo, 0, 0));

  led.show();
}


void juegos()
{
  pantalla.fillScreen(ST7735_BLACK);
  pantalla.setTextSize(2);
  pantalla.setTextColor(BLANCO);
  pantalla.setCursor(0, 0);
  pantalla.print("menu juegos");
  delay(3000);
}

void records()
{
  pantalla.fillScreen(ST7735_BLACK);
  pantalla.setTextSize(2);
  pantalla.setTextColor(BLANCO);
  pantalla.setCursor(0, 0);
  pantalla.print("menu records");
  delay(1000);
}

