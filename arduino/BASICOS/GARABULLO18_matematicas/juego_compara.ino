void compara()
{
  puntuacion = 0;
  //bateria();
  pantalla.fillScreen(NEGRO);
  apaga_leds(1);
  pantalla.setTextSize(2);
  pantalla.setTextColor(VERDE);
  pantalla.setCursor(10, 10);
  pantalla.print("COMPARA");
  pantalla.setTextColor(BLANCO);
  pantalla.setCursor(30, 35);
  pantalla.print("Y");
  pantalla.setTextColor(CYAN);
  pantalla.setCursor(20, 60);
  pantalla.print("COMPLETA");
  pantalla.setTextColor(BLANCO);
  pantalla.setCursor(0, 90);
  pantalla.print("record= ");
  pantalla.print(EEPROM.read(17));
  delay(3000);
  cuenta_atras(5);
  tiempo_juego = 8000;
  tiempo_inicio = millis();
  tiempo_actual = millis();

  led.setPixelColor(3, led.Color(0, brillo, 0));
  led.setPixelColor(4, led.Color(0, 0, brillo));
  led.setPixelColor(5, led.Color(brillo, 0, 0));
  led.show();
  barra_nueva(tiempo_actual - tiempo_inicio, 70, tiempo_juego);
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
    int primer_numero = random(1,10);
    int segundo_numero = random(1,10);


//presentacion en pantalla
    pantalla.setTextSize(5);
    pantalla.setCursor(0, 93);
    pantalla.setTextColor(BLANCO, VERDE);
    pantalla.print(">");
    pantalla.setCursor(49, 93);
    pantalla.fillRect(45, 93, 4, 38 , AZUL);
    pantalla.setTextColor(BLANCO, AZUL);
    pantalla.print("=");
    pantalla.setCursor(94, 93);
    pantalla.setTextColor(BLANCO, ROJO);
    pantalla.print("<");
    pantalla.setTextSize(4);
    pantalla.setTextColor(CYAN);
    pantalla.setCursor(0, 30);
    pantalla.print(primer_numero);
    pantalla.print(" ? ");
    pantalla.print(segundo_numero);
    pantalla.setTextSize(2);
    pantalla.setTextColor(VERDE);
    pantalla.fillRect(55, 0, 30, 15 , NEGRO);
    pantalla.setCursor(55, 0);
    pantalla.print(puntuacion);

    int boton = boton_pulsado();
    while (boton != 3 && boton != 5  && boton != 4 && (tiempo_actual - tiempo_inicio) < tiempo_juego)
    {
      boton = boton_pulsado();
      delay(5);
      tiempo_actual = millis();
      barra_nueva(tiempo_actual - tiempo_inicio, 70, tiempo_juego);
    }

    if ((boton == 3 && primer_numero - segundo_numero > 0)  || (boton == 4 && primer_numero - segundo_numero  == 0) || (boton == 5 && primer_numero - segundo_numero  < 0))
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
      pantalla.fillRect(45, 30, 30, 30, NEGRO);
      sonido_fail();
      
      pantalla.setTextSize(4);
      pantalla.setCursor(45,30);
      if(primer_numero > segundo_numero) pantalla.print(">"); else if(primer_numero < segundo_numero) pantalla.print("<"); else pantalla.print("=");
      delay(3000);
    }
  }
  apaga_leds(1);
  pantalla.fillScreen(NEGRO);
  final(puntuacion, 8);// Por un tema :P con ese 8 va a eeprom 17... cosas de la vida

}
