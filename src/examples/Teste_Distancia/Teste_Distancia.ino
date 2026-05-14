#include "Sensor_Distancia.h"

// Pinos conforme configuração no simulador [cite: 108-109]
const int trig = 2;
const int echo = 3;

LiquidCrystal_I2C lcd1(0x27, 16, 2); 
LiquidCrystal_I2C lcd2(0x20, 16, 2);

void setup() {
    Distancia_Init(trig, echo, &lcd1, &lcd2);
}

void loop() {
    Distancia_Update(trig, echo, &lcd1, &lcd2);
    delay(200); // Estabilidade para o simulador [cite: 118]
}
