/*
 ******************************************************************************
 * @file    Acelerometro_ADXL345.h
 * @brief   Biblioteca para leitura do ADXL345 e exibição em LCD I2C.
 ******************************************************************************
 * @attention
 *
 * Date: 13/05/2026
 * Author: Kleberson
 * Project: Biblioteca Pessoal de Automação
 * Version: 1.0
 ******************************************************************************
 */

#ifndef ACELEROMETRO_ADXL345_H
#define ACELEROMETRO_ADXL345_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
#include <LiquidCrystal_I2C.h>

/*
 **************************************************************
 * @name  ADXL345_Init
 * @brief Inicializa o sensor acelerômetro e os displays LCD.
 ***************************************************************
 * @input:   *_accel - ponteiro para a instância do sensor
 * *_lcd1  - ponteiro para o display dos eixos X/Y
 * *_lcd2  - ponteiro para o display do eixo Z
 * @return:  bool    - retorna true se o sensor for iniciado com sucesso
 */
bool ADXL345_Init(Adafruit_ADXL345_Unified *_accel, LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2);

/*
 **************************************************************
 * @name  ADXL345_ReadAndDisplay
 * @brief Lê as acelerações e atualiza os dados nos displays.
 ***************************************************************
 * @input:   *_accel - ponteiro para o sensor
 * *_lcd1  - display X/Y
 * *_lcd2  - display Z
 * @return:  sem retorno
 */
void ADXL345_ReadAndDisplay(Adafruit_ADXL345_Unified *_accel, LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2);

#endif
