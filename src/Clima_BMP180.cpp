#include "Clima_BMP180.h"

bool BMP180_Init(Adafruit_BMP085 *_bmp, LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2) {
    _lcd1->init(); _lcd1->backlight();
    _lcd2->init(); _lcd2->backlight();
    
    _lcd1->setCursor(0, 0); _lcd1->print("SISTEMA TERMICO");
    _lcd2->setCursor(0, 0); _lcd2->print("SISTEMA BAROM.");
    
    delay(1000); // Aguarda estabilização

    if (!_bmp->begin()) {
        _lcd1->clear(); _lcd1->print("ERRO: SENSOR");
        return false;
    }
    return true;
}

void BMP180_UpdateDisplay(Adafruit_BMP085 *_bmp, LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2) {
    // Leitura dos dados do sensor
    float temp = _bmp->readTemperature();
    int32_t pressao = _bmp->readPressure();

    // Atualização do LCD 1 (Temperatura)
    _lcd1->setCursor(0, 1);
    _lcd1->print("TEMP: ");
    _lcd1->print(temp, 1);
    _lcd1->print(" C      ");

    // Atualização do LCD 2 (Pressão em Pa)
    _lcd2->setCursor(0, 1);
    _lcd2->print("PRES: ");
    _lcd2->print(pressao);
    _lcd2->print(" Pa  ");
}
