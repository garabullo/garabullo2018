// juego basado en las baldosas de celda, hay que poner todas del mismo color

int juego_baldosas()
{
  pantalla.fillScreen(ST7735_BLACK);
  entrada();
  puntuacion = 0;
  tiempo_inicio = millis();
  pantalla.setTextSize(3);
  pantalla.setCursor(0, 5);
  pantalla.setTextColor(ST7735_WHITE, ST7735_BLUE);
  pantalla.print(" MAGIC  TILES ");
  pantalla.setTextColor(ST7735_BLUE, ST7735_YELLOW);
  pantalla.setCursor(2, 55);
  pantalla.setTextSize(2);
  pantalla.print("  LEVEL 1 ");

  randomSeed(analogRead(A2));
  baldosas_inicial();
  while (test_tiempo_suficiente())
  {
    switch (boton_pulsado())
    {
      case 0:
        matriz[0] = !matriz[0];
        matriz[1] = !matriz[1];
        matriz[3] = !matriz[3];
        break;

      case 1:
        matriz[0] = !matriz[0];
        matriz[1] = !matriz[1];
        matriz[2] = !matriz[2];
        matriz[4] = !matriz[4];
        break;

      case 2:
        matriz[1] = !matriz[1];
        matriz[2] = !matriz[2];
        matriz[5] = !matriz[5];
        break;

      case 3:
        matriz[0] = !matriz[0];
        matriz[6] = !matriz[6];
        matriz[3] = !matriz[3];
        matriz[4] = !matriz[4];
        break;

      case 4:
        matriz[4] = !matriz[4];
        matriz[1] = !matriz[1];
        matriz[3] = !matriz[3];
        matriz[5] = !matriz[5];
        matriz[7] = !matriz[7];
        break;

      case 5:
        matriz[5] = !matriz[5];
        matriz[2] = !matriz[2];
        matriz[4] = !matriz[4];
        matriz[8] = !matriz[8];
        break;

      case 6:
        matriz[6] = !matriz[6];
        matriz[7] = !matriz[7];
        matriz[3] = !matriz[3];
        break;

      case 7:
        matriz[6] = !matriz[6];
        matriz[7] = !matriz[7];
        matriz[4] = !matriz[4];
        matriz[8] = !matriz[8];
        break;

      case 8:
        matriz[8] = !matriz[8];
        matriz[7] = !matriz[7];
        matriz[5] = !matriz[5];
        break;
    }
    muestra_baldosas();
    if (test_terminado())
    {
      acierto();
      randomSeed(analogRead(A2));
      baldosas_inicial();
    }
    muestra_barra_crono();
    muestra_aciertos();
  }
  final(puntuacion);
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
void baldosas_inicial()
{
  for (int i = 0; i < 9; i++)
  {
    matriz[i] = random(2);
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
    else
    {
      led.setPixelColor(i, led.Color(0, brillo, 0));
    }
  }
  led.show();
}

boolean test_terminado()
{
  int contador = 0;
  for (int i = 0; i < 9; i++)
  {
    if (matriz[i])
    {
      contador += 1;
    }
  }
  if (contador != 0 && contador != 9)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}
void final(int puntuacion)
{
  //ole();
  pantalla.fillScreen(ST7735_BLACK);
  pantalla.setCursor(0,0);
  pantalla.setTextSize(3);
  pantalla.setTextColor(ST7735_WHITE, ST7735_BLUE);
  pantalla.print(" PUNTOS");
  pantalla.setTextColor(ST7735_WHITE);
  pantalla.print("    ");
  pantalla.print(puntuacion);
  delay(5000);
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
  puntuacion +=1;
}
void entrada()
{
  
}

