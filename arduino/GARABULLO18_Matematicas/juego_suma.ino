void sumas()
{
  bateria();
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
  pantalla.print("record = ");
  pantalla.print(EEPROM.read(13));
  delay(3000);
  cuenta_atras(5);

  tiempo_inicio = millis();
  tiempo_actual = millis();

  while ((tiempo_actual - tiempo_inicio) < 5400)
  {
    pantalla.fillScreen(NEGRO);
    randomSeed(millis());
    int primer_numero = random(100);
    int segundo_numero = random(100);
    int acierto = random(2); // si es cero es falso, si es uno acierta
    int resultado;
    if (acierto)
    {
      resultado = primer_numero + segundo_numero;
    }
    else
    {
      int diferencia = random(1 , 20);
      int mas_menos = random(2);
      if (mas_menos)
      {
        resultado = primer_numero + segundo_numero + diferencia;
      }
      else
      {
        resultado = primer_numero + segundo_numero - diferencia;
      }
    }
    resultado = constrain(resultado, 0, 200);
    pantalla.setTextSize(4);
    pantalla.setTextColor(CYAN);
    pantalla.setCursor(50, 0);
    if(primer_numero < 10) {  pantalla.print(" ");}    
    pantalla.print(primer_numero);
    pantalla.setCursor(50, 35);
    if(segundo_numero < 10) {  pantalla.print(" ");}
    
    pantalla.print(segundo_numero);
    pantalla.setCursor(26, 35);
    pantalla.print("+");
    pantalla.fillRect(26,65,70,3, CYAN);
    pantalla.setCursor(26,70);
    if(resultado < 100)
    {
      pantalla.print(" ");
      if (resultado < 10)
      {
        pantalla.print(" ");
      }
    }
    pantalla.print(resultado);
    pantalla.setCursor(100,100);
    pantalla.print(acierto);
    delay(2000);

    
  }

}

