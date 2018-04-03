void pita()
{
  tone (buzzer , 500, 200);
}
void sonido_acierto()
{
  tone(buzzer, 500, 100);
  delay(150);
  tone(buzzer,1000, 100);
  delay(150);
  tone(buzzer, 2000, 200);
  delay(600);
}

