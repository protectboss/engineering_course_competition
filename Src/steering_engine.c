#include "steering_engine.h"
#include "tim.h"

void Steering_Engine_Init(void)
{
 HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
}

void Steering_Engine_Prick_Balloon(void)
{
 __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,1000);
}

void Steering_Engine_Stop(void)
{
 __HAL_TIM_SetCompare(&htim2,TIM_CHANNEL_3,2500);
}

