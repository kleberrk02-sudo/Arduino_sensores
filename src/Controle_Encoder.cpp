#include "Controle_Encoder.h"

// Variáveis internas para controle [cite: 251]
volatile int contador = 0;
String sentido = "Parado"; 
int estadoAnteriorA;
int pinoA_local, pinoB_local;

void Encoder_Init(int _pinA, int _pinB, int _pinBT, LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2) {
    pinoA_local = _pinA;
    pinoB_local = _pinB;
    
    pinMode(_pinA, INPUT);
    pinMode(_pinB, INPUT);
    pinMode(_pinBT, INPUT_PULLUP);

    _lcd1->init(); _lcd1->backlight();
    _lcd2->init(); _lcd2->backlight();

    _lcd1->setCursor(0, 0);
    _lcd1->print("CONTROLE ENCODER");
    _lcd2->setCursor(0, 0);
    _lcd2->print("STATUS GIRO:");

    estadoAnteriorA = digitalRead(_pinA);
    attachInterrupt(digitalPinToInterrupt(_pinA), ISR_AtualizarEncoder, CHANGE);
}

void ISR_AtualizarEncoder() {
    int estadoA = digitalRead(pinoA_local);
    if (estadoA != estadoAnteriorA) {
        if (digitalRead(pinoB_local) != estadoA) {
            contador--;
            sentido = "ANTI-HORARIO";
        } else {
            contador++;
            sentido = "HORARIO     ";
        }
    }
    estadoAnteriorA = estadoA;
}

void Encoder_UpdateDisplay(LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2) {
    _lcd1->setCursor(0, 1);
    _lcd1->print("VALOR: ");
    _lcd1->print(contador);
    _lcd1->print("     "); 

    _lcd2->setCursor(0, 1);
    _lcd2->print("DIR: ");
    _lcd2->print(sentido);
    _lcd2->print("   ");
}

void Encoder_CheckReset(int _pinBT) {
    if (digitalRead(_pinBT) == LOW) {
        contador = 0;
        sentido = "RESET!      ";
        delay(200); 
    }
}
