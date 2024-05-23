/*
 * led7display4digit.h
 *
 *  Created on: Apr 1, 2024
 *      Author: pc
 */

#ifndef SRC_LED7DISPLAY4DIGIT_H_
#define SRC_LED7DISPLAY4DIGIT_H_

#include "main.h"

//TODO
const uint8_t codes[18][8] = {
    {1, 1, 1, 1, 1, 1, 0, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1, 0}, // 2
    {1, 1, 1, 1, 0, 0, 1, 0}, // 3
    {0, 1, 1, 0, 0, 1, 1, 0}, // 4
    {1, 0, 1, 1, 0, 1, 1, 0}, // 5
    {1, 0, 1, 1, 1, 1, 1, 0}, // 6
    {1, 1, 1, 0, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1, 0}, // 8
    {1, 1, 1, 1, 0, 1, 1, 0}, // 9
    {1, 1, 1, 0, 1, 1, 1, 0}, // A
    {0, 0, 1, 1, 1, 1, 1, 0}, // B
    {1, 0, 0, 1, 1, 1, 0, 0}, // C
    {0, 1, 1, 1, 1, 0, 1, 0}, // D
    {1, 0, 0, 1, 1, 1, 1, 0}, // E
    {1, 0, 0, 0, 1, 1, 1, 0}, // F
    {0, 0, 0, 0, 0, 0, 0, 1}, // типу point
    {0, 0, 0, 0, 0, 0, 0, 0}  // clear
};
const uint16_t LEDS_PINS[8] = {
    LEDa_Pin, LEDb_Pin, LEDc_Pin, LEDd_Pin, LEDe_Pin, LEDf_Pin, LEDg_Pin, LEDp_Pin
};
GPIO_TypeDef* LEDS_PORTS[8] = {
    LEDa_GPIO_Port, LEDb_GPIO_Port, LEDc_GPIO_Port, LEDd_GPIO_Port,
    LEDe_GPIO_Port, LEDf_GPIO_Port, LEDg_GPIO_Port, LEDp_GPIO_Port
};

void displayNumber(uint8_t number){
	for(uint8_t i=0; i<8; i++)
		HAL_GPIO_WritePin( LEDS_PORTS[i], LEDS_PINS[i], !codes[number][i] );
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
}

#endif /* SRC_LED7DISPLAY4DIGIT_H_ */
