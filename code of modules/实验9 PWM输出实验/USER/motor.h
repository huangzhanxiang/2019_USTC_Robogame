//////////////////////////////////////////////////////////////////////////////////
//2019ROBOGAME大赛竞技组_永怀初心队
//底盘电机驱动程序
//整理By hzx @ USTC
//////////////////////////////////////////////////////////////////////////////////
//单片机IO口与电机驱动接口对应关系
//0号电机 PG7-IN4 PC6-IN3 PC8-PWM输入 TIM3——CH3
//1号电机 PG8-IN4 PC7-IN3 PC9-PWM输入 TIM3_CH4
//2号电机 PA12-IN4 PA10-IN3 PA8-PWM输入TIM1_CH1
//3号电机 PA15-IN4 PA11-IN3 PA9-PWM输入 TIM1_CH2
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
#define distance_perimpuls 0.0446249	//每个脉冲产生的轮子线性行进距离，单位CM

extern u16 motor_dutycycle[4] ;	//各路电机占空比(0~1000)调节速度  ,1~50不转，0满转
extern u32 PreRotateNum[4];
extern u32 RotateNum[4];							//存放从开始计数至今的各路电机脉冲数，轮子转一圈输出19*16个脉冲，0~3分别对应M0~M3电机
extern float Speed[4];   						//4个轮子的线性行进速度，10ms更新一次

void MOTOR_Init(void);//初始化
//各轮旋转速度由motor_dutycycle[4]数组来确定(0~100)	
void motor_dir(int motorn,int status);
								
#endif
