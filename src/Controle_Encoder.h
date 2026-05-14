/*
 ******************************************************************************
 * @file    Controle_Encoder.h
 * @brief   Biblioteca para leitura de Encoder Rotativo com interrupção e LCDs.
 ******************************************************************************
 * @attention
 *
 * Date: 13/05/2026
 * Author: Kleberson
 * Project: Biblioteca Pessoal de Automação
 * Version: 1.0
 ******************************************************************************
 */

#ifndef CONTROLE_ENCODER_H
#define CONTROLE_ENCODER_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

/*
 **************************************************************
 * @name  Encoder_Init
 * @brief Configura pinos, interrupções e inicializa os displays.
 ***************************************************************
 * @input:   _pinA   - pino A (CLK)
 * _pinB   - pino B (DT)
 * _pinBT  - pino do botão (SW)
 * *_lcd1  - display de posição
 * *_lcd2  - display de status
 * @return:  sem retorno
 */
void Encoder_Init(int _pinA, int _pinB, int _pinBT, LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2);

/*
 **************************************************************
 * @name  Encoder_UpdateDisplay
 * @brief Atualiza os valores de contador e direção nos LCDs.
 ***************************************************************
 * @input:   *_lcd1  - display de valor
 * *_lcd2  - display de direção
 * @return:  sem retorno
 */
void Encoder_UpdateDisplay(LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2);

/*
 **************************************************************
 * @name  Encoder_CheckReset
 * @brief Verifica se o botão foi pressionado para zerar o contador.
 ***************************************************************
 * @input:   _pinBT  - pino do botão
 * @return:  sem retorno
 */
void Encoder_CheckReset(int _pinBT);

// Função de interrupção (precisa ser global)
void ISR_AtualizarEncoder();

#endif
