#include "Termometro_NTC.h"

// Função de inicialização [cite: 87-88]
void NTC_Init(LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2) {
    _lcd1->init(); 
    _lcd1->backlight();
    _lcd2->init(); 
    _lcd2->backlight();

    _lcd1->setCursor(0,0);
    _lcd1->print("TERMOMETRO NTC");
    _lcd2->setCursor(0,0);
    _lcd2->print("LEITURA ADC:");
}

// Função de leitura e processamento [cite: 89-97]
void NTC_ReadAndDisplay(int _pin, LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2) {
    int valorADC = analogRead(_pin);
    if (valorADC >= 1023) valorADC = 1022; // Evita divisão por zero [cite: 91]

    // Parâmetros do sensor conforme sua configuração original [cite: 90-91]
    const float beta = 3380.0;
    const float resistenciaNominal = 10000.0;
    const float tempNominalK = 25.0 + 273.15; 
    
    // Cálculo da resistência para o divisor de tensão do simulador [cite: 92]
    float resistencia = resistenciaNominal * ((float)valorADC / (1023.0 - (float)valorADC));
    
    // Equação Beta para conversão de temperatura [cite: 93]
    float temperaturaK;
    temperaturaK = log(resistencia / resistenciaNominal);
    temperaturaK = (1.0 / tempNominalK) + (temperaturaK / beta);
    temperaturaK = 1.0 / temperaturaK;
    
    float temperaturaC = temperaturaK - 273.15; // Conversão para Celsius [cite: 94]

    // Atualização dos displays com os resultados [cite: 95-97]
    _lcd1->setCursor(0, 1);
    _lcd1->print("TEMP: ");
    _lcd1->print(temperaturaC, 1);
    _lcd1->print(" C     ");

    _lcd2->setCursor(0, 1);
    _lcd2->print("VALOR: ");
    _lcd2->print(valorADC);
    _lcd2->print("       ");
}
