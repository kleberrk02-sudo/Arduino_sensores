#include "Sensor_Distancia.h"

void Distancia_Init(int _pinoTrig, int _pinoEcho, LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2) {
    pinMode(_pinoTrig, OUTPUT);
    pinMode(_pinoEcho, INPUT);
    digitalWrite(_pinoTrig, LOW); // Garante estado inicial [cite: 111]

    _lcd1->init(); 
    _lcd1->backlight();
    _lcd2->init(); 
    _lcd2->backlight();

    _lcd1->setCursor(0,0);
    _lcd1->print("HC-SR04 PIN 2/3");
}

void Distancia_Update(int _pinoTrig, int _pinoEcho, LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2) {
    // Sequência de disparo do pulso ultrassónico [cite: 112-113]
    digitalWrite(_pinoTrig, LOW);
    delayMicroseconds(2);
    digitalWrite(_pinoTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(_pinoTrig, LOW);

    // Leitura do tempo de retorno (Echo) [cite: 114]
    long duracao = pulseIn(_pinoEcho, HIGH, 40000); 

    if (duracao > 0) {
        // Cálculo da distância em cm [cite: 115]
        float distancia = (duracao * 0.0343) / 2;

        // Atualização do LCD 1 (Distância) [cite: 116]
        _lcd1->setCursor(0, 1);
        _lcd1->print("DIST: ");
        _lcd1->print(distancia, 1);
        _lcd1->print(" cm      ");

        // Atualização do LCD 2 (Tempo Bruto) [cite: 116-117]
        _lcd2->setCursor(0, 1);
        _lcd2->print("ECHO: ");
        _lcd2->print(duracao);
        _lcd2->print(" us    ");
    } else {
        _lcd1->setCursor(0, 1);
        _lcd1->print("AGUARDANDO...  "); [cite: 118]
    }
}
