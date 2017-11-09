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
  
  while(1)
  {
    if(HAL_I2S_Receive_DMA(&hi2s1, data_buffer, 512))
    {
      for(uint16_t i = 0; i < 512; i++)
        printf("%5x\t", data_buffer[i]);
      printf("\n");
    }
  }

  return 0;
}

