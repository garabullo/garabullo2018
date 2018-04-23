// la variable sonido_activado hace que cualquier sonido esté activado o no
// escepto el sonido_alive porque lo que marca es que lo dejamos encendido
// el sonido alive se mantiene siempre como protección de descarga de batería
void pita()
{
  if (sonido_activado)
  {
    tone (buzzer , 500, 200);
  }
}
void sonido_acierto() // cada vez que en un juego
{
  if (sonido_activado)
  {
    tone(buzzer, 500, 100);
    delay(150);
    tone(buzzer, 1000, 100);
    delay(150);
    tone(buzzer, 2000, 200);
    delay(600);
  }
}
void sonido_alive()
{
  tone(buzzer, 500, 100);
  delay(150);
  tone(buzzer, 1000, 100);
  delay(150);
}

void sonido_fail()
{
  if (sonido_activado)
  {
    tone(buzzer, 500, 1000);
    delay(1100);
  }
}

