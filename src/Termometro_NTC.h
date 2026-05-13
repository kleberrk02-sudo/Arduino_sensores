/*
 ******************************************************************************
 * @file    Termometro_NTC.h
 * @brief   Biblioteca para cálculo de temperatura via NTC e exibição em LCD.
 ******************************************************************************
 * @attention
 *
 * Date: 13/05/2026
 * Author: Kleberson
 * Project: Biblioteca Pessoal de Automação
 * Version: 1.0
 ******************************************************************************
 */

#ifndef TERMOMETRO_NTC_H
#define TERMOMETRO_NTC_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <math.h>

/*
 **************************************************************
 * @name  NTC_Init
 * @brief Inicializa os displays para a leitura de temperatura.
 ***************************************************************
 * @input:   *_lcd1 - ponteiro para o display de temperatura
 * *_lcd2 - ponteiro para o display de valor ADC
 * @return:  sem retorno
 */
void NTC_Init(LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2);

/*
 **************************************************************
 * @name  NTC_ReadAndDisplay
 * @brief Realiza a leitura analógica, calcula a temperatura e atualiza os LCDs.
 ***************************************************************
 * @input:   _pin  - pino analógico do NTC
 * *_lcd1 - display de temperatura
 * *_lcd2 - display de valor ADC
 * @return:  sem retorno
 */
void NTC_ReadAndDisplay(int _pin, LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2);

#endif
