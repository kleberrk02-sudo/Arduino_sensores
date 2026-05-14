#include "Controle_Encoder.h"

const int pinA = 2; 
const int pinB = 3;
const int pinBT = 4;

LiquidCrystal_I2C lcd1(0x27, 16, 2); 
LiquidCrystal_I2C lcd2(0x20, 16, 2);

void setup() {
    Encoder_Init(pinA, pinB, pinBT, &lcd1, &lcd2);
}

void loop() {
    Encoder_UpdateDisplay(&lcd1, &lcd2);
    Encoder_CheckReset(pinBT);
    delay(50);
}
