#ifndef __I2S_H__
#define __I2S_H__

#include "stm32f4xx.h"

#define USER_I2S                              SPI1
#define USER_I2S_GPIO_AF                      GPIO_AF5_SPI1
#define USER_I2S_RCC_CLK_ENABLE()             __HAL_RCC_SPI1_CLK_ENABLE()
#define USER_I2S_RCC_CLK_DISABLE()            __HAL_RCC_SPI1_CLK_DISABLE()

#define USER_I2S_SCK_PORT                     GPIOA
#define USER_I2S_SCK_PIN                      GPIO_PIN_5
#define USER_I2S_SCK_RCC_CLK_ENABLE()         __HAL_RCC_GPIOA_CLK_ENABLE()
#define USER_I2S_SCK_RCC_CLK_DISABLE()        __HAL_RCC_GPIOA_CLK_DISABLE()

#define USER_I2S_SD_PORT                      GPIOA
#define USER_I2S_SD_PIN                       GPIO_PIN_7
#define USER_I2S_SD_RCC_CLK_ENABLE()          __HAL_RCC_GPIOA_CLK_ENABLE()
#define USER_I2S_SD_RCC_CLK_DISABLE()         __HAL_RCC_GPIOA_CLK_DISABLE()

#define USER_I2S_WS_PORT                      GPIOA
#define USER_I2S_WS_PIN                       GPIO_PIN_4
#define USER_I2S_WS_RCC_CLK_ENABLE()          __HAL_RCC_GPIOA_CLK_ENABLE()
#define USER_I2S_WS_RCC_CLK_DISABLE()         __HAL_RCC_GPIOA_CLK_DISABLE()

#define USER_I2S_AUDIO_FREQ                   16000

void USER_I2S_Init(void);


#endif

