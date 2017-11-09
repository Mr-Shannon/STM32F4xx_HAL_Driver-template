#ifndef __I2S_H__
#define __I2S_H__

#include "stm32f4xx.h"

#define USER_I2S                              SPI1
#define USER_I2S_GPIO_AF                      GPIO_AF5_SPI1
#define USER_I2S_ENABLE(a)                    __HAL_I2S_ENABLE(a)
#define USER_I2S_DISABLE(a)                   __HAL_I2S_DISABLE(a)
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
#define USER_I2S_WS_PIN                       GPIO_PIN_15
#define USER_I2S_WS_RCC_CLK_ENABLE()          __HAL_RCC_GPIOA_CLK_ENABLE()
#define USER_I2S_WS_RCC_CLK_DISABLE()         __HAL_RCC_GPIOA_CLK_DISABLE()

#define USER_I2S_RX_DMA_STREAM                DMA2_Stream0
#define USER_I2S_RX_DMA_CHANNEL               DMA_CHANNEL_3
#define USER_I2S_DMA_RCC_CLK_ENABLE()         __HAL_RCC_DMA2_CLK_ENABLE()
#define USER_I2S_DMA_RCC_CLK_DISABLE()        __HAL_RCC_DMA2_CLK_DISABLE()

#define USER_I2S_AUDIO_FREQ                   I2S_AUDIOFREQ_16K



void USER_I2S_Init(void);


#endif

