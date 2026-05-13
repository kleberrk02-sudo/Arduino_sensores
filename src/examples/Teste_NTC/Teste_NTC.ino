#include <Termometro_NTC.h>

// Configurações para o PICSimLab [cite: 85-86]
const int pinoNTC = A0; 
LiquidCrystal_I2C lcd1(0x27, 16, 2); 
LiquidCrystal_I2C lcd2(0x20, 16, 2);

void setup() {
    // Chama a inicialização da sua biblioteca
    NTC_Init(&lcd1, &lcd2);
}

void loop() {
    // Executa a leitura e atualização dos displays [cite: 89, 95-97]
    NTC_ReadAndDisplay(pinoNTC, &lcd1, &lcd2);
    delay(500);
}
