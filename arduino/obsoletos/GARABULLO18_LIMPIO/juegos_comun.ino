// la función limpia_eeprom() busca en las posiciones reservadas a los records
// valores de 255 que son los que están al principio en estas posiciones si no se han usado
// De la posición 10 hasta la 29
// si hay un valor diferente no lo cambia
// la variable pasada como argumento "forzado" si es 1 es porque desde el menú de ajustes se fuerza a borrar
void limpia_eeprom(boolean forzado)
{
  for (int i = 10; i < 30; i++)
  if (EEPROM.read(i) == 255 || forzado) 
  {
    EEPROM.write(i, 0);
  }
  if (EEPROM.read(0) == 255) // posición de sonido activado, si es la primera vez que se usa se activa, si no se deja como está
  {
    EEPROM.write(0, 1);
  }
}

