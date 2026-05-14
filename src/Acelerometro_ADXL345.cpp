#include "Acelerometro_ADXL345.h"

bool ADXL345_Init(Adafruit_ADXL345_Unified *_accel, LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2) {
    _lcd1->init(); 
    _lcd1->backlight();
    _lcd2->init(); 
    _lcd2->backlight();

    if(!_accel->begin()) {
        _lcd1->setCursor(0,0);
        _lcd1->print("ERRO ADXL345");
        return false;
    }

    _accel->setRange(ADXL345_RANGE_16_G); // Define o range conforme original [cite: 95]
    return true;
}

void ADXL345_ReadAndDisplay(Adafruit_ADXL345_Unified *_accel, LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2) {
    sensors_event_t event; 
    _accel->getEvent(&event);

    // Display 1: Eixos X e Y [cite: 97]
    _lcd1->setCursor(0,0); 
    _lcd1->print("X: "); 
    _lcd1->print(event.acceleration.x);
    _lcd1->setCursor(0,1);
    _lcd1->print("Y: "); 
    _lcd1->print(event.acceleration.y);

    // Display 2: Eixo Z
    _lcd2->setCursor(0,0); 
    _lcd2->print("EIXO Z:");
    _lcd2->setCursor(0,1); 
    _lcd2->print(event.acceleration.z);
    _lcd2->print(" m/s^2");
}
