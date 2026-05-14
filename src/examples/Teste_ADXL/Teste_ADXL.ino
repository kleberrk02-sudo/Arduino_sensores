#include "Acelerometro_ADXL345.h"

// Instâncias conforme seu código original [cite: 93-94]
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
LiquidCrystal_I2C lcd1(0x27, 16, 2);
LiquidCrystal_I2C lcd2(0x20, 16, 2);

void setup() {
    // Inicialização modular
    if(!ADXL345_Init(&accel, &lcd1, &lcd2)) {
        while(1); 
    }
}

void loop() {
    // Leitura e atualização modular
    ADXL345_ReadAndDisplay(&accel, &lcd1, &lcd2);
    delay(500);
}
