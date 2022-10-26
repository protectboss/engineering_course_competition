#include "mode.h"
#include "tim.h"
#include "chassis.h"
#include "settlement.h"
#include "tracking.h"
#include "pid.h"
#include "encoder.h"
#include "steering_engine.h"
#include "opencv.h"

int flag_ballon2=0;
int8_t Step=1;
int Steering_engine_time=0;



void Step_One(void)
{
 Read_GPIO();
 Read_Encoder_Speed();
 Judge_Turn_Amplitude();
 Car_Target_Speed();
 WZ_Pid_Calculation();
 Chassis_WZPid_Output();
 Steering_Engine_Stop();
 if(write_time==600) Step=2;
 if(flag_ballon==1&&flag_ballon2==0) 
 {
	 Step=3;
	 flag_ballon2=1;
 }

}


void Step_Two(void)
{
 Chassis_Output_Zero();
 Steering_Engine_Stop();
}


void Step_Three(void)
{
	static int flag=0;
	if(flag==0)
	{
  Displacement_Settlement();
	Read_Encoder_Speed();
	WZ_Pid_Calculation();
	Chassis_WZPid_Output();
	if(MotoData.Moto1.targer_speed==0&&MotoData.Moto2.targer_speed==0&&MotoData.Moto3.targer_speed==0&&MotoData.Moto4.targer_speed==0) flag=1;
	}
	if(flag==1)
	{
  if(Steering_engine_time>240)
  {
	  Step=4;
	  write_time=0;
  }
  if(Steering_engine_time<170) 
  {
	  Steering_Engine_Prick_Balloon();
	  Steering_engine_time++;
    Read_Encoder_Speed();
	  Car_Forward(0);
	  WZ_Pid_Calculation();
	  Chassis_WZPid_Output();
  }
  if(Steering_engine_time>=170&&Steering_engine_time<=240) 
  {
	  Steering_Engine_Stop();
	  Steering_engine_time++;
    Read_Encoder_Speed();
	  Car_Forward(0);
	  WZ_Pid_Calculation();
	  Chassis_WZPid_Output();
  }
 }
}


void Step_Four(void)
{
 Read_GPIO();
 Read_Encoder_Speed();
 Judge_Turn_Amplitude();
 Car_Target_Speed2();
 WZ_Pid_Calculation();
 Chassis_WZPid_Output();
 if(write_time==400) Step=2;
 Steering_Engine_Stop();
}

void Step_Judge(void)
{
 switch(Step)
 {
	 case 1:Step_One();break;
	 case 2:Step_Two();break;
	 case 3:Step_Three();break;
	 case 4:Step_Four();break;
 }
}

