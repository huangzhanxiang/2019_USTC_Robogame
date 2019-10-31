//////////////////////////////////////////////////////////////////////////////////
//2019ROBOGAME����������_�������Ķ�
//���̵����������
//����By hzx @ USTC
//////////////////////////////////////////////////////////////////////////////////
//��Ƭ��IO�����������ӿڶ�Ӧ��ϵ
//0�ŵ�� PG7-IN4 PC6-IN3 PC8-PWM���� TIM3����CH3
//1�ŵ�� PG8-IN4 PC7-IN3 PC9-PWM���� TIM3_CH4
//2�ŵ�� PA12-IN4 PA10-IN3 PA8-PWM����TIM1_CH1
//3�ŵ�� PA15-IN4 PA11-IN3 PA9-PWM���� TIM1_CH2
//All rights reserved
#define  cycle_moto1 TIM3->CCR1 
#define  cycle_moto2 TIM3->CCR2
#define  cycle_moto3 TIM3->CCR3 
#define  cycle_moto4 TIM3->CCR4 
//////////////////////////////////////////////////////////////////////////////////
#ifndef __MOTOR_H
#define __MOTOR_H	 
#include "sys.h"
 
#define CW 0
#define ACW 1
#define motor0 0
#define motor1 1
#define motor2 2
#define motor3 3
#define distance_perimpuls 0.0446249	//ÿ��������������������н����룬��λCM

extern u16 motor_dutycycle[4] ;	//��·���ռ�ձ�(0~1000)�����ٶ�  ,1~50��ת��0��ת
extern u32 PreRotateNum[4];
extern u32 RotateNum[4];							//��Ŵӿ�ʼ��������ĸ�·���������������תһȦ���19*16�����壬0~3�ֱ��ӦM0~M3���
extern float Speed[4];   						//4�����ӵ������н��ٶȣ�10ms����һ��

void MOTOR_Init(void);//��ʼ��
//������ת�ٶ���motor_dutycycle[4]������ȷ��(0~100)	
void motor_dir(int motorn,int status);
								
#endif
