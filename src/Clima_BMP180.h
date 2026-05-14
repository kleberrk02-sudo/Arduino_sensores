/*
 ******************************************************************************
 * @file    Clima_BMP180.h
 * @brief   Biblioteca para leitura de Pressão e Temperatura com BMP180/085.
 ******************************************************************************
 * @attention
 *
 * Date: 13/05/2026
 * Author: Kleberson
 * Project: Biblioteca Pessoal de Automação
 * Version: 1.0
 ******************************************************************************
 */

#ifndef CLIMA_BMP180_H
#define CLIMA_BMP180_H

#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <LiquidCrystal_I2C.h>

/*
 **************************************************************
 * @name  BMP180_Init
 * @brief Inicializa o barramento I2C, o sensor e os LCDs.
 ***************************************************************
 * @input:   *_bmp   - ponteiro para a instância do sensor
 * *_lcd1  - display para temperatura
 * *_lcd2  - display para pressão
 * @return:  bool    - retorna true se o sensor iniciar com sucesso
 */
bool BMP180_Init(Adafruit_BMP085 *_bmp, LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2);

/*
 **************************************************************
 * @name  BMP180_UpdateDisplay
 * @brief Lê os dados do sensor e atualiza os valores nos LCDs.
 ***************************************************************
 * @input:   *_bmp   - ponteiro para o sensor
 * *_lcd1  - display de temperatura
 * *_lcd2  - display de pressão
 * @return:  sem retorno
 */
void BMP180_UpdateDisplay(Adafruit_BMP085 *_bmp, LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2);

#endif
