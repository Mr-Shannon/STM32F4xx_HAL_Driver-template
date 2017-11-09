#include "board.h"

uint16_t data_buffer[512];
extern I2S_HandleTypeDef hi2s1;

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  USER_UART_Init();	
  USER_I2S_Init();
  printf("DMA \n");
  HAL_I2S_Receive_DMA(&hi2s1, data_buffer, 512); 
  
  while(1)
  {
    
  }

  return 0;
}

