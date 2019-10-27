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
  apaga_leds(0);
  led.setPixelColor(3, led.Color(brillo / 2, brillo, 0));
  led.setPixelColor(5, led.Color(0, brillo, brillo));
  led.setPixelColor(6, led.Color(0, brillo, 0));
  led.setPixelColor(8, led.Color(brillo, 0, 0));
  led.show();
  delay(1000);
  boolean salida = 0;
  while (!salida)
  {
    test_alive();
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
    apaga_leds(0);
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
    pantalla.setTextSize(2);
    pantalla.setCursor(0, 50);
    pantalla.setTextColor(AZUL);
    pantalla.print("SONIDO");
    pantalla.setCursor(65, 65);
    pantalla.setTextColor(ROSA);
    pantalla.print("PASOS");
    pantalla.setCursor(65, 110);
    pantalla.setTextColor(NEGRO, ROJO);
    pantalla.print("SALIR");
    if (!sonido_activado)
    {
      pantalla.drawLine(0, 50, 70, 63, ROJO);
      pantalla.drawLine(0, 63, 70, 50, ROJO);
    }

    boolean salida = 0;
    while (!salida)
    {
      test_alive();
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
        case 3:
          sonido_activado = !sonido_activado;
          pantalla.setCursor(0, 50);
          pantalla.setTextColor(AZUL);
          pantalla.fillRect(0, 49, 70, 15, NEGRO);
          pantalla.setTextSize(2);
          pantalla.print("SONIDO");
          if (!sonido_activado)
          {
            pantalla.drawLine(0, 50, 70, 63, ROJO);
            pantalla.drawLine(0, 63, 70, 50, ROJO);
          }
          else pita();//viene de no hacer el pitido porque acaba de cambiar
          break;

        case 5:
          menu_pasos();
          salida = 1;
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
  led.setPixelColor(3, led.Color(0, 0, brillo));
  led.setPixelColor(5, led.Color(brillo, brillo / 2, brillo / 4));
  led.setPixelColor(8, led.Color(brillo, 0, 0));

  led.show();
}

void juegos()
{
  apaga_leds(0);
  led.setPixelColor(0, led.Color(0, brillo, 0));
  led.setPixelColor(2, led.Color(0, 0, brillo));
  led.setPixelColor(3, led.Color(brillo, brillo, 0));
  led.setPixelColor(5, led.Color(5, brillo, 0));
  led.setPixelColor(8, led.Color(brillo / 2, 0, 0));

  led.show();
  pantalla.fillScreen(ST7735_BLACK);
  pantalla.setTextSize(2);
  pantalla.setTextColor(VERDE);
  pantalla.setCursor(0, 0);
  pantalla.print("MAGIC");
  pantalla.setCursor(0, 18);
  pantalla.print("TILES");
  pantalla.setTextColor(AZUL);
  pantalla.setCursor(80, 9);
  pantalla.print("SUMA");
  pantalla.setTextColor(AMARILLO);
  pantalla.setCursor(0, 50);
  pantalla.print("SIMON");
  pantalla.setTextColor(VERDE);
  pantalla.setCursor(75, 43);
  pantalla.print("PRO-");
  pantalla.setCursor(68, 60);
  pantalla.print("DUCTO");

  pantalla.setTextColor(ROJO);
  pantalla.setCursor(65, 105);
  pantalla.print("SALIR");
  boolean salida = 0;
  while (!salida)
  {
    test_alive();
    byte boton = boton_pulsado();
    switch (boton)
    {
      case 0:
        apaga_leds(1);
        nivel_baldosas();
        salida = 1;
        break;
      case 2:
        apaga_leds(1);
        sumas();
        salida = 1;
        break;
      case 3:
        apaga_leds(1);
        juego_simon();
        salida = 1;
        break;
      case 5:
        apaga_leds(1);
        juego_producto();
        salida = 1;
        break;
      case 8:
        salida = 1;
        break;

    }
  }
}

void records()
{
  apaga_leds(1);
  pantalla.fillScreen(ST7735_BLACK);
  pantalla.setTextSize(2);
  pantalla.setTextColor(VERDE);
  pantalla.setCursor(0, 0);
  pantalla.print("BALDOSAS:");
  pantalla.setCursor(10, 20);
  pantalla.print("Niv1 = ");

  pantalla.print(EEPROM.read(11));
  pantalla.setCursor(10, 40);

  pantalla.print("Niv2 = ");

  pantalla.print(EEPROM.read(12));
  pantalla.setCursor(0, 60);

  pantalla.print("SUMAS = ");

  pantalla.print(EEPROM.read(13));

  pantalla.setCursor(0, 80);

  pantalla.print("PROD. = ");

  pantalla.print(EEPROM.read(15));

  pantalla.setCursor(0, 100);

  pantalla.print("SIMON = ");

  pantalla.print(EEPROM.read(14));
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

void menu_pasos()
{
  apaga_leds(0);
  led.setPixelColor(0, led.Color(brillo, 0, 0));
  led.setPixelColor(2, led.Color(0, brillo, 0));
  led.setPixelColor(3, led.Color(brillo, 0, 0));
  led.setPixelColor(5, led.Color(0, brillo, 0));
  led.setPixelColor(6, led.Color(0, 0, brillo));
  led.setPixelColor(8, led.Color(brillo, 0, 0));
  led.show();
  pantalla.fillScreen(ST7735_BLACK);
  pantalla.setTextSize(2);
  pantalla.setTextColor(ROJO);
  pantalla.setCursor(0, 0);
  pantalla.print("-");
  pantalla.setCursor(0, 50);
  pantalla.print("-");
  pantalla.setTextColor(CYAN);
  pantalla.setCursor(30, 0);
  pantalla.print("RECTO");
  pantalla.setCursor(35, 50);
  pantalla.print("GIRO");
  pantalla.setCursor(110, 0);
  pantalla.setTextColor(VERDE);
  pantalla.print("+");
  pantalla.setCursor(110, 50);
  pantalla.print("+");
  pantalla.setTextColor(AZUL);
  pantalla.setCursor(0, 110);
  pantalla.print("TEST");
  pantalla.setCursor(65, 110);
  pantalla.setTextColor(ROJO);
  pantalla.print("SALIR");
  muestra_pasos();

  boolean salida = 0;
  while (!salida)
  {
    test_alive();
    byte boton = boton_pulsado();
    switch (boton)
    {
      case 0:
        if (pasos_recto > 10)
        {
          pasos_recto -= 1;
          muestra_pasos();
        }
        else
        {
          sonido_fail();
        }
        break;

      case 2:
        if (pasos_recto < 220)
        {
          pasos_recto += 1;
          muestra_pasos();
        }
        else
        {
          sonido_fail();
        }
        break;

      case 3:
        if (pasos_giro > 10)
        {
          pasos_giro -= 1;
          muestra_pasos();
        }
        else
        {
          sonido_fail();
        }

        break;

      case 5:
        if (pasos_giro < 220)
        {
          pasos_giro += 1;
          muestra_pasos();
        }
        else
        {
          sonido_fail();
        }
        break;

      case 6:
        delay(1000);
        for (int a = 0; a < 2; a++)
        {
          adelante();
          for (int i = 0; i < 4; i++)
          {
            derecha();
          }
        }
        sonido_acierto();
        break;
      case 8:
        guarda_pasos();
        salida = 1;
    }
  }
}
void muestra_pasos()
{
  pantalla.fillRect(45, 15, 30, 18, NEGRO);
  pantalla.fillRect(45, 65, 30, 18, NEGRO);
  pantalla.setTextColor(AMARILLO);
  pantalla.setCursor(45, 15);
  pantalla.print(pasos_recto);
  pantalla.setCursor(45, 65);
  pantalla.print(pasos_giro);
}
void guarda_pasos()
{
  apaga_leds(0);
  led.setPixelColor(3, led.Color(0, brillo, 0));
  led.setPixelColor(5, led.Color(brillo, brillo / 2, brillo / 3));
  led.show();
  pantalla.fillScreen(NEGRO);
  pantalla.setTextColor(BLANCO);
  pantalla.setTextSize(2);
  pantalla.setCursor(8, 0);
  pantalla.print("-GUARDAR-");
  pantalla.setTextColor(VERDE);
  pantalla.setTextSize(4);
  pantalla.setCursor(0, 60);
  pantalla.print("NO");
  pantalla.setTextColor(NARANJA);
  pantalla.setCursor(80, 60);
  pantalla.print("SI");
  boolean salida = 0;
  while (!salida)
  {
    test_alive();
    byte boton = boton_pulsado();
    switch (boton)
    {
      case 3:
        salida = 1;
        break;
      case 5:
        if (pasos_recto != EEPROM.read(1))
        {
          EEPROM.write(1, pasos_recto);
        }
        if (pasos_giro != EEPROM.read(2))
        {
          EEPROM.write(2, pasos_giro);
        }
        salida = 1;
        break;
    }
  }
}

