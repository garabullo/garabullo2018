String menu_principal[] = {"ROBOT", "JUEGOS", "RECORDS", "AJUSTES"};
String string1 =" pulsa un boton para  ver su   valor en  pantalla ";

void menu()
{
    //pantalla.fillScreen(ST7735_BLACK);
    pantalla.setTextSize(2);
    
    pantalla.setCursor(0, 5);
    pantalla.setTextColor(ST7735_WHITE,ST7735_BLUE);
    pantalla.print(string1);
    pantalla.drawRoundRect(25,90,70,30,5,ST7735_BLUE);
    pantalla.drawRoundRect(24,89,72,32,6,ST7735_BLUE);
    int lectura =  prueba_lectura();
    if (lectura > 0)
    {
      pantalla.fillRect(27,92,66,26,ST7735_BLACK);
      pantalla.setCursor(35, 95);
      pantalla.setTextColor(ST7735_WHITE);
      pantalla.setTextSize(3);
      pantalla.print(lectura);
      delay(100);
    }
    else
    {
      pantalla.fillRect(27,92,66,26,ST7735_BLACK);
      delay(5);
    }
    /*pantalla.setCursor(12, 47);
    pantalla.setTextColor(ST7735_WHITE,ST7735_MAGENTA);
    pantalla.print(menu_principal[1]);

    pantalla.setCursor(0, 89);
    pantalla.setTextColor(ST7735_WHITE,ST7735_RED);
    pantalla.print(menu_principal[3]);

*/
    led.setPixelColor(1, led.Color(0,0,brillo));
    led.setPixelColor(4, led.Color(brillo/2,0,brillo));
    led.setPixelColor(6, led.Color(brillo,0,0));
    led.setPixelColor(0, led.Color(0,0,brillo));
    led.setPixelColor(3, led.Color(brillo/2,0,brillo));
    led.setPixelColor(7, led.Color(brillo,0,0));
    led.setPixelColor(2, led.Color(0,0,brillo));
    led.setPixelColor(5, led.Color(brillo/2,0,brillo));
    led.setPixelColor(8, led.Color(brillo,0,0));
    led.show();
    
}

