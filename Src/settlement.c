#include "settlement.h"
#include "encoder.h"
#include "tim.h"
#include "chassis.h"
#include "mode.h"


int8_t Encoder_reset=0;


void Displacement_forward(int distance,int speed)
{
 if(Encoder_Sum.Moto1<distance) MotoData.Moto1.targer_speed=speed;
 else MotoData.Moto1.targer_speed=0;

 if(Encoder_Sum.Moto2<distance) MotoData.Moto2.targer_speed=speed;
 else MotoData.Moto2.targer_speed=0;

 if(Encoder_Sum.Moto3<distance) MotoData.Moto3.targer_speed=speed;
 else MotoData.Moto3.targer_speed=0;

 if(Encoder_Sum.Moto4<distance) MotoData.Moto4.targer_speed=speed;
 else MotoData.Moto4.targer_speed=0;
}


void Displacement_back(int distance,int speed)
{
 if(Encoder_Sum.Moto1>-distance) MotoData.Moto1.targer_speed=-speed;
 else MotoData.Moto1.targer_speed=0;

 if(Encoder_Sum.Moto2>-distance) MotoData.Moto2.targer_speed=-speed;
 else MotoData.Moto2.targer_speed=0;

 if(Encoder_Sum.Moto3>-distance) MotoData.Moto3.targer_speed=-speed;
 else MotoData.Moto3.targer_speed=0;

 if(Encoder_Sum.Moto4>-distance) MotoData.Moto4.targer_speed=-speed;
 else MotoData.Moto4.targer_speed=0;
}


void Displacement_Turn_Left(int distance,int speed)
{
 if(Encoder_Sum.Moto1>-distance) MotoData.Moto1.targer_speed=-speed;
 else MotoData.Moto1.targer_speed=0;

 if(Encoder_Sum.Moto2<distance) MotoData.Moto2.targer_speed=speed;
 else MotoData.Moto2.targer_speed=0;

 if(Encoder_Sum.Moto3>-distance) MotoData.Moto3.targer_speed=-speed;
 else MotoData.Moto3.targer_speed=0;

 if(Encoder_Sum.Moto4<distance) MotoData.Moto4.targer_speed=speed;
 else MotoData.Moto4.targer_speed=0;
}


void Displacement_Turn_Right(int distance,int speed)
{
 if(Encoder_Sum.Moto1<distance) MotoData.Moto1.targer_speed=speed;
 else MotoData.Moto1.targer_speed=0;

 if(Encoder_Sum.Moto2>-distance) MotoData.Moto2.targer_speed=-speed;
 else MotoData.Moto2.targer_speed=0;

 if(Encoder_Sum.Moto3<distance) MotoData.Moto3.targer_speed=speed;
 else MotoData.Moto3.targer_speed=0;

 if(Encoder_Sum.Moto4>-distance) MotoData.Moto4.targer_speed=-speed;
 else MotoData.Moto4.targer_speed=0;
}


void Displacement_Settlement(void)
{
	if(Encoder_reset==0)
	{
   Encoder_Zero();
	 Encoder_Sum_Zero();
   Encoder_reset=1;
	}
	Read_Encoder_Sum();
  Displacement_back(300,20);
}
