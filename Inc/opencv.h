#ifndef __OPENCV_H_
#define __OPENCV_H_

#include "usart.h"

extern uint8_t Rx_data;
extern uint8_t flag_ballon;



void Opencv_Init(void);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);





#endif

