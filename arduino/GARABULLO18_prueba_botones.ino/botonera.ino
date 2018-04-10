int boton_pulsado()
{
  if (analogRead (botonera1) > 50)
  {
    delay(20); // espera 1ms para estabilizar la lectura
    int lectura_actual = analogRead(botonera1);
    pita();
    debounce();
    if (abs(lectura_actual - lectura_boton_0) < umbral)
    {
      return 0;
    }
    else if (abs(lectura_actual - lectura_boton_1) < umbral)
    {
      return 1;
    }
    else if (abs(lectura_actual - lectura_boton_2) < umbral)
    {
      return 2;
    }
    else if (abs(lectura_actual - lectura_boton_3) < umbral)
    {
      return 3;
    }
    else if (abs(lectura_actual - lectura_boton_4) < umbral)
    {
      return 4;
    }
  }
  else if (analogRead (botonera2) > 50)
  {
    delay(20); // espera 1ms para estabilizar la lectura
    int lectura_actual = analogRead(botonera2);
    pita();
    debounce();
    if (abs(lectura_actual - lectura_boton_5) < umbral)
    {
      return 5;
    }
    else if (abs(lectura_actual - lectura_boton_6) < umbral)
    {
      return 6;
    }
    else if (abs(lectura_actual - lectura_boton_7) < umbral)
    {
      return 7;
    }
    else if (abs(lectura_actual - lectura_boton_8) < umbral)
    {
      return 8;
    }
  }
  else return 100;
  
  
}

void debounce()
{
  int contador = 0;
  while (contador < 10)
  {
    int lectura_botonera1 = analogRead(botonera1);
    int lectura_botonera2 = analogRead(botonera2);
    if (lectura_botonera1 < 50 && lectura_botonera2 < 50)
    {
      contador += 1;
    }
    else
    {
      contador = 0;
    }
    delayMicroseconds(500);
  }
}
int prueba_lectura()
{
  if (analogRead (botonera1) > 50)
  {
    return analogRead (botonera1);
  }
  else if (analogRead (botonera2) > 50)
  {
    return analogRead (botonera2);
  }
  else return 0;
}

