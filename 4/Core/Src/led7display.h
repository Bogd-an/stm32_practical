/*
 * led7display.h
 *
 *  Created on: Apr 1, 2024
 *      Author: pc
 */

#ifndef SRC_LED7DISPLAY_H_
#define SRC_LED7DISPLAY_H_

#include "main.h"

const uint8_t codes[18][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}, // 9
    {1, 1, 1, 0, 1, 1, 1}, // A
    {0, 0, 1, 1, 1, 1, 1}, // B
    {1, 0, 0, 1, 1, 1, 0}, // C
    {0, 1, 1, 1, 1, 0, 1}, // D
    {1, 0, 0, 1, 1, 1, 1}, // E
    {1, 0, 0, 0, 1, 1, 1}, // F
    {0, 0, 0, 0, 0, 0, 1}, // типу point
    {0, 0, 0, 0, 0, 0, 0}  // clear
};
const uint16_t LEDS_PINS[7] = {
    LEDa_Pin, LEDb_Pin, LEDc_Pin, LEDd_Pin, LEDe_Pin, LEDf_Pin, LEDg_Pin
};
GPIO_TypeDef* LEDS_PORTS[7] = {
    LEDa_GPIO_Port, LEDb_GPIO_Port, LEDc_GPIO_Port, LEDd_GPIO_Port,
    LEDe_GPIO_Port, LEDf_GPIO_Port, LEDg_GPIO_Port
};

void displayNumber(uint8_t number){
	for(uint8_t i=0; i<7; i++)
		HAL_GPIO_WritePin( LEDS_PORTS[i], LEDS_PINS[i], codes[number][i] );
}
 
void displayChar(char charNumber){
	switch (charNumber) {
    case '0' ... '9':
        displayNumber(charNumber - '0');
        break;
    case 'A' ... 'F':
        displayNumber(charNumber - 'A' + 10);
        break;
    case '*':
        displayNumber(16);
        break;
    case '#':
        displayNumber(17);
        break;
    }
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
}

#endif /* SRC_LED7DISPLAY_H_ */
