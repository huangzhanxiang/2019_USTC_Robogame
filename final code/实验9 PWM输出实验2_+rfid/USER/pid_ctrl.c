#include "motor.h"
#include "pid_ctrl.h"
#include "math.h"
#include "motor.h"
#include "usart.h"
#include "led.h"
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
	cycle_moto1= m1;
	cycle_moto2= m2;
	cycle_moto3= m3;
	cycle_moto4= m4;
//	cycle_temp[0]=m1;
//	cycle_temp[1]=m2;
//	cycle_temp[2]=m3;
//	cycle_temp[3]=m4;
	
}
void setdir(int i)
{
	switch(i){
		case 1:
			//ֱ��
			motor_dir(motor0, ACW);
		motor_dir(motor1, ACW);
			motor_dir(motor2, CW);
		motor_dir(motor3, CW);
		break ;
		case 2:
			//��ƽ��
		motor_dir(motor0, ACW);
		motor_dir(motor1, CW);
		motor_dir(motor2, CW);
		motor_dir(motor3, ACW);
		break;
		case 3:
			//��ƽ��
		motor_dir(motor0, CW);
		motor_dir(motor1, ACW);
		motor_dir(motor2, ACW);
		motor_dir(motor3, CW);		
		break;
		case 4:
			//��ʱ����ת
				motor_dir(motor0, CW);
		motor_dir(motor1, ACW);
		motor_dir(motor2, CW);
		motor_dir(motor3, ACW);	
		break;
		case 5:
			//ֹͣ 
				dir_moto1_1=0;
	      dir_moto1_2=0;
				dir_moto2_1=0;
				dir_moto2_2=0;
				dir_moto3_1=0;
				dir_moto3_2=0;
	      dir_moto4_1=0;
				dir_moto4_2=0;
		break;
		case 6:
			//˳ʱ����ת
   	motor_dir(motor0, ACW);
		motor_dir(motor1, CW);
		motor_dir(motor2, ACW);
		motor_dir(motor3, CW);	
    break;		
		
		case 7:
			//����
					motor_dir(motor0, CW);
		motor_dir(motor1, CW);
			motor_dir(motor2, ACW);
		motor_dir(motor3, ACW);
		break;
		default :
		motor_dir(motor0, CW);
		motor_dir(motor1, CW);
		motor_dir(motor2, CW);
		motor_dir(motor3, CW);
		break;
	}
}


void Pid_ctrl()
{

}
