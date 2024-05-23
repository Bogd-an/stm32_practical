/*
 * keyPad.h
 *
 *    Created on: Apr 1, 2024
 *            Author: pc
 */

#ifndef SRC_KEYPAD_H_
#define SRC_KEYPAD_H_

#include "main.h"

const uint16_t columnPins[4] = { 
    C1_Pin, C2_Pin, C3_Pin, C4_Pin };
const uint16_t rowPins[4] = { 
    R1_Pin, R2_Pin, R3_Pin, R4_Pin };
GPIO_TypeDef* columnPorts[4] = {
    C1_GPIO_Port, C2_GPIO_Port, C3_GPIO_Port, C4_GPIO_Port};
GPIO_TypeDef* rowPorts[4] = {
    R1_GPIO_Port, R2_GPIO_Port, R3_GPIO_Port, R4_GPIO_Port};

const char keypadKeys[4][4]={
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

char read_keypad2(void) {
    for(uint8_t row=1; row<4;row++)
        HAL_GPIO_WritePin(rowPorts[row], rowPins[row], GPIO_PIN_SET);
    for (uint8_t row = 0; row < 4; row++) {
        // Activate row
        HAL_GPIO_WritePin(rowPorts[row], rowPins[row], GPIO_PIN_RESET);
        // Check columns
        for (uint8_t column = 0; column < 4; column++)
            if (! HAL_GPIO_ReadPin(columnPorts[column], columnPins[column])){
                return keypadKeys[row][column];
            }
        // Deactivate row
        HAL_GPIO_WritePin(rowPorts[row], rowPins[row], GPIO_PIN_SET);
    }
    return 0;
}


char read_keypad (void)
{
/* Встановити НИЗЬКИЙ рівень на рядку R1 та ВИСОКИЙ на всіх інших
рядках */
HAL_GPIO_WritePin (R1_GPIO_Port, R1_PIN, GPIO_PIN_RESET);
HAL_GPIO_WritePin (R2_GPIO_Port, R2_PIN, GPIO_PIN_SET);
HAL_GPIO_WritePin (R3_GPIO_Port, R3_PIN, GPIO_PIN_SET);
HAL_GPIO_WritePin (R4_GPIO_Port, R4_PIN, GPIO_PIN_SET);
// якщо на стовпці С1 низький рівень
if (!(HAL_GPIO_ReadPin (C1_PORT, C1_PIN)))
{
// очікуємо поки кнопка натиснута
while (!(HAL_GPIO_ReadPin (C1_PORT, C1_PIN)));
return '1';
}
// якщо на стовпці С2 низький рівень
if (!(HAL_GPIO_ReadPin (C2_PORT, C2_PIN)))
{
while (!(HAL_GPIO_ReadPin (C2_PORT, C2_PIN)));
return '2';
}
// якщо на стовпці С3 низький рівень
if (!(HAL_GPIO_ReadPin (C3_PORT, C3_PIN)))
{
while (!(HAL_GPIO_ReadPin (C3_PORT, C3_PIN)));
return '3';
}
// якщо на стовпці С4 низький рівень
if (!(HAL_GPIO_ReadPin (C4_PORT, C4_PIN)))
{
while (!(HAL_GPIO_ReadPin (C4_PORT, C4_PIN)));
return 'A';
}
/* Встановити НИЗЬКИЙ рівень на рядку R2 та ВИСОКИЙ на всіхрядках */
HAL_GPIO_WritePin (R1_GPIO_Port, R1_PIN, GPIO_PIN_SET);
HAL_GPIO_WritePin (R2_GPIO_Port, R2_PIN, GPIO_PIN_RESET);
HAL_GPIO_WritePin (R3_GPIO_Port, R3_PIN, GPIO_PIN_SET);
HAL_GPIO_WritePin (R4_GPIO_Port, R4_PIN, GPIO_PIN_SET);
// якщо на стовпці С1 низький рівень
if (!(HAL_GPIO_ReadPin (C1_PORT, C1_PIN)))
{
while (!(HAL_GPIO_ReadPin (C1_PORT, C1_PIN)));
return '4';
}
// якщо на стовпці С2 низький рівень
if (!(HAL_GPIO_ReadPin (C2_PORT, C2_PIN)))
{
while (!(HAL_GPIO_ReadPin (C2_PORT, C2_PIN)));
return '5';
}
// якщо на стовпці С3 низький рівень
if (!(HAL_GPIO_ReadPin (C3_PORT, C3_PIN)))
{
while (!(HAL_GPIO_ReadPin (C3_PORT, C3_PIN)));
return '6';
}
// якщо на стовпці С4 низький рівень
if (!(HAL_GPIO_ReadPin (C4_PORT, C4_PIN)))
{
while (!(HAL_GPIO_ReadPin (C4_PORT, C4_PIN)));
return 'B';
}
/* Встановити НИЗЬКИЙ рівень на рядку R3 та ВИСОКИЙ на всіх інших
рядках */
HAL_GPIO_WritePin (R1_GPIO_Port, R1_PIN, GPIO_PIN_SET);
HAL_GPIO_WritePin (R2_GPIO_Port, R2_PIN, GPIO_PIN_SET);
HAL_GPIO_WritePin (R3_GPIO_Port, R3_PIN, GPIO_PIN_RESET);
HAL_GPIO_WritePin (R4_GPIO_Port, R4_PIN, GPIO_PIN_SET);
// якщо на стовпці С1 низький рівень
if (!(HAL_GPIO_ReadPin (C1_PORT, C1_PIN)))
{
while (!(HAL_GPIO_ReadPin (C1_PORT, C1_PIN)));
return '7';
}
// якщо на стовпці С2 низький рівень
if (!(HAL_GPIO_ReadPin (C2_PORT, C2_PIN)))
{
while (!(HAL_GPIO_ReadPin (C2_PORT, C2_PIN)));
return '8';
}
// якщо на стовпці С3 низький рівень
if (!(HAL_GPIO_ReadPin (C3_PORT, C3_PIN)))
{
while (!(HAL_GPIO_ReadPin (C3_PORT, C3_PIN)));
return '9';
}
// якщо на стовпці С4 низький рівень
if (!(HAL_GPIO_ReadPin (C4_PORT, C4_PIN)))
{
while (!(HAL_GPIO_ReadPin (C4_PORT, C4_PIN)));
return 'C';
}
/* Встановити НИЗЬКИЙ рівень на рядку R4 та ВИСОКИЙ на всіх інших
рядках */
HAL_GPIO_WritePin (R1_GPIO_Port, R1_PIN, GPIO_PIN_SET);
HAL_GPIO_WritePin (R2_GPIO_Port, R2_PIN, GPIO_PIN_SET);
HAL_GPIO_WritePin (R3_GPIO_Port, R3_PIN, GPIO_PIN_SET);
HAL_GPIO_WritePin (R4_GPIO_Port, R4_PIN, GPIO_PIN_RESET);
// якщо на стовпці С1 низький рівень
if (!(HAL_GPIO_ReadPin (C1_PORT, C1_PIN)))
{
while (!(HAL_GPIO_ReadPin (C1_PORT, C1_PIN)));
return '*';
}
// якщо на стовпці С2 низький рівень
if (!(HAL_GPIO_ReadPin (C2_PORT, C2_PIN)))
{
while (!(HAL_GPIO_ReadPin (C2_PORT, C2_PIN)));
return '0';
}
// якщо на стовпці С3 низький рівень
if (!(HAL_GPIO_ReadPin (C3_PORT, C3_PIN)))
{
while (!(HAL_GPIO_ReadPin (C3_PORT, C3_PIN)));
return '#';
}
// якщо на стовпці С4 низький рівень
if (!(HAL_GPIO_ReadPin (C4_PORT, C4_PIN)))
{
while (!(HAL_GPIO_ReadPin (C4_PORT, C4_PIN)));
return 'D';
}
return 0;
 // якщо жодна кнопка не натиснута
}

#endif /* SRC_KEYPAD_H_ */