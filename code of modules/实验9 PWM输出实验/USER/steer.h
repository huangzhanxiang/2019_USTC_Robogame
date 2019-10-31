//////////////////////////////////////////////////////////////////////////////////
//2019ROBOGAME大赛竞技组_永怀初心队
//机械臂控制程序
//整理By hzx @ USTC
//////////////////////////////////////////////////////////////////////////////////
//用Catch_Steer、Rotate_Steer函数来控制云台和机械臂的姿态
//R0、L0 +90°时表示手臂指向M1电机方向（抓旗方向），0°时两臂分别指向M2、MO方向（见下方车身俯视图）
//R1、L1 +90°时表示手臂朝上，0°时手臂伸直
//R2、L2 +90°时表示手爪张开，0°时手爪闭合
//R2->PB4 R1->PB6 R0->PB8
//L2->PB5 L1->PB7 L0->PB9
//////////////////////////////////////////////////////////////////////////////////
#ifndef __STEER_H
#define __STEER_H	 
#include "sys.h"

#define steer_speed 5
#define catch_tang 105
#define catch_L 30
#define catch_R 25
#define R1_elevation 5
#define L1_elevation 5
#define  cycle_step_moto TIM4->CCR1 
#define  cycle_steer_down TIM2->CCR3 
#define  cycle_steer_catch TIM2->CCR4 


extern u16 steer_dutycycle_Right[3];//右侧舵机的占空比(50左满舵~150居中~250右满舵) 
extern u16 steer_dutycycle_Left[3];	//左侧舵机的占空比(50左满舵~150居中~250右满舵)
extern u16 Pwm_50Hz; 										//产生50Hz的PWM波，用于舵机控制

void Steer_Init(void);//机械臂舵机IO口初始化程序
void Right_Steer(int a0,int a1,int a2); //angle0(-135~135),angle1(-135~135),angle2(0~90)
void Left_Steer(int a0,int a1,int a2); 	//angle0(-135~135),angle1(-135~135),angle2(0~90)
void CatchFlag_Right_Ready(void);
void CatchFlag_Right_Start(void);
void CatchFlag_Left_Ready(void);
void CatchFlag_Left_Start(void);
void CatchFlag_Left_End(void);
void CatchFlag_Right_End(void);
void CatchFlag_Right_Finish_Left_Ready_RFID(void);
void CatchFlag_Left_Finish_Right_Ready_RFID(void);
void PutFlag_Right_Left_Ready(void);           //准备放置物块
void PutFlag_Right_Left_Start(void);           //放置物块
void PutFlag_Right_Left_End(void);
void PutFlag_High_Ready(void);
void PutFlag_High_Move(void);
void PutFlag_High_Put(void);    //低杆时放置物块
void PutFlag_Right_Left_Ready_LSJR(void);           //准备放置物块
void PutFlag_Right_Left_Start_LSJR(void);           //放置物块
void PutFlag_Right_Left_End_LSJR(void);

#endif

