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
 if(write_time==400) Step=2;
 Steering_Engine_Stop();
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
 if(Steering_engine_time>240) Step=1;
 if(Steering_engine_time<170) 
 {
	 Steering_Engine_Prick_Balloon();
	 Steering_engine_time++;
   Chassis_Output_Zero();
 }
 if(Steering_engine_time>=170&&Steering_engine_time<=240) 
 {
	 Steering_Engine_Stop();
	 Steering_engine_time++;
   Chassis_Output_Zero();
 }
}


void Step_Judge(void)
{
 switch(Step)
 {
	 case 1:Step_One();break;
	 case 2:Step_Two();break;
	 case 3:Step_Three();break;
 }
}

