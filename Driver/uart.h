#ifndef __UART_H__
#define __UART_H__

#include "stm32f4xx.h"

#define USER_UART                             USART1
#define USER_UART_GPIO_AF                     GPIO_AF7_USART1
#define USER_UART_RCC_CLK_ENABLE()            __HAL_RCC_USART1_CLK_ENABLE()
#define USER_UART_RCC_CLK_DISABLE()           __HAL_RCC_USART1_CLK_DISABLE()

#define USER_UART_TX_RCC_CLK_ENABLE()         __HAL_RCC_GPIOA_CLK_ENABLE()
#define USER_UART_TX_RCC_CLK_DISABLE()        __HAL_RCC_GPIOA_CLK_DISABLE()
#define USER_UART_TX_PORT                     GPIOA
#define USER_UART_TX_PIN                      GPIO_PIN_9

#define USER_UART_RX_RCC_CLK_ENABLE()         __HAL_RCC_GPIOA_CLK_ENABLE()
#define USER_UART_RX_RCC_CLK_DISABLE()        __HAL_RCC_GPIOA_CLK_DISABLE()
#define USER_UART_RX_PORT                     GPIOA
#define USER_UART_RX_PIN                      GPIO_PIN_10

void USER_UART_Init(void);

#endif
