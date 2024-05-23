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
const uint8_t COD_CLEAR = 17; // in codes[]
const uint8_t COD_MINUS = 18; // in codes[]

const uint8_t codes[19][8] = {
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
    {0, 0, 0, 0, 0, 0, 0, 1}, // point
    {0, 0, 0, 0, 0, 0, 0, 0}, // clear
    {0, 0, 0, 0, 0, 0, 1, 0}  // -
};

const uint16_t LEDS_PINS[8] = {
    LEDa_Pin, LEDb_Pin, LEDc_Pin, LEDd_Pin, LEDe_Pin, LEDf_Pin, LEDg_Pin, LEDp_Pin
};
GPIO_TypeDef* LEDS_PORTS[8] = {
    LEDa_GPIO_Port, LEDb_GPIO_Port, LEDc_GPIO_Port, LEDd_GPIO_Port,
    LEDe_GPIO_Port, LEDf_GPIO_Port, LEDg_GPIO_Port, LEDp_GPIO_Port
};


const uint16_t D_PINS[4] = {D1_Pin,             D2_Pin,       D3_Pin,       D4_Pin};
GPIO_TypeDef* D_PORTS[4] = {D1_GPIO_Port, D2_GPIO_Port, D3_GPIO_Port, D4_GPIO_Port};

/**
  * @param number       0..9..19
  * @param number_digit 0..3
  */
void displayNumberToDigit(uint8_t number, uint8_t number_digit){
	for(uint8_t i=0; i<8; i++) // off segments
	            HAL_GPIO_WritePin(LEDS_PORTS[i], LEDS_PINS[i], 1 );
    for(uint8_t i=0; i<4; i++) // on/off digit
        HAL_GPIO_WritePin(D_PORTS[i], D_PINS[i], number_digit == i);
    for(uint8_t i=0; i<8; i++) // on/off segments
        HAL_GPIO_WritePin(LEDS_PORTS[i], LEDS_PINS[i], !codes[number][i] );

}

uint8_t currentDigit = 0; // 0..3
int16_t number = 0;
int8_t numberOverflow = 0;
//TODO
uint8_t numberDigit[4] = {COD_CLEAR,COD_CLEAR,COD_CLEAR,COD_CLEAR};

uint8_t pointState = 1;

void displayTick(){
    displayNumberToDigit(numberDigit[currentDigit], currentDigit);
    if(currentDigit++ >= 4) {
        currentDigit = 0;
//        if(numberOverflow) HAL_GPIO_WritePin(LEDp_GPIO_Port, LEDp_Pin, 0);
    }
    if(currentDigit == 3)
    	HAL_GPIO_WritePin(LEDp_GPIO_Port, LEDp_Pin, pointState);
}

void pointBlink(){
	pointState = !pointState;
}

void displayNumber2(int16_t newNumber){
	for(uint8_t i=0; i<4; i++) numberDigit[i] = COD_CLEAR;

	for (int i = 3; i >= 0; i--) {
		numberDigit[i] = newNumber % 10;
		newNumber /= 10;
	    }
	currentDigit = 0;
	displayTick();
}

void displayNumber(int16_t newNumber){
    number = newNumber;
    currentDigit = 0;
    numberOverflow = 0;

    for(uint8_t i=0; i<4; i++) numberDigit[i] = COD_CLEAR;

    if(newNumber ==0){
    	numberDigit[0]=0;
    	return;
    }
    uint8_t digitCount = 0;
    if(newNumber < 0){
        numberDigit[3] = COD_MINUS;
        newNumber *= -1;
    }
    
    do {
        numberDigit[digitCount++] = newNumber % 10;
        newNumber /= 10;
        if(numberDigit[3]==COD_MINUS) break;
    } while (newNumber > 0 && digitCount < 4);
    
    if(numberDigit[3]==COD_MINUS){
    	numberOverflow = newNumber < 0;
    }else {
    	numberOverflow = newNumber > 0;
    }


    displayTick();
}



 
// void displayChar(char charNumber){
// 	switch (charNumber) {
//     case '0' ... '9':
//         displayNumber(charNumber - '0');
//         break;
//     case 'A' ... 'F':
//         displayNumber(charNumber - 'A' + 10);
//         break;
//     case '*':
//         displayNumber(16);
//         break;
//     case '#':
//         displayNumber(17);
//         break;
//     }
// }

#endif /* SRC_LED7DISPLAY4DIGIT_H_ */
