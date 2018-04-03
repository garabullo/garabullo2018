boolean test_tiempo_suficiente()
{
  tiempo_actual = millis();
  medida_tiempo = (tiempo_actual - tiempo_inicio) / 1000; //esta variable se usa para la longitud de la barra de tiempo
  if (tiempo_actual - tiempo_inicio > 120000)
  {
    return 0;
  }
  else return 1;
}


void muestra_barra_crono()
{
  pantalla.fillRect(4, 72, 120 - medida_tiempo, 10, ST7735_GREEN);
  pantalla.fillRect(124 - medida_tiempo, 72, medida_tiempo , 10, ST7735_BLACK);
}

