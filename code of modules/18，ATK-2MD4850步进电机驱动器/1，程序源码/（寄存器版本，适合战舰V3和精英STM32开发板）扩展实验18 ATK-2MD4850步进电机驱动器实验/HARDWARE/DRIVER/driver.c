#include "driver.h"
#include "delay.h"
#include "usart.h"

//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//�������вο���̳�������̵�һ����(http://www.openedv.com/thread-41832-1-1.html)
//ALIENTEKս��STM32������
//������������� ���Դ���			   
//lycreturn@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2016/05/12
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved	
//********************************************************************************
//�޸�����:2016/05/12
//////////////////////////////////////////////////////////////////////////////////
/********** ������ �˿ڶ��� **************
//DRIVER_DIR   PC0 (OV_D0)
//DRIVER_OE    PC2 (OV_D2)
//STEP_PULSE   PC7 (TIM8_CH2,OV_D7)
******************************************/

u8 rcr_remainder;   //�ظ�������������
u8 is_rcr_finish=1; //�ظ��������Ƿ��������
long rcr_integer;	//�ظ�������������
long target_pos=0;  //�з��ŷ���
long current_pos=0; //�з��ŷ���
DIR_Type motor_dir=CW;//˳ʱ��

/************** �����������ź��߳�ʼ�� ****************/
void Driver_Init(void)
{
	RCC->APB2ENR|=1<<4; //GPIOCʱ��ʹ��
	
	GPIOC->CRL&=0XFFFFF0F0;	//PC0,2�������
	GPIOC->CRL|=0X00000303;	//PC0,2�������
	DRIVER_DIR=1;   //PC0����� ˳ʱ�뷽��
	DRIVER_OE=0; 	//PC2����� ʹ�����
}

/***********************************************
//TIM8_CH2(PC7) ���������+�ظ��������ܳ�ʼ��
//TIM8 ʱ��Ƶ�� 72MHz
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
************************************************/
void TIM8_OPM_RCR_Init(u16 arr,u16 psc)
{		 					 
	//�˲������ֶ��޸�IO������
	RCC->APB2ENR|=1<<13; 	//TIM8ʱ��ʹ�� 
	RCC->APB2ENR|=1<<4; 	//GPIOCʱ��ʹ��	
	GPIOC->CRL&=0X0FFFFFFF;	//PC7���֮ǰ������
	GPIOC->CRL|=0XB0000000;	//���ù������  
	
	TIM8->ARR=arr;			//�趨�������Զ���װֵ 
	TIM8->PSC=psc;			//Ԥ��Ƶ������	
	TIM8->CCR2=TIM8->ARR>>1;//�Ƚ�ֵ
	TIM8->CR1|=1<<2;   		//����ֻ�м��������Ϊ�����ж�
	TIM8->CR1|=1<<3;   		//������ģʽ
	TIM8->CCMR1|=7<<12;  	//CH2 PWM2ģʽ	
	TIM8->CCMR1|=1<<11; 	//CH2Ԥװ��ʹ��			
	TIM8->CCER|=1<<4;   	//OC2 ���ʹ��	  
	TIM8->CR1|=0x0080;   	//ARPEʹ�� 
	TIM8->DIER|=1<<0;   	//��������ж�
	MY_NVIC_Init(1,1,TIM8_UP_IRQn,2);//��ռ1�������ȼ�1����2	
	TIM8->SR=0;//������б�־λ
	TIM8->CR1|=0x01; //ʹ�ܶ�ʱ��8 										  
}
/******* TIM8�����жϷ������ *********/
void TIM8_UP_IRQHandler(void)
{
	if(TIM8->SR&(1<<0))//�����ж�
	{
		TIM8->SR&=~(1<<0);//��������жϱ�־λ	
		if(is_rcr_finish==0)//�ظ�������δ�������
		{
			if(rcr_integer!=0) //�����������廹δ�������
			{
				TIM8->RCR=RCR_VAL;//�����ظ�����ֵ
				rcr_integer--;//����RCR_VAL+1������				
			}else if(rcr_remainder!=0)//������������ ��λ0
			{
				TIM8->RCR=rcr_remainder-1;//������������
				rcr_remainder=0;//����
				is_rcr_finish=1;//�ظ��������������				
			}else goto out;   //rcr_remainder=0��ֱ���˳�			
			TIM8->EGR|=0x01;  //����һ�������¼� ���³�ʼ��������
			TIM8->BDTR|=1<<15;//MOE �����ʹ��
			TIM8->CR1|=0x01;  //ʹ�ܶ�ʱ��8			
			if(motor_dir==CW) //�������Ϊ˳ʱ��   
				current_pos+=(TIM8->RCR+1);//�����ظ�����ֵ
			else          //������Ϊ��ʱ��
				current_pos-=(TIM8->RCR+1);//��ȥ�ظ�����ֵ			
		}else
		{
out:		is_rcr_finish=1;//�ظ��������������
			TIM8->BDTR&=~(1<<15);//MOE �ر������
			TIM8->CR1&=~(1<<0);  //�رն�ʱ��8						
			printf("��ǰλ��=%ld\r\n",current_pos);//��ӡ���
		}	
	}
}
/***************** ����TIM8 *****************/
void TIM8_Startup(u32 frequency)   //������ʱ��8
{
	TIM8->ARR=1000000/frequency-1; //�趨��װֵ	
	TIM8->CCR2=TIM8->ARR>>1;   //ƥ��ֵ2������װֵһ�룬����ռ�ձ�Ϊ50%	
	TIM8->CNT=0;//����������
	TIM8->CR1|=1<<0;   //������ʱ��TIM8����
}
/********************************************
//��Զ�λ���� 
//num 0��2147483647
//frequency: 20Hz~100KHz
//dir: CW(˳ʱ�뷽��)  CCW(��ʱ�뷽��)
*********************************************/
void Locate_Rle(long num,u32 frequency,DIR_Type dir) //��Զ�λ����
{
	if(num<=0) //��ֵС����0 ��ֱ�ӷ���
	{
		printf("\r\nThe num should be greater than zero!!\r\n");
		return;
	}
	if(TIM8->CR1&0x01)//��һ�����廹δ�������  ֱ�ӷ���
	{
		printf("\r\nThe last time pulses is not send finished,wait please!\r\n");
		return;
	}
	if((frequency<20)||(frequency>100000))//����Ƶ�ʲ��ڷ�Χ�� ֱ�ӷ���
	{
		printf("\r\nThe frequency is out of range! please reset it!!(range:20Hz~100KHz)\r\n");
		return;
	}
	motor_dir=dir;//�õ�����	
	DRIVER_DIR=motor_dir;//���÷���
	
	if(motor_dir==CW)//˳ʱ��
		target_pos=current_pos+num;//Ŀ��λ��
	else if(motor_dir==CCW)//��ʱ��
		target_pos=current_pos-num;//Ŀ��λ��
	
	rcr_integer=num/(RCR_VAL+1);//�ظ�������������
	rcr_remainder=num%(RCR_VAL+1);//�ظ�������������
	is_rcr_finish=0;//�ظ�������δ�������
	TIM8_Startup(frequency);//����TIM8
}
/********************************************
//���Զ�λ���� 
//num   -2147483648��2147483647
//frequency: 20Hz~100KHz
*********************************************/
void Locate_Abs(long num,u32 frequency)//���Զ�λ����
{
	if(TIM8->CR1&0x01)//��һ�����廹δ������� ֱ�ӷ���
	{
		printf("\r\nThe last time pulses is not send finished,wait please!\r\n");
		return;
	}
	if((frequency<20)||(frequency>100000))//����Ƶ�ʲ��ڷ�Χ�� ֱ�ӷ���
	{
		printf("\r\nThe frequency is out of range! please reset it!!(range:20Hz~100KHz)\r\n");
		return;
	}
	target_pos=num;//����Ŀ��λ��
	if(target_pos!=current_pos)//Ŀ��͵�ǰλ�ò�ͬ
	{
		if(target_pos>current_pos)
			motor_dir=CW;//˳ʱ��
		else
			motor_dir=CCW;//��ʱ��
		DRIVER_DIR=motor_dir;//���÷���
		
		rcr_integer=abs(target_pos-current_pos)/(RCR_VAL+1);//�ظ�������������
		rcr_remainder=abs(target_pos-current_pos)%(RCR_VAL+1);//�ظ�������������
		is_rcr_finish=0;//�ظ�������δ�������
		TIM8_Startup(frequency);//����TIM8
	}
}





