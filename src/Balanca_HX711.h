/*
 ******************************************************************************
 * @file    Balanca_HX711.h
 * @brief   Biblioteca para sistema de pesagem com HX711 e displays I2C.
 ******************************************************************************
 * @attention
 *
 * Date: 13/05/2026
 * Author: Kleberson
 * Project: Biblioteca Pessoal de Automação
 * Version: 1.0
 ******************************************************************************
 */

#ifndef BALANCA_HX711_H
#define BALANCA_HX711_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "HX711.h"

/*
 **************************************************************
 * @name  Balanca_Init
 * @brief Inicializa a célula de carga e os displays LCD.
 ***************************************************************
 * @input:   *_balanca - ponteiro para a instância HX711
 * _pinDT    - pino de dados
 * _pinSCK   - pino de clock
 * *_lcd1    - display principal
 * *_lcd2    - display de monitoramento
 * @return:  sem retorno
 */
void Balanca_Init(HX711 *_balanca, int _pinDT, int _pinSCK, LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2);

/*
 **************************************************************
 * @name  Balanca_Update
 * @brief Processa a leitura bruta e atualiza os pesos nos LCDs.
 ***************************************************************
 * @input:   *_balanca - instância HX711
 * *_lcd1    - display de peso corrigido
 * *_lcd2    - display de valor bruto
 * @return:  sem retorno
 */
void Balanca_Update(HX711 *_balanca, LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2);

#endif
