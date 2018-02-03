//umbral lecturas 
int umbral = 30;

//lecturas tipo de cada boton
//empieza a contar desde cero para coincidir con los leds
// y así hacer más fácil la programación led-pulsador-onda-corpúsculo ;)
int lectura_boton_0 = 786;
int lectura_boton_1 = 601; 
int lectura_boton_2 = 443; 
int lectura_boton_3 = 299; 
int lectura_boton_4 = 156; 

int lectura_boton_5 = 759; 
int lectura_boton_6 = 549; 
int lectura_boton_7 = 364; 
int lectura_boton_8 = 188; 


// esta variable almacena el brillo inicial. Es modificable mediante el menu de configuración
byte brillo = 25;

int tiempoEntrePaso = 1500;
/****************************Variables pasosRecto y pasosGiro**************************************
   En pasosRecto se debe almacenar el número de pasos que necesita GARABULLO para avanzar un cuadro
   En pasosGiro se debe almacenar el número de pasos que necesita GARABULLO para girar 90º
*/
int pasos_recto = 400;
int pasosGiro = 240;
/**************************Variables relaccionadas con botonera analógica**************************
*/
// matriz pare el juego de baldosas... e o que cumpra
int matriz[9];

boolean tiempo_suficiente;
long tiempo_actual;
long tiempo_inicio;
long medida_tiempo;

int puntuacion;
