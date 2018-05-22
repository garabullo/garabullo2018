// juego basado en las baldosas de celda, hay que poner todas del mismo color

//records
//nivel 1 eeprom posicion 11
//nivel 2 eeprom posicion 12

void nivel_baldosas()
{
  bateria();// lo primero ver como está la batería
  pantalla.fillScreen(ST7735_BLACK);
  apaga_leds(0);
  led.setPixelColor(1, led.Color(0, brillo, 0));
  led.setPixelColor(4, led.Color(brillo, 0, 0));
  led.show();

  pantalla.setTextSize(3);
  pantalla.setCursor(0, 5);
  pantalla.setTextColor(ST7735_WHITE, ST7735_BLUE);
  pantalla.print(" MAGIC  TILES ");
  pantalla.setCursor(0, 60);
  pantalla.setTextColor(ST7735_GREEN);
  pantalla.print("NIVEL 1");
  pantalla.setCursor(0, 90);
  pantalla.setTextColor(ST7735_RED);
  pantalla.print("NIVEL 2");
  int salida = 0;
  int col;
  while (salida == 0)
  {
    test_alive();
    int boton = boton_pulsado();

    if (boton == 1)
    {
      col = 2;
      salida = 1;
    }
    else if (boton == 4)
    {
      col = 3;
      salida = 1;
    }
    delay(5);
  }

  apaga_leds(1);
  juego_baldosas(col);
}

void juego_baldosas(int colores)
{

  pantalla.fillScreen(ST7735_BLACK);
  entrada(colores);
  puntuacion = 0;
  tiempo_inicio = millis();
  pantalla.setTextSize(3);
  pantalla.setCursor(0, 5);
  pantalla.setTextColor(ST7735_WHITE, ST7735_BLUE);
  pantalla.print(" MAGIC  TILES ");
  pantalla.setTextColor(ST7735_BLUE, ST7735_YELLOW);
  pantalla.setCursor(2, 55);
  pantalla.setTextSize(2);
  pantalla.print("  NIVEL ");
  pantalla.print(colores - 1);
  pantalla.print(" ");
  randomSeed(millis());
  baldosas_inicial(colores);
  while (test_tiempo_suficiente())
  {
    switch (boton_pulsado())
    {
      case 0:
        matriz[0] = (matriz[0] + 1) % colores;
        matriz[1] = (matriz[1] + 1) % colores;
        matriz[3] = (matriz[3] + 1) % colores;
        break;

      case 1:
        matriz[0] = (matriz[0] + 1) % colores;
        matriz[1] = (matriz[1] + 1) % colores;
        matriz[2] = (matriz[2] + 1) % colores;
        matriz[4] = (matriz[4] + 1) % colores;
        break;

      case 2:
        matriz[1] = (matriz[1] + 1) % colores;
        matriz[2] = (matriz[2] + 1) % colores;
        matriz[5] = (matriz[5] + 1) % colores;
        break;

      case 3:
        matriz[0] = (matriz[0] + 1) % colores;
        matriz[6] = (matriz[6] + 1) % colores;
        matriz[3] = (matriz[3] + 1) % colores;
        matriz[4] = (matriz[4] + 1) % colores;
        break;

      case 4:
        matriz[4] = (matriz[4] + 1) % colores;
        matriz[1] = (matriz[1] + 1) % colores;
        matriz[3] = (matriz[3] + 1) % colores;
        matriz[5] = (matriz[5] + 1) % colores;
        matriz[7] = (matriz[7] + 1) % colores;
        break;

      case 5:
        matriz[5] = (matriz[5] + 1) % colores;
        matriz[2] = (matriz[2] + 1) % colores;
        matriz[4] = (matriz[4] + 1) % colores;
        matriz[8] = (matriz[8] + 1) % colores;
        break;

      case 6:
        matriz[6] = (matriz[6] + 1) % colores;
        matriz[7] = (matriz[7] + 1) % colores;
        matriz[3] = (matriz[3] + 1) % colores;
        break;

      case 7:
        matriz[6] = (matriz[6] + 1) % colores;
        matriz[7] = (matriz[7] + 1) % colores;
        matriz[4] = (matriz[4] + 1) % colores;
        matriz[8] = (matriz[8] + 1) % colores;
        break;

      case 8:
        matriz[8] = (matriz[8] + 1) % colores;
        matriz[7] = (matriz[7] + 1) % colores;
        matriz[5] = (matriz[5] + 1) % colores;
        break;
    }
    muestra_baldosas();
    if (test_terminado())
    {
      acierto();
      randomSeed(analogRead(A2));
      baldosas_inicial(colores);
    }
    muestra_barra_crono();
    muestra_aciertos();
  }
  final(puntuacion, colores);
  tiempo_ultimo_evento = millis();
}

void ole()
{
  for (int rep = 0; rep < 5; rep++)
  {
    for (int i = 500; i < 5000; i++)
    {
      tone(buzzer , i);
    }
    for (int i = 5000; i < 500; i-- )
    {
      tone(buzzer , i);

    }
  }
  noTone(buzzer);
}




//función que rellena la matriz inicial con valores aleatorios
void baldosas_inicial(int colores)
{
  for (int i = 0; i < 9; i++)
  {
    matriz[i] = random(colores);
    randomSeed(analogRead(pin_bateria));
  }
  muestra_baldosas();
}
void muestra_baldosas()
{
  for (int i = 0; i < 9; i++)
  {
    if (matriz[i] == 0)
    {
      led.setPixelColor(i, led.Color(brillo, 0, 0));
    }
    else if (matriz[i] == 1)
    {
      led.setPixelColor(i, led.Color(0, brillo, 0));
    }
    else if (matriz[i] == 2)
    {
      led.setPixelColor(i, led.Color(brillo, brillo, 0));
    }
  }
  led.show();
}

boolean test_terminado()
{
  if (matriz[0] == matriz[1] && matriz[1] == matriz[2] && matriz[2] == matriz[3] && matriz[3] == matriz[4] && matriz[4] == matriz[5] && matriz[5] == matriz[6] && matriz[6] == matriz[7] && matriz[7] == matriz[8])
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
void final(int puntuacion, int colores)
{
  //ole();
  apaga_leds(0);
  led.setPixelColor(8, led.Color(brillo, 0, 0));
  led.show();
  pantalla.fillScreen(ST7735_BLACK);
  pantalla.setCursor(0, 0);
  pantalla.setTextSize(3);
  pantalla.setTextColor(ST7735_WHITE, ST7735_BLUE);
  pantalla.print(" PUNTOS");
  pantalla.setTextColor(ST7735_WHITE);
  pantalla.print("    ");
  pantalla.print(puntuacion);
  if (puntuacion >= EEPROM.read(colores + 10 - 1)) // testea si hay record nuevo
  {
    pantalla.setCursor(0, 60);
    pantalla.setTextSize(3);
    pantalla.setTextColor(ST7735_WHITE, ST7735_GREEN);
    pantalla.print("!RECORD NUEVO!");
    EEPROM.write(colores + 10 - 1 , puntuacion);
  }
  pantalla.setCursor(80, 110);
  pantalla.setTextSize(1);
  pantalla.setTextColor(ROJO);
  pantalla.print("SALIR");
  boolean salida = 0;
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
void muestra_aciertos()
{
  pantalla.setCursor(0, 83);
  pantalla.setTextSize(2);
  pantalla.setTextColor(ST7735_CYAN);
  for (int i = 0; i < puntuacion; i++)
  {
    pantalla.print(char(003));
  }
}
void acierto()
{
  sonido_acierto();
  puntuacion += 1;
}
void entrada(int col)
{
  apaga_leds(0);
  led.setPixelColor(4, led.Color(0, brillo, 0));
  led.show();

  pantalla.setCursor(0, 0);
  pantalla.setTextSize(3);
  pantalla.setTextColor(ST7735_WHITE);
  pantalla.print("Record actual = ");
  pantalla.print(EEPROM.read(col + 10 - 1));
  pantalla.setTextSize(2);
  pantalla.setTextColor(ST7735_GREEN);
  pantalla.setCursor(0, 80);
  pantalla.print("Pulsa para empezar");
  while (boton_pulsado() != 4)
  {
    test_alive();
    delay(5);
  }
  apaga_leds(1);
  pantalla.fillScreen(ST7735_BLACK);
  delay(1000);
}

