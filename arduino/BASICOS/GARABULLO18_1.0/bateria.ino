// función que lee el pin de la batería y muestra el nivel en el led de esta.
void bateria()
{
  int nivel_bateria = analogRead(pin_bateria);
  if (nivel_bateria > 720)
  {
  led.setPixelColor(9, led.Color(0, 10, 0));
  }
  else if (nivel_bateria > 600)
  {
  led.setPixelColor(9, led.Color(4, 6, 0));
  }
  else
  {
    led.setPixelColor(9, led.Color(10, 0, 0));
  }
  led.show();
}
//función que testea que no se ha pulsado nada en 1 minuto y avisa de que está encendido
void test_alive()
{
  if ( ( (millis() - tiempo_ultimo_evento)) > 60000)
  {
    sonido_alive();
    tiempo_ultimo_evento = millis();
    delay(5);
  }
}
// función para apagar el led de la batería cuando se entra en un juego y no despisten los colores
void apaga_bateria()
{
  led.setPixelColor(9, led.Color(0, 0, 0));
  led.show();
}
