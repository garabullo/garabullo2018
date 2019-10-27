void cuadros()
{
  apaga_leds(1);
  cargando(5);
  puntero_almacen = 0;
  boolean salida = 0;
  boolean bandera_cartel_borrado = 0;
  pantalla_inicio_cuadros();
  while (almacen[puntero_almacen])
  {
    puntero_almacen += 1;
  }
  marca_movimientos();
  while (!salida)
  {
    test_alive();
    delay(10);
    int boton = boton_pulsado();
    switch (boton)
    {
      case 0:
        if (puntero_almacen > 0)
        {
          vacia_almacen();
          marca_movimientos();
          bandera_cartel_borrado = 0;
          pantalla.setTextSize(2);
          pantalla.setCursor(0, 0);
          pantalla.setTextColor(AMARILLO, ROJO);
          pantalla.print("SALIR");
        }
        else
        {
          salida = 1;
        }
        break;
      case 1:
        almacen[puntero_almacen] = 1; // el 1 almacena movimiento recto
        puntero_almacen += 1;
        marca_movimientos();
        break;

      case 2:
        almacen[puntero_almacen] = 5; // el 5 almacena una pausa
        puntero_almacen += 1;
        marca_movimientos();
        break;

      case 3:
        almacen[puntero_almacen] = 4; // el 4 almacena una movimiento izquierda
        puntero_almacen += 1;
        marca_movimientos();
        break;

      case 4:
        arranca_chofer(); // al pulsar el botón central empieza los movimientos
        //salida = 1;
        delay(1000);
        sonido_acierto();
        delay(1000);
        leds_cuadros();
        tiempo_ultimo_evento = millis();
        break;

      case 5:
        almacen[puntero_almacen] = 2; // el 2 almacena una movimiento derecha
        puntero_almacen += 1;
        marca_movimientos();
        break;
      case 7:
        almacen[puntero_almacen] = 3; // el 2 almacena una movimiento derecha
        puntero_almacen += 1;
        marca_movimientos();
        break;
    }
    if (bandera_cartel_borrado == 0 && puntero_almacen > 0)
    {
      pantalla.setTextSize(2);
      pantalla.setCursor(0, 0);
      pantalla.setTextColor(AMARILLO, ROJO);
      pantalla.print("BORRA");
      bandera_cartel_borrado = 1;
    }

  }
}
void pantalla_inicio_cuadros()
{
  pantalla.fillScreen(NEGRO);
  pantalla.setTextSize(3);
  pantalla.setCursor(0, 0);
  pantalla.setTextColor(BLANCO, AZUL);
  //pantalla.print("CUADROS");
  pantalla.setTextColor(VERDE);
  pantalla.setTextSize(5);
  pantalla.setCursor(50, 20); //arriba
  pantalla.write(24);
  pantalla.setCursor(50, 90); //abajo
  pantalla.write(25);
  pantalla.setCursor(10, 58); //izquierda
  pantalla.write(27);
  pantalla.setCursor(90, 58); //derecha
  pantalla.write(26);
  pantalla.setTextColor(AZUL);
  pantalla.setCursor(53, 58); //centro play
  pantalla.write(175);

  pantalla.setTextSize(2);
  pantalla.setCursor(0, 0);
  pantalla.setTextColor(AMARILLO, ROJO);
  pantalla.print("SALIR");

  pantalla.setCursor(65, 0);
  pantalla.setTextColor(ROJO, AMARILLO);
  pantalla.print("PAUSA");
  leds_cuadros();


}
void todos_juntos()
{
  for (int i = 0; i < 255; i ++)
  {
    pantalla.fillScreen(NEGRO);
    pantalla.setTextSize(5);
    pantalla.setCursor(10, 10);
    pantalla.setTextColor(AZUL);
    pantalla.write(i);
    pantalla.setCursor(10, 50);
    pantalla.print(i);
    delay(1000);
  }
}

void test_movimientos()
{
  bateria();
  apaga_leds(1);
  delay(1000);
  for (int i = 0; i < 2; i++)
  {
    adelante();
    delay(500);
    derecha();
    delay(500);
    izquierda();
    delay(500);
    atras();
    delay(500);
  }
  delay(1000);
  sonido_acierto();
  pantalla.fillScreen(NEGRO);
}

void arranca_chofer()
{
  puntero_almacen = 0;
  apaga_leds(1);
  delay(1000);
  while (almacen[puntero_almacen] != 0)
  {
    switch (almacen[puntero_almacen])
    {
      case 1:
        adelante();
        break;

      case 2:
        derecha();
        break;

      case 3:
        atras();
        break;

      case 4:
        izquierda();
        break;

      case 5:
        delay(2000);
        pita();
        break;

    }
    puntero_almacen += 1;
  }
}

void marca_movimientos()
{
  pantalla.fillRect(100, 110, 30, 15, NEGRO);
  pantalla.setTextSize(2);
  pantalla.setCursor(100, 110);
  pantalla.setTextColor(VERDE);
  if (puntero_almacen < 10)
  {
    pantalla.print(" ");
  }
  pantalla.print(puntero_almacen);
}

void vacia_almacen()
{
  for (int i = 0; i < 100; i++)
  {
    almacen[i] = 0;
  }
  puntero_almacen = 0;
}
void leds_cuadros()
{
  apaga_leds(0);
  led.setPixelColor(0, led.Color(brillo, 0, 0)); // borrar
  led.setPixelColor(2, led.Color(brillo, brillo, 0)); // pausa
  led.setPixelColor(1, led.Color(0, brillo, 0));
  led.setPixelColor(3, led.Color(0, brillo, 0));
  led.setPixelColor(5, led.Color(0, brillo, 0));
  led.setPixelColor(7, led.Color(0, brillo, 0));
  led.setPixelColor(4, led.Color(0, 0, brillo));
  led.show();
}
