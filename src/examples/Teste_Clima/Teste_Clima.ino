#include "Clima_BMP180.h"

Adafruit_BMP085 bmp;
LiquidCrystal_I2C lcd1(0x27, 16, 2); 
LiquidCrystal_I2C lcd2(0x20, 16, 2); 

void setup() {
    if(!BMP180_Init(&bmp, &lcd1, &lcd2)) {
        while(1); 
    }
}

void loop() {
    BMP180_UpdateDisplay(&bmp, &lcd1, &lcd2);
    delay(1000);
}
