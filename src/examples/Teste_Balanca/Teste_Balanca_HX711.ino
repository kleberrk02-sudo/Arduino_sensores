#include "Balanca_HX711.h"

// Definições de hardware [cite: 98, 100]
const int pinoDT = A1;
const int pinoSCK = A0;
HX711 balanca;
LiquidCrystal_I2C lcd1(0x27, 16, 2); 
LiquidCrystal_I2C lcd2(0x20, 16, 2);

void setup() {
    Balanca_Init(&balanca, pinoDT, pinoSCK, &lcd1, &lcd2);
}

void loop() {
    Balanca_Update(&balanca, &lcd1, &lcd2);
    delay(250);
}
