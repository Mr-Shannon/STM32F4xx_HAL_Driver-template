#include "i2s.h"

I2S_HandleTypeDef   hi2s1;

void USER_I2S_Init(void)
{
  hi2s1.Instance            = USER_I2S;
  HAL_I2S_DeInit(&hi2s1);
  hi2s1.Init.AudioFreq      = USER_I2S_AUDIO_FREQ;
  hi2s1.Init.ClockSource    = I2S_CLOCK_PLL;
  hi2s1.Init.CPOL           = I2S_CPOL_LOW;
  hi2s1.Init.DataFormat     = I2S_DATAFORMAT_16B_EXTENDED;
  hi2s1.Init.FullDuplexMode = I2S_FULLDUPLEXMODE_DISABLE;
  hi2s1.Init.MCLKOutput     = I2S_MCLKOUTPUT_DISABLE;
  hi2s1.Init.Mode           = I2S_MODE_MASTER_TX;
  hi2s1.Init.Standard       = I2S_STANDARD_MSB;
  HAL_I2S_Init(&hi2s1);
}

void HAL_I2S_MspInit(I2S_HandleTypeDef *hi2s)
{
  GPIO_InitTypeDef  GPIO_InitStruct;
  
  if(hi2s->Instance == USER_I2S)
  {
    //RCC
    USER_I2S_SCK_RCC_CLK_ENABLE();
    USER_I2S_SD_RCC_CLK_ENABLE();
    USER_I2S_WS_RCC_CLK_ENABLE();
    USER_I2S_RCC_CLK_ENABLE();
    
    //GPIO
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_PULLUP;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FAST;
    GPIO_InitStruct.Alternate = USER_I2S_GPIO_AF;
    
    GPIO_InitStruct.Pin       = USER_I2S_SCK_PIN;
    HAL_GPIO_Init(USER_I2S_SCK_PORT, &GPIO_InitStruct);
    
    GPIO_InitStruct.Pin       = USER_I2S_SD_PIN;
    HAL_GPIO_Init(USER_I2S_SD_PORT, &GPIO_InitStruct);
    
    GPIO_InitStruct.Pin       = USER_I2S_WS_PIN;
    HAL_GPIO_Init(USER_I2S_WS_PORT, &GPIO_InitStruct);
  }
}




