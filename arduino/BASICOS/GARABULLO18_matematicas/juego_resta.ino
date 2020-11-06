void resta()
{
  puntuacion = 0;
  //bateria();
  pantalla.fillScreen(NEGRO);
  apaga_leds(1);
  pantalla.setTextSize(2);
  pantalla.setTextColor(VERDE);
  pantalla.setCursor(10, 10);
  pantalla.print("VERDADERO");
  pantalla.setTextColor(BLANCO);
  pantalla.setCursor(70, 35);
  pantalla.print("O");
  pantalla.setTextColor(ROJO);
  pantalla.setCursor(60, 60);
  pantalla.print("FALSO");
  pantalla.setTextColor(BLANCO);
  pantalla.setCursor(0, 90);
  pantalla.print("record= ");
  pantalla.print(EEPROM.read(16));
  delay(3000);
  cuenta_atras(5);
  tiempo_juego = 8000;
  tiempo_inicio = millis();
  tiempo_actual = millis();

  led.setPixelColor(3, led.Color(0, brillo, 0));
  led.setPixelColor(5, led.Color(brillo, 0, 0));
  led.show();
  barra_nueva(tiempo_actual - tiempo_inicio, 99, tiempo_juego);
  vidas = 3;
  while (vidas > 0)
  {
    tiempo_inicio = millis();
    tiempo_actual = millis();
    pantalla.fillRect(0, 0, 128, 98, NEGRO);
    pantalla.setTextSize(2);
    pantalla.setTextColor(ROJO);
    pantalla.setCursor(0, 0);
    for (int v = 0; v < vidas; v++)
    {
      pantalla.write(3);
    }
    randomSeed(millis());
    int primer_numero = random(1,11);
    int segundo_numero = random(1,11);
    int acierto = random(2); // si es cero es falso, si es uno acierta
    int resultado;
    if (segundo_numero > primer_numero) // si el segundo numero es mayor la resta es negativa... para niños no vale
    {
      resultado = segundo_numero;
      segundo_numero = primer_numero;
      primer_numero = resultado;
    }
    if (acierto)
    {
      resultado = primer_numero - segundo_numero;
    }
    else
    {
      int diferencia = random(1 , 3);
      int mas_menos = random(2);
      if (mas_menos)
      {
        resultado = primer_numero - segundo_numero + diferencia;
      }
      else
      {
        resultado = primer_numero - segundo_numero - diferencia;
        if (resultado < 0)
        {
         resultado = primer_numero - segundo_numero + 1;

        }
      }
    }
    pantalla.setTextSize(3);
    pantalla.setCursor(0, 105);
    pantalla.setTextColor(BEIS, VERDE);
    pantalla.print("SI");
    pantalla.setCursor(90, 105);
    pantalla.setTextColor(AMARILLO, ROJO);
    pantalla.print("NO");
    resultado = constrain(resultado, 0, 200);
    pantalla.setTextSize(4);
    pantalla.setTextColor(CYAN);
    pantalla.setCursor(50, 0);
    if (primer_numero < 10) {
      pantalla.print(" ");
    }
    pantalla.print(primer_numero);
    pantalla.setCursor(50, 35);
    if (segundo_numero < 10) {
      pantalla.print(" ");
    }

    pantalla.print(segundo_numero);
    pantalla.setCursor(26, 35);
    pantalla.print("-");
    pantalla.fillRect(26, 65, 70, 3, CYAN);
    pantalla.setCursor(26, 70);
    if (resultado < 100)
    {
      pantalla.print(" ");
      if (resultado < 10)
      {
        pantalla.print(" ");
      }
    }
    pantalla.print(resultado);
    pantalla.setTextSize(2);
    pantalla.setTextColor(VERDE);
    pantalla.fillRect(55, 110, 30, 15 , NEGRO);
    pantalla.setCursor(55, 110);
    pantalla.print(puntuacion);

    int boton = boton_pulsado();
    while (boton != 3 && boton != 5 && (tiempo_actual - tiempo_inicio) < tiempo_juego)
    {
      boton = boton_pulsado();
      delay(5);
      tiempo_actual = millis();
      barra_nueva(tiempo_actual - tiempo_inicio, 99, tiempo_juego);
    }

    if ((boton == 3 && acierto == 1) || (boton == 5 && acierto == 0))
    {
      sonido_acierto();
      puntuacion += 1;
      tiempo_juego = tiempo_juego - tiempo_juego / 10;
      tiempo_inicio = millis();
    }
    else
    {
      vidas -= 1;
      tiempo_juego = 8000;
      sonido_fail();
      for (int i = 0; i < 128; i++)
      {
        pantalla.fillRect(0, 70, i, 28, AZUL);
        delay(10);
      }
      int resultado_correcto = primer_numero - segundo_numero;
      pantalla.setTextSize(4);
      pantalla.setCursor(26, 70);
      if (resultado < 100)
      {
        pantalla.print(" ");
        if (resultado < 10)
        {
          pantalla.print(" ");
        }
      }
      pantalla.print(resultado_correcto);
      delay(1500);
    }
  }
  apaga_leds(1);
  pantalla.fillScreen(NEGRO);
  final(puntuacion, 7);// Por un tema :P con ese 4 va a eeprom 13... cosas de la vida

}
