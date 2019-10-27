
int paso [8][4] =
{
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};
 
void adelante()
{
  for (int pasos = 0; pasos < pasos_recto; pasos++)
  {
    int aceleracion;
    if (pasos < 20)
    {
      aceleracion = acelera(pasos); 
    }
    else if ((pasos_recto - pasos) < 20)
    {
      aceleracion = decelera(pasos_recto - pasos); 
    }
    else aceleracion= 0;
    for (int i = 7; i >= 0; i--)
    {
      
      digitalWrite(IN1d, paso[i][0]);
      digitalWrite(IN2d, paso[i][1]);
      digitalWrite(IN3d, paso[i][2]);
      digitalWrite(IN4d, paso[i][3]);
      
      digitalWrite(IN1i, paso[i][0]);
      digitalWrite(IN2i, paso[i][1]);
      digitalWrite(IN3i, paso[i][2]);
      digitalWrite(IN4i, paso[i][3]);
      
      delayMicroseconds(tiempoEntrePaso + aceleracion);
    }
  }
  pita();
}
void atras()
{
  
  for (int pasos = 0; pasos < pasos_recto; pasos++)
  {
    int aceleracion;
    if (pasos < 20)
    {
      aceleracion = acelera(pasos); 
    }
    if ((pasos_recto - pasos) < 20)
    {
      aceleracion = decelera(pasos_recto - pasos); 
    }
    for (int i = 0; i < 8; i++)
    {
      digitalWrite(IN1d, paso[i][0]);
      digitalWrite(IN2d, paso[i][1]);
      digitalWrite(IN3d, paso[i][2]);
      digitalWrite(IN4d, paso[i][3]);
      digitalWrite(IN1i, paso[i][0]);
      digitalWrite(IN2i, paso[i][1]);
      digitalWrite(IN3i, paso[i][2]);
      digitalWrite(IN4i, paso[i][3]);
      delayMicroseconds(tiempoEntrePaso + aceleracion);
      
    }
  }
  pita();
}

void izquierda()
{
  
  for (int pasos = 0; pasos < pasosGiro; pasos++)
  {
    int aceleracion;
    if (pasos < 20)
    {
      aceleracion = acelera(pasos); 
    }
    if ((pasosGiro - pasos) < 20)
    {
      aceleracion = decelera(pasosGiro - pasos); 
    }
    for (int i = 7; i >= 0; i--)
    {
      digitalWrite(IN1d, paso[i][0]);
      digitalWrite(IN2d, paso[i][1]);
      digitalWrite(IN3d, paso[i][2]);
      digitalWrite(IN4d, paso[i][3]);
      digitalWrite(IN1i, paso[7-i][0]);
      digitalWrite(IN2i, paso[7-i][1]);
      digitalWrite(IN3i, paso[7-i][2]);
      digitalWrite(IN4i, paso[7-i][3]);
      delayMicroseconds(tiempoEntrePaso + aceleracion);
    }
  }
  pita();
}

void derecha()
{
  for (int pasos = 0; pasos < pasosGiro; pasos++)
  {
    int aceleracion;
    if (pasos < 20)
    {
      aceleracion = acelera(pasos); 
    }
    if ((pasosGiro - pasos) < 20)
    {
      aceleracion = decelera(pasosGiro - pasos); 
    }
    for (int i = 7; i >= 0; i--)
    {
      digitalWrite(IN1d, paso[7-i][0]);
      digitalWrite(IN2d, paso[7-i][1]);
      digitalWrite(IN3d, paso[7-i][2]);
      digitalWrite(IN4d, paso[7-i][3]);
      digitalWrite(IN1i, paso[i][0]);
      digitalWrite(IN2i, paso[i][1]);
      digitalWrite(IN3i, paso[i][2]);
      digitalWrite(IN4i, paso[i][3]);
      delayMicroseconds(tiempoEntrePaso + aceleracion);
    }
  }
  pita();
}

void apaga_motores()
{
  digitalWrite(IN1d, LOW);
  digitalWrite(IN2d, LOW);
  digitalWrite(IN3d, LOW);
  digitalWrite(IN4d, LOW);
  digitalWrite(IN1i, LOW);
  digitalWrite(IN2i, LOW);
  digitalWrite(IN3i, LOW);
  digitalWrite(IN4i, LOW);
}
int acelera (int paso_que_pasa)
{
  return (tiempoEntrePaso / 10) * (20 - paso_que_pasa);
}

int decelera (int paso_que_pasa)
{
  return (tiempoEntrePaso / 10) * (20 - paso_que_pasa);
}

