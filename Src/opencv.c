#include "opencv.h"
#include "usart.h"
#include "mode.h"

uint8_t flag_ballon=0;
uint8_t Rx_data=0;

void Opencv_Init(void)
{
  HAL_UART_Receive_IT(&huart1,&Rx_data,1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
 if(huart->Instance==USART1)
 {
  if(Rx_data==49)
	{
	 flag_ballon=1;
	}
  HAL_UART_Receive_IT(&huart1,&Rx_data,1);
 }
}

