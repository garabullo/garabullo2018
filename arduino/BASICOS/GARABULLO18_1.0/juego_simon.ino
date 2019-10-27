void juego_simon()
{
  puntuacion = 0;
  bateria();
  pantalla.fillScreen(NEGRO);
  apaga_leds(1);
  pantalla.setTextSize(2);
  pantalla.setTextColor(VERDE);
  pantalla.setCursor(10, 10);
  pantalla.print("Simon");
  pantalla.setTextColor(BLANCO);
  pantalla.setCursor(0, 40);
  pantalla.print("record= ");
  pantalla.print(EEPROM.read(14));
  delay(3000);
  vidas = 1;
  vacia_almacen();
  pantalla_simon();
  int pulsaciones_simon = 0;
  while (vidas > 0)
  {
    leds_simon();
    delay(1000);
    nuevo_movimiento();
    pantalla.fillRect(0,0,128,10,ROJO);
    pantalla.fillRect(0,118,128,10,ROJO);
    muestra_movimientos();
    
    pantalla_simon();
    pantalla.fillRect(0,0,128,10,VERDE);
    pantalla.fillRect(0,118,128,10,VERDE);
    replica_jugador();
  }
  apaga_leds(1);
  pantalla.fillScreen(NEGRO);
  final(puntero_almacen-1, 5);// Por un tema :P con ese 5 va a eeprom 14... cosas de la vida

}

void pantalla_simon()
{
  pantalla.fillScreen(NEGRO);
  pantalla.setTextSize(4);
  pantalla.setTextColor(VERDE);
  pantalla.setCursor(40, 50);
  if(puntero_almacen < 10)
  {
    pantalla.print(" ");
  }
  pantalla.print(puntero_almacen);

}

void replica_jugador()
{
  int posicion_color = 0;
  int fallo_simon = 0;
  while (almacen[posicion_color] > 0 && fallo_simon == 0)
  {
    byte acierto = almacen[posicion_color];
    byte respuesta = boton_pulsado();
    while (respuesta == 100)
    {
      respuesta = boton_pulsado();
      delay(20);

    }
    pita();
    leds_simon();
    switch (respuesta)
    {
      case 1:
        leds_simon();
        led.setPixelColor(1, led.Color(0, 255, 0));
        break;
      case 3:
        leds_simon();
        led.setPixelColor(3, led.Color(255, 255, 0));
        break;
      case 5:
        leds_simon();
        led.setPixelColor(5, led.Color(255, 0, 0));
        break;
      case 7:
        leds_simon();
        led.setPixelColor(7, led.Color(0, 0, 255));
        break;
    }
    led.show();
    delay(200);
    leds_simon();
    led.show();
    if ((respuesta == 1 &&acierto ==1)||(respuesta == 3&& acierto ==2)||(respuesta == 5 &&acierto ==3)||(respuesta == 7 &&acierto ==4))
    {
      posicion_color += 1;

    }
    else
    {
      sonido_fail();
      fallo_simon = 1;
      vidas-=1;
      pantalla_simon();
    }
  }
    pantalla.fillRect(0,0,128,10,ROJO);
    pantalla.fillRect(0,118,128,10,ROJO);
  delay(2000);
}

void nuevo_movimiento()
{
  randomSeed(millis());
  int aleatorio = random(1, 5); // 1,2,3,4
  almacen[puntero_almacen] = aleatorio;
  puntero_almacen += 1;
}

void muestra_movimientos()
{
  int posicion_color = 0;
  while (almacen[posicion_color] > 0)
  {
    int actual = almacen[posicion_color];
    {
      apaga_leds(1);

      switch (actual)
      {
        case 1:
          leds_simon();
          led.setPixelColor(1, led.Color(0, 255, 0));
          break;
        case 2:
          leds_simon();
          led.setPixelColor(3, led.Color(255, 255, 0));
          break;
        case 3:
          leds_simon();
          led.setPixelColor(5, led.Color(255, 0, 0));
          break;
        case 4:
          leds_simon();
          led.setPixelColor(7, led.Color(0, 0, 255));
          break;
      }
      posicion_color += 1;
      led.show();
      pita();
      delay(600 - 15 * puntero_almacen);
      apaga_leds(1);
      leds_simon();
      led.show();
      delay(200- 5 * puntero_almacen);

    }
  }

}


void leds_simon()
{
  led.setPixelColor(1, led.Color(0, brillo, 0));
  led.setPixelColor(3, led.Color(brillo, brillo, 0));
  led.setPixelColor(5, led.Color(brillo,0, 0));
  led.setPixelColor(7, led.Color(0, 0, brillo));
}
