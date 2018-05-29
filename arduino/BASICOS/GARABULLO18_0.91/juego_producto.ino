void juego_producto()
{
  puntuacion = 0;
  bateria();
  pantalla.fillScreen(NEGRO);
  apaga_leds(1);
  pantalla.setTextSize(2);
  pantalla.setTextColor(VERDE);
  pantalla.setCursor(10, 10);
  pantalla.print("Busca");
  pantalla.setTextColor(BLANCO);
  pantalla.setCursor(50, 35);
  pantalla.print("la");
  pantalla.setTextColor(ROJO);
  pantalla.setCursor(30, 60);
  pantalla.print("correcta");
  pantalla.setTextColor(BLANCO);
  pantalla.setCursor(0, 90);
  pantalla.print("record= ");
  pantalla.print(EEPROM.read(15));
  delay(3000);
  cuenta_atras(5);

  randomSeed(millis());


  tiempo_inicio = millis();
  tiempo_actual = millis();
  leds_amarillo();
  led.show();
  barra_nueva(tiempo_actual - tiempo_inicio , 30, 60000);
  while ((tiempo_actual - tiempo_inicio) < 60000)
  {
    tiempo_actual = millis();
    int numero_1 = random(1, 10);
    int numero_2 = random(1, 11);
    int respuesta_producto = numero_1 * numero_2;
    int posicion_acierto = random(10); // donde va a estar la respuesta correcta

    for (int i = 0; i < 9; i++) // aqui se colocan las respuestas en el array muestras
    {
      muestras[(i + posicion_acierto) % 9] = numero_1 * (((numero_2 + i) % 10));
      if (((numero_2 + i) % 10) == 0)
      {
        muestras[(i + posicion_acierto) % 9] = numero_1 * 10;
      }
    }

    pantalla.setTextSize(2);
    pantalla.setTextColor(CYAN);
    pantalla.setCursor(100, 1);
    if(puntuacion < 10)
    {
      pantalla.print(" ");
    }
    pantalla.print(puntuacion);
    pantalla.setTextSize(4);
    pantalla.setTextColor(VERDE);
    pantalla.setCursor(3, 1);
    pantalla.print(numero_1);
    pantalla.print("x");
    pantalla.print(numero_2);
    barra_nueva(tiempo_actual - tiempo_inicio, 30, 60000);
    presenta_muestras();
    // comienzo resolución
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    int boton = boton_pulsado();
    while (boton != posicion_acierto && (tiempo_actual - tiempo_inicio) < 60000)
    {
      boton = boton_pulsado();
      tiempo_actual = millis();
      barra_nueva(tiempo_actual - tiempo_inicio, 30, 60000);
    }
    if (boton == posicion_acierto)
    {
      puntuacion += 1;
    }
    pantalla.fillRect(0, 0, 128, 29, NEGRO);
  }
  final(puntuacion, 6);// Por un tema :P con ese 6 va a eeprom 15... cosas de la vida
}

void presenta_muestras()
{
  byte posicion_de_respuesta = 0;
  for (byte y = 0; y < 3; y++)
  {
    for (byte x = 0; x < 3; x++)
    {

      pantalla.drawRoundRect(3 + 41 * x, 36 + 31 * y, 40, 30, 5,  CYAN);
      pantalla.fillRoundRect(4 + 41 * x, 37 + 31 * y, 38, 28, 4,   NEGRO);
      pantalla.setTextSize(3);
      pantalla.setTextColor(AMARILLO);
      pantalla.setCursor(7 + 41 * x, 41 + 31 * y);
      if (muestras[posicion_de_respuesta] < 10)
      {
        pantalla.print(" ");
      }
      pantalla.print(muestras[posicion_de_respuesta]);
      posicion_de_respuesta += 1;
    }
  }
}
