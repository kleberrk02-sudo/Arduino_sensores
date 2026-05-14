/*
 ******************************************************************************
 * @file    Sensor_Distancia.h
 * @brief   Biblioteca para medição de distância com HC-SR04 e displays I2C.
 ******************************************************************************
 * @attention
 *
 * Date: 13/05/2026
 * Author: Kleberson
 * Project: Biblioteca Pessoal de Automação
 * Version: 1.0
 ******************************************************************************
 */

#ifndef SENSOR_DISTANCIA_H
#define SENSOR_DISTANCIA_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

/*
 **************************************************************
 * @name  Distancia_Init
 * @brief Configura os pinos do sensor e inicializa os displays.
 ***************************************************************
 * @input:   _pinoTrig - pino de disparo (Trigger)
 * _pinoEcho - pino de receção (Echo)
 * *_lcd1    - display principal
 * *_lcd2    - display secundário
 * @return:  sem retorno
 */
void Distancia_Init(int _pinoTrig, int _pinoEcho, LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2);

/*
 **************************************************************
 * @name  Distancia_Update
 * @brief Realiza a leitura do sensor e atualiza os dados nos LCDs.
 ***************************************************************
 * @input:   _pinoTrig - pino de disparo
 * _pinoEcho - pino de receção
 * *_lcd1    - display para distância (cm)
 * *_lcd2    - display para tempo de eco (us)
 * @return:  sem retorno
 */
void Distancia_Update(int _pinoTrig, int _pinoEcho, LiquidCrystal_I2C *_lcd1, LiquidCrystal_I2C *_lcd2);

#endif
