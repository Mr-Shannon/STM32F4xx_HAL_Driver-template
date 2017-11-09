#include "i2s.h"

I2S_HandleTypeDef   hi2s1;
DMA_HandleTypeDef hdma_hi2s1_rx;

void USER_I2S_Init(void)
{
  hi2s1.Instance            = USER_I2S;
  HAL_I2S_DeInit(&hi2s1);
  hi2s1.Init.AudioFreq      = USER_I2S_AUDIO_FREQ;
  hi2s1.Init.ClockSource    = I2S_CLOCK_PLL;
  hi2s1.Init.CPOL           = I2S_CPOL_LOW;
  hi2s1.Init.DataFormat     = I2S_DATAFORMAT_16B;
  hi2s1.Init.FullDuplexMode = I2S_FULLDUPLEXMODE_DISABLE;
  hi2s1.Init.MCLKOutput     = I2S_MCLKOUTPUT_ENABLE;
  hi2s1.Init.Mode           = I2S_MODE_MASTER_RX;
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
    USER_I2S_DMA_RCC_CLK_ENABLE();
    USER_I2S_RCC_CLK_ENABLE();
    
    //GPIO
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_NOPULL;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = USER_I2S_GPIO_AF;
    
    GPIO_InitStruct.Pin       = USER_I2S_SCK_PIN;
    HAL_GPIO_Init(USER_I2S_SCK_PORT, &GPIO_InitStruct);
    
    GPIO_InitStruct.Pin       = USER_I2S_SD_PIN;
    HAL_GPIO_Init(USER_I2S_SD_PORT, &GPIO_InitStruct);
    
    GPIO_InitStruct.Pin       = USER_I2S_WS_PIN;
    HAL_GPIO_Init(USER_I2S_WS_PORT, &GPIO_InitStruct);
    
    hdma_hi2s1_rx.Instance                  = USER_I2S_RX_DMA_STREAM;
    HAL_DMA_DeInit(&hdma_hi2s1_rx);
    hdma_hi2s1_rx.Init.Channel              = USER_I2S_RX_DMA_CHANNEL;
    hdma_hi2s1_rx.Init.Direction            = DMA_PERIPH_TO_MEMORY;
    hdma_hi2s1_rx.Init.PeriphInc            = DMA_PINC_DISABLE;
    hdma_hi2s1_rx.Init.MemInc               = DMA_MINC_ENABLE;
    hdma_hi2s1_rx.Init.PeriphDataAlignment  = DMA_PDATAALIGN_HALFWORD;
    hdma_hi2s1_rx.Init.MemDataAlignment     = DMA_MDATAALIGN_HALFWORD;
    hdma_hi2s1_rx.Init.Mode                 = DMA_CIRCULAR;
    hdma_hi2s1_rx.Init.Priority             = DMA_PRIORITY_VERY_HIGH;
    hdma_hi2s1_rx.Init.FIFOMode             = DMA_FIFOMODE_DISABLE;

    HAL_DMA_Init(&hdma_hi2s1_rx);
    
    __HAL_LINKDMA(hi2s, hdmarx, hdma_hi2s1_rx);
    
    /* DMA2_Stream0_IRQn interrupt configuration */
    HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 2, 1);
    HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);
  }
}

void HAL_I2S_MspDeInit(I2S_HandleTypeDef* hi2s)
{
  if(hi2s->Instance == USER_I2S)
  {
    USER_I2S_RCC_CLK_DISABLE();
  
    HAL_GPIO_DeInit(USER_I2S_SCK_PORT, USER_I2S_SCK_PIN);
    HAL_GPIO_DeInit(USER_I2S_SD_PORT, USER_I2S_SD_PIN);
    HAL_GPIO_DeInit(USER_I2S_WS_PORT, USER_I2S_WS_PIN);
    HAL_DMA_DeInit(hi2s->hdmarx);
  }
}





