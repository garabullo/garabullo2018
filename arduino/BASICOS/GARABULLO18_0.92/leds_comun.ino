void apaga_leds(boolean muestra) //apaga todos los leds escepto el de la batería
{
  for (int i = 0; i < 9; i++)
  {
    led.setPixelColor(i, led.Color(0, 0, 0));
    if(muestra)
    {
      led.show();
    }
  }
}

void apaga_led_bateria() //funcion que hace eso mismo... claro
{
  led.setPixelColor(9, led.Color(0, 0, 0));
  led.show();
}


void leds_amarillo() //apaga todos los leds escepto el de la batería
{
  for (int i = 0; i < 9; i++)
  {
    led.setPixelColor(i, led.Color(brillo / 2, brillo, 0));
  }
        led.show();
}
