
#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_


#include "stm32f1xx_hal.h"
#include "main.h"
#include "time.h"

char read_keypad(void) {
  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_SET);
  if (!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin))) {
    while (!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin)));
    return '1';
  }
  if (!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin))) {
    while (!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin)));
    return '2';
  }
  if (!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin))) {
    while (!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin)));
    return '3';
  }
  if (!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin))) {
    while (!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin)));
    return 'A';
  }
  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_SET);
  if (!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin))) {
    while (!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin)));
    return '4';
  }
  if (!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin))) {
    while (!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin)));
    return '5';
  }
  if (!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin))) {
    while (!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin)));
    return '6';
  }
  if (!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin))) {
    while (!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin)));
    return 'B';
  }
  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_SET);
  if (!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin))) {
    while (!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin)));
    return '7';
  }
  if (!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin))) {
    while (!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin)));
    return '8';
  }
  if (!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin))) {
    while (!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin)));
    return '9';
  }
  if (!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin))) {
    while (!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin)));
    return 'C';
  }

  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_RESET);
  if (!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin))) {
    while (!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin)));
    return '*';
  }
  if (!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin))) {
    while (!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin)));
    return '0';
  }
  if (!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin))) {
    while (!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin)));
    return '#';
  }
  if (!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin))) {
    while (!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin)));
    return 'D';
  }
  return 0;
}

#endif /* INC_KEYPAD_H_ */
