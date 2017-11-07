#include "board.h"

extern void debug_uart1_init(void);

int main(void)
{
  HAL_Init();	
  USER_UART_Init();
  
  while(1)
  {    
    printf("Hello World");
		HAL_Delay(10);
  }

  return 0;
}

