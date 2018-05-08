
#include <EEPROM.h>

void setup() {

  if (EEPROM.read(0) != 1) // si la posicion cero de la eeprom es diferente de uno...
  {
    EEPROM.write(0, 1);  // ... fija a uno el valor de la variable del sonido.
  }

  if (EEPROM.read(1) != 78) // posicion de pasos recto
  {
    EEPROM.write(1, 78);// por defecto arranca en 77
  }
  
  if (EEPROM.read(2) !=54) // posicion de pasos giro
  {
    EEPROM.write(2, 54);// por defecto arranca en 53
  }

  for (int i = 11 ; i < EEPROM.length() ; i++)
  {
    if (EEPROM.read(i) != 0)
    {
      EEPROM.write(i, 0);
    }
  }
}

void loop() {

}
