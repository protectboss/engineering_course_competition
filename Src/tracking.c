#include "tim.h"
#include "tracking.h"
#include "chassis.h"


#define car_stop 0
#define car_turn_forward 1
#define car_turn_left 2
#define car_turn_right 3


int tracking[7];
int8_t direction=0;
int8_t amplitude=0;
int write_time=0;


void Read_GPIO(void)
{
	 tracking[6]=HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_0);
	 tracking[5]=HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_1);
	 tracking[4]=HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_2);
	 tracking[3]=HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_3);
	 tracking[2]=HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_4);
	 tracking[1]=HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_5);
	 tracking[0]=HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_6);
}


void Judge_Turn_Amplitude(void)
{
 if((tracking[6]||tracking[0])==1)
 {
  if(tracking[6]==1)
  {
   if(tracking[0]==1) direction=car_turn_forward;
	 else
	 {
	  direction=car_turn_right;
	  amplitude=3;
	 }
  }	
  else
  {
   direction=car_turn_left;
   amplitude=3;
  } 
 }
 else
 {
  if(tracking[5]||tracking[1]==1)
  {
   if(tracking[5]==1)
   {
    if(tracking[1]==1) direction=car_turn_forward;
    else
    {
     direction=car_turn_right;
	   amplitude=2;	
    }
   }
	 else
	 {
	  direction=car_turn_left;
	  amplitude=2;
	 }
  }
  else
  {
   if(tracking[4]||tracking[2])
   {
    if(tracking[4]==1)
	  {
	   if(tracking[2]==1) direction=car_turn_forward;
	   else
	   {
	    direction=car_turn_right;
	    amplitude=1;
 	   }
	  }
	  else
	  {
	   direction=car_turn_left;
	   amplitude=1;
	  }
   }
   else
   {
    if(tracking[3]==1) direction=car_turn_forward;
    else
		{
			direction=4;
			write_time++;
		}
   }
  }
 }
}

void Car_Target_Speed(void)
{
 switch(direction)
 {
	case 0:Car_Forward(0);break;
  case 1:Car_Forward(18);break;
	
	case 2:switch(amplitude)
	{
		case 3:Car_Turn(0,35);break;
	  case 2:Car_Turn(0,30);break;
		case 1:Car_Turn(15,20);break;
	}break;
	case 3:switch(amplitude)
	{
		case 3:Car_Turn(35,0);break;
	  case 2:Car_Turn(30,0);break;
		case 1:Car_Turn(20,15);break;
	}break;
	case 4:Car_Forward(10);break; 
 }
}


void Car_Target_Speed2(void)
{
 switch(direction)
 {
	case 0:Car_Forward(0);break;
  case 1:Car_Forward(40);break;
	
	case 2:switch(amplitude)
	{
		case 3:Car_Turn(0,35);break;
	  case 2:Car_Turn(0,30);break;
		case 1:Car_Turn(35,40);break;
	}break;
	case 3:switch(amplitude)
	{
		case 3:Car_Turn(35,0);break;
	  case 2:Car_Turn(30,0);break;
		case 1:Car_Turn(40,35);break;
	}break;
	case 4:Car_Forward(10);break; 
 }
}
