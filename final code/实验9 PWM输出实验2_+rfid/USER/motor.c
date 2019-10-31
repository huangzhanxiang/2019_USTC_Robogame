#include "motor.h"
#include "led.h"
#include "delay.h"
 u16 motor_dutycycle[4] = { 0 };	//��·���ռ�ձ�(0~1000)�����ٶ�  ,1~50��ת��0��ת
u32 PreRotateNum[4] = { 0 };
u32 RotateNum[4] = { 0 };							//��Ŵӿ�ʼ��������ĸ�·���������������תһȦ���19*16�����壬0~3�ֱ��ӦM0~M3���
float Speed[4] = { 0 };   						//4�����ӵ������н��ٶȣ�10ms����һ��

//�ײ����������IO�ڳ�ʼ������
void MOTOR_Init(void){
	
	GPIO_InitTypeDef  GPIO_InitStructure;	
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);	//ʧ��STM32 JTAG��д���ܣ�ֻ����SWDģʽ��д����ų�PA15��PB�в���IO��
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	//ʹ��PE�˿�ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);	//ʹ��PG�˿�ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); 	//��������ʱ��
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_11 | GPIO_Pin_12 |GPIO_Pin_13|GPIO_Pin_14| GPIO_Pin_15;
	//PA10�߼�������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 	//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 	//IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);								//�����趨������ʼ��GPIOA
	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;				//�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;			//IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOG, &GPIO_InitStructure);								//�����趨������ʼ��GPIOG
	
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource0);  // ѡ��GPIOE��Pin0,1,2,3��Ϊ�ⲿ�ж�����Դ
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource1);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource2);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource3);

}


void  motor_dir(int motorn,int status){
//	delay_ms(5);
	switch(motorn){
		case 0:
			if(status==CW){
				dir_moto1_1=0;
				dir_moto1_2=1;
			  
			}
			else {
			  dir_moto1_1=1;
	      dir_moto1_2=0;
			}
			break;				
		case 1:
			if(status==CW){
			  dir_moto2_1=0;
	      dir_moto2_2=1;
			}
			else {
				dir_moto2_1=1;
	      dir_moto2_2=0;		  
			}
			break;
		case 2:
			if(status==CW){
			  dir_moto3_1=0;
	      dir_moto3_2=1;
			}
			else {
				dir_moto3_1=1;
	     dir_moto3_2=0;		  
			}
			break;
		case 3:
		if(status==CW){
			  dir_moto4_1=0;
				dir_moto4_2=1;
			}
			else {
				 dir_moto4_1=1;
	      dir_moto4_2=0;		  
			}
			break;
			default:
			{
				dir_moto1_1=1;
	      dir_moto1_2=1;
				dir_moto2_1=1;
				dir_moto2_2=1;
				dir_moto3_1=1;
				dir_moto3_2=1;
	      dir_moto4_1=1;
				dir_moto4_2=1;
			}
	
	}	
}

