String menu_principal[] = {"ROBOT", "JUEGOS", "RECORDS", "AJUSTES"};

String pocoserio = "PULSA ALGOvenga...va";

void menu()
{
  pantalla.fillScreen(ST7735_BLACK);
  pantalla.setTextSize(2);
  pantalla.setTextColor(BLANCO);
  pantalla.setCursor(0, 0);
  pantalla.print(pocoserio);
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
        juegos();
        break;
      case 6:
        salida = 1;
        records();
        break;
      case 8:
        salida = 1;
        ajustes();
        break;
    }
  }
}
void ajustes()
{
  {
    pantalla.fillScreen(ST7735_BLACK);
    pantalla.setTextSize(2);
    pantalla.setTextColor(BLANCO);
    pantalla.setCursor(0, 0);
    pantalla.print("menu ajustes");
    delay(1000);
  }
}

void juegos()
{
  
}

void records()
{
  
}

