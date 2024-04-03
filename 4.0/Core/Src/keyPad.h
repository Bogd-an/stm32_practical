/*
 * keyPad.h
 *
 *    Created on: Apr 1, 2024
 *            Author: pc
 */

#ifndef SRC_KEYPAD_H_
#define SRC_KEYPAD_H_

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

char read_keypad(void) {
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

#endif /* SRC_KEYPAD_H_ */