//////////////////////////////////////////////////////////////////////////////////
//2019ROBOGAME����������_�������Ķ�
//��е�ۿ��Ƴ���
//����By hzx @ USTC
//////////////////////////////////////////////////////////////////////////////////
//��Catch_Steer��Rotate_Steer������������̨�ͻ�е�۵���̬
//R0��L0 +90��ʱ��ʾ�ֱ�ָ��M1�������ץ�췽�򣩣�0��ʱ���۷ֱ�ָ��M2��MO���򣨼��·�������ͼ��
//R1��L1 +90��ʱ��ʾ�ֱ۳��ϣ�0��ʱ�ֱ���ֱ
//R2��L2 +90��ʱ��ʾ��צ�ſ���0��ʱ��צ�պ�
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


extern u16 steer_dutycycle_Right[3];//�Ҳ�����ռ�ձ�(50������~150����~250������) 
extern u16 steer_dutycycle_Left[3];	//�������ռ�ձ�(50������~150����~250������)
extern u16 Pwm_50Hz; 										//����50Hz��PWM�������ڶ������

void Steer_Init(void);//��е�۶��IO�ڳ�ʼ������
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
void PutFlag_Right_Left_Ready(void);           //׼���������
void PutFlag_Right_Left_Start(void);           //�������
void PutFlag_Right_Left_End(void);
void PutFlag_High_Ready(void);
void PutFlag_High_Move(void);
void PutFlag_High_Put(void);    //�͸�ʱ�������
void PutFlag_Right_Left_Ready_LSJR(void);           //׼���������
void PutFlag_Right_Left_Start_LSJR(void);           //�������
void PutFlag_Right_Left_End_LSJR(void);

#endif

