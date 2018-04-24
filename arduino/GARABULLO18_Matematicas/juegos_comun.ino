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
  if (EEPROM.read(1) == 255) // posicion de pasos recto
  {
    EEPROM.write(1, 78);// por defecto arranca en 77
  }
  if (EEPROM.read(2) == 255) // posicion de pasos giro
  {
    EEPROM.write(2, 54);// por defecto arranca en 53
  }
  
  pasos_recto = EEPROM.read(1);
  pasos_giro = EEPROM.read(2);
}


// Posiciones de eeprom
/*
 * EEPROM 0 SONIDO ACTIVADO
 * EEPROM 11 MAGIC TILES 1
 * EEPROM 12 MAGIC TILES 2
 * 
 * 
 * 
 * 
 * 
 * 
 */
