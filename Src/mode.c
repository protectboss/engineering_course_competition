#include "mode.h"
#include "tim.h"
#include "chassis.h"
#include "settlement.h"
#include "tracking.h"
#include "pid.h"
#include "encoder.h"


int8_t Step=1;


//void Step_One(void)
//{
// Displacement_Settlement();
// WZ_Pid_Calculation();
// Chassis_WZPid_Output();
// if(MotoData.Moto1.targer_speed==0&&MotoData.Moto2.targer_speed==0&&MotoData.Moto3.targer_speed==0&&MotoData.Moto4.targer_speed==0)
// {
//  Step=2;
// }
//}
void Step_One(void)
{
 Read_GPIO();
 Read_Encoder_Speed();
 Judge_Turn_Amplitude();
 Car_Target_Speed();
 WZ_Pid_Calculation();
 Chassis_WZPid_Output();
 if(write_time==400) Step=2;
}


void Step_Two(void)
{
	Chassis_Output_Zero();
}


void Step_Judge(void)
{
 switch(Step)
 {
	 case 1:Step_One();break;
	 case 2:Step_Two();break;
 }
}

