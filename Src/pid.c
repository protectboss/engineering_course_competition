#include "pid.h"
#include "tim.h"
#include "chassis.h"


#define LIMIT(x,min,max) x=(x<(min)?min:((x>=max)?max:x))


/*位置pid*/
void WZPid(WZPID_TypeDef *WZpid,float target,float real)
{
 WZpid->error_last=WZpid->error;
 WZpid->error=target-real;
 WZpid->output=(WZpid->error-WZpid->error_last)*WZpid->Kd;//微分部分
 WZpid->output+=(WZpid->error*WZpid->Kp);//误差部分
 WZpid->integral+=(WZpid->error*WZpid->Ki);//积分部分 
 LIMIT(WZpid->integral,-WZpid->integral_max,WZpid->integral_max);
 WZpid->output+=WZpid->integral;
 LIMIT(WZpid->output,-WZpid->output_max,WZpid->output_max);
}

void WZPid_Init(WZPID_TypeDef *WZpid,float p,float i,float d,float Integral_max,float Out_max)
{
 WZpid->Kp=p;
 WZpid->Ki=i;
 WZpid->Kd=d;
 WZpid->integral_max=Integral_max;
 WZpid->output_max=Out_max;
}


WZPID_NumberTypeDef Pid;
void ALL_Pid_Init(void)
{
 WZPid_Init(&Pid.No1,100,0.1,0,950,950);
 WZPid_Init(&Pid.No2,100,0.1,0,950,950);
 WZPid_Init(&Pid.No3,100,0.1,0,950,950);
 WZPid_Init(&Pid.No4,100,0.1,0,950,950);
}


void WZ_Pid_Calculation(void)
{
 	WZPid(&Pid.No1,MotoData.Moto1.targer_speed,MotoData.Moto1.encoder);
	WZPid(&Pid.No2,MotoData.Moto2.targer_speed,MotoData.Moto2.encoder);
	WZPid(&Pid.No3,MotoData.Moto3.targer_speed,MotoData.Moto3.encoder);
	WZPid(&Pid.No4,MotoData.Moto4.targer_speed,MotoData.Moto4.encoder);
}

void Chassis_WZPid_Output(void)
{
	Moto1_Speed_Output(Pid.No1.output);
	Moto2_Speed_Output(Pid.No2.output);
	Moto3_Speed_Output(Pid.No3.output);
	Moto4_Speed_Output(Pid.No4.output);
}

void Chassis_Output_Zero(void)
{
	Moto1_Speed_Output(0);
	Moto2_Speed_Output(0);
	Moto3_Speed_Output(0);
	Moto4_Speed_Output(0);
}
