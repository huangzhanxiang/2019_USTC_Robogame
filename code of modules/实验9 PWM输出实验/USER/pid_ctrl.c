#include "motor.h"
#include "pid_ctrl.h"
#include "math.h"
#include "motor.h"
#include "usart.h"
int set_speed[4] ;
float actual_speed[4] = { 0 };
float error[4] = { 0 };
float error_last[4] = { 0 };
float error_sum[4] = { 0 };
int cycle_temp[4];
float kp[4] = { 4.5,4.5,4.5,4.5 }, ki[4] = { 0.55,0.55,0.55,0.55 }, kd[4] = { 0,0,0,0 };
float ctrl[4] = { 0 };

void setspeed(int m1,int m2,int m3,int m4)
{
//	cycle_moto1= m1;
//	cycle_moto2= m2;
//	cycle_moto3= m3;
//	cycle_moto4= m4;
	cycle_temp[0]=m1;
	cycle_temp[1]=m2;
	cycle_temp[2]=m3;
	cycle_temp[3]=m4;
	
}
void setdir(int i)
{
	switch(i){
		case 1:
			//Ö±ÐÐ
			motor_dir(motor0, CW);
		motor_dir(motor1, CW);
			motor_dir(motor2, CW);
		motor_dir(motor3, CW);
		break ;
		default :
		motor_dir(motor0, CW);
		motor_dir(motor1, CW);
		motor_dir(motor2, CW);
		motor_dir(motor3, CW);
		break;
	}
}
//	set_speed[0] = fabs(speed0);
//	if (speed0>0)
//		motor_dir(motor0, CW);
//	else if (speed0<0)
//		motor_dir(motor0, ACW);

//	set_speed[1] = fabs(speed1);
//	if (speed1>0)
//		motor_dir(motor1, CW);
//	else if (speed1<0)
//		motor_dir(motor1, ACW);

//	set_speed[2] = fabs(speed2);
//	if (speed2>0)
//		motor_dir(motor2, CW);
//	else if (speed2<0)
//		motor_dir(motor2, ACW);

//	set_speed[3] = fabs(speed3);
//	if (speed3>0)
//		motor_dir(motor3, CW);
//	else if (speed3<0)
//		motor_dir(motor3, ACW);



void Pid_ctrl()
{

}
