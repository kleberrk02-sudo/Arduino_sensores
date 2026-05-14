# Arduino_sensores

Biblioteca modular desenvolvida para a leitura, processamento e exibição de dados de diversos sensores utilizando a plataforma Arduino.
O projeto é otimizado para o simulador PICSimLab e segue padrões profissionais de organização de software.

Funcionalidades:

**Termômetro NTC:** Leitura de temperatura analógica utilizando a Equação Beta para conversão de resistência em Celsius.

**Acelerômetro ADXL345:** Monitoramento de aceleração nos eixos X, Y e Z com suporte a diferentes escalas de sensibilidade (G).

**Balança Digital (HX711):** Sistema de pesagem com calibração via software e tratamento de ruído bruto (RAW).

**Sensor Ultrassônico (HC-SR04):** Medição de distância por pulso sonoro com cálculo baseado na velocidade do som (0.0343 cm/µs).

**Encoder Rotativo:** Controle de posição e sentido de giro (horário/anti-horário) utilizando interrupções de hardware para alta precisão.

**Estação Climática (BMP180):** Monitoramento barométrico de pressão atmosférica e temperatura via protocolo I2C.

* Exibição em múltiplos displays LCD via I2C.
* Compatível com o simulador PICSimLab.
