#include "Balanca_HX711.h"

// Constantes de calibração baseadas no seu projeto original [cite: 99]
const float fatorCalibracao = 2280.0; 
const long valorZero = 463392; 

void Balanca_Init(HX711 *_balanca, int _pinDT, int _pinSCK, LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2) {
    _lcd1->init(); _lcd1->backlight();
    _lcd2->init(); _lcd2->backlight();
    
    _balanca->begin(_pinDT, _pinSCK);
    
    _lcd1->setCursor(0,0);
    _lcd1->print("BALANCA PRONTA");
}

void Balanca_Update(HX711 *_balanca, LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2) {
    long leituraAtual = _balanca->read();
    
    // Cálculo do peso corrigido [cite: 102]
    float pesoCalculado = (float)(leituraAtual - valorZero) / fatorCalibracao;
    
    // Filtro de ruído para valores próximos a zero [cite: 104]
    if(pesoCalculado < 0.05 && pesoCalculado > -0.05) pesoCalculado = 0.00;

    // Atualização do LCD 1 (Peso Corrigido) [cite: 103-105]
    _lcd1->setCursor(0, 0);
    _lcd1->print("BALANCA DIGITAL ");
    _lcd1->setCursor(0, 1);
    _lcd1->print("PESO: ");
    _lcd1->print(pesoCalculado, 2);
    _lcd1->print(" kg      ");

    // Atualização do LCD 2 (Monitoramento Bruto) [cite: 106-107]
    _lcd2->setCursor(0, 0);
    _lcd2->print("VALOR BRUTO:    ");
    _lcd2->setCursor(0, 1);
    _lcd2->print("RAW: ");
    _lcd2->print(leituraAtual);
    _lcd2->print("         ");
}
