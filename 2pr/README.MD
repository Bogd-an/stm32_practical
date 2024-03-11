# Практична робота 2

## ТЗ
Написати програму, в якій у випадку натискання кнопки користувацький
світлодіод розпочинає миготіти з частотою 2 Гц. При утримані кнопки в
натиснутому стані кожних 2 секунди частота блимання повинна
збільшуватись в два рази, максимум до 64 Гц. Після чого світлодіод
повинен загаснути. У разі відпускання кнопки світлодіод вмикається на
секунду та гасне.
---
[Увесь код main.c](Core/Src/main.c)

[Відос з прикладом роботи](https://github.com/Bogd-an/stm32_practical/raw/main/2pr/READMEfiles/PLAYpr2.3TestCode.html)

```cpp
/* USER CODE BEGIN PFP */
int button_pressed (void);
```

```cpp
/* USER CODE BEGIN WHILE */
uint32_t previousMillisFrequency = HAL_GetTick();
uint32_t previousMillisLongPress = HAL_GetTick();
int  frequencyBlink = 2;
int  buttonState = 0;
```
```cpp
/* USER CODE BEGIN 3 */
if(frequencyBlink > 0){
        if(HAL_GetTick() - previousMillisFrequency >= 1000/frequencyBlink/2){
        previousMillisFrequency = HAL_GetTick();
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
    }
    buttonState = button_pressed();
    if     (buttonState == 1) frequencyBlink = 2;
    else if(buttonState == 2){ 
    if(HAL_GetTick() - previousMillisLongPress >= 2000){
        previousMillisLongPress = HAL_GetTick();
        frequencyBlink *= 2;
        if(frequencyBlink >= 64) {
        frequencyBlink = 0;
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
        }
    }
    }
}
else if(frequencyBlink == 0){
    frequencyBlink = -1;
    while(! button_pressed() == 0){}
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
    HAL_Delay(1000);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
} else{/* Щo тепер? */} 
```

```cpp
/* USER CODE BEGIN 4 */ 
int button_pressed (void){
// 0 - not press, 1 - short, 2 - long
	uint32_t count = 1;
	uint8_t flag = 0;
	while(count){
		count += (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)? 1: -1);
        if     (count == 500) flag = 1;
        else if(count == 10000) return 2;
	}
	return flag;
}
```
