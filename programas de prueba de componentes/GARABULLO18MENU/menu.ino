String menu_principal[] = {"ROBOT", "JUEGOS", "RECORDS", "AJUSTES"};

void menu()
{
    pantalla.fillScreen(ST7735_BLACK);
    pantalla.setTextSize(3);
    
    pantalla.setCursor(20, 5);
    pantalla.setTextColor(ST7735_WHITE,ST7735_BLUE);
    pantalla.print(menu_principal[0]);

    pantalla.setCursor(12, 47);
    pantalla.setTextColor(ST7735_WHITE,ST7735_MAGENTA);
    pantalla.print(menu_principal[1]);

    pantalla.setCursor(0, 89);
    pantalla.setTextColor(ST7735_WHITE,ST7735_RED);
    pantalla.print(menu_principal[3]);


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

