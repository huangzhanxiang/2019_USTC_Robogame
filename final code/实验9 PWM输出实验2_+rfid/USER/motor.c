#include "motor.h"
#include "led.h"
#include "delay.h"
 u16 motor_dutycycle[4] = { 0 };	//各路电机占空比(0~1000)调节速度  ,1~50不转，0满转
u32 PreRotateNum[4] = { 0 };
u32 RotateNum[4] = { 0 };							//存放从开始计数至今的各路电机脉冲数，轮子转一圈输出19*16个脉冲，0~3分别对应M0~M3电机
float Speed[4] = { 0 };   						//4个轮子的线性行进速度，10ms更新一次

//底部驱动电机的IO口初始化程序
void MOTOR_Init(void){
	
	GPIO_InitTypeDef  GPIO_InitStructure;	
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);	//失能STM32 JTAG烧写功能，只能用SWD模式烧写，解放出PA15和PB中部分IO口
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);	//使能PE端口时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);	//使能PG端口时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); 	//开启复用时钟
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_11 | GPIO_Pin_12 |GPIO_Pin_13|GPIO_Pin_14| GPIO_Pin_15;
	//PA10逻辑有问题
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 	//推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 	//IO口速度为50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);								//根据设定参数初始化GPIOA
	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;				//推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;			//IO口速度为50MHz
	GPIO_Init(GPIOG, &GPIO_InitStructure);								//根据设定参数初始化GPIOG
	
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource0);  // 选定GPIOE的Pin0,1,2,3作为外部中断输入源
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

