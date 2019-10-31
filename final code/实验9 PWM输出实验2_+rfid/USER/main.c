#include "led.h"
#include "stdio.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
#include "motor.h"
#include "infrare.h"
#include "pid_ctrl.h"
#include "follow_line.h"
#include "steer.h"
#include "driver.h"
#include "usart2.h"
/************************************************
 ALIENTEK精英STM32开发板实验9
 PWM输出实验  
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/
//电机：pwm:PC6,7,8,9
//修改占空比：cycle_moto1 cycle_moto2 cycle_moto3 cycle_moto4
//MOTOR1:D13,G7 MOTOR2：A6,G3 MOTOR3:A7,G4 MOTOR4:A5,G5

//步进电机：pwm PB6  cycle_step_moto step_shutdown step_dir
//舵机：PB10，PB11 cycle_steer_down cycle_steer_catch

//步进电机TIM1 CH1 PA8  PC0 PC2
//轮 TIM3 4通道 
//4个爪子 TIM2 PA0，PA1，PB10,PB11
//机械臂舵机 TIM4 PD12(黄色信号)
// 1号轮   0 1 2 3  2号轮
//			12
//			8		       9
//							   10   
// 4号轮11  4 5 6 7  3号轮
 
//1号轮对应0
//红外  PF0-。。。
//rfid : rfid0:PA2,PA3
//rfid1: PA9,PA10
 int main(void)
 {		
	int i;
	int  j;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init();
	uart_init(115200);	 //串口初始化为115200
	
 	LED_Init();			     //LED端口初始化
	TIM3_PWM_Init(7199,0);//电机PWM频率1Khz 用于4个电机pwm输出
	TIM2_PWM_Init(1999,719); //舵机pwm频率50HZ
	TIM4_PWM_Init(1999,719);//舵机0  PD12
	Infrare_Init();
	TIM6_Int_Init(999,71);		//1ms更新一次，用于处理对管信息
	Driver_Init();			//驱动器初始化
	TIM1_OPM_RCR_Init(999,72-1); //1MHz计数频率  单脉冲+重复计数模式	   //步进电机
	uart_init(19200);	 //串口1初始化为19200
	uart2_init(19200);
//	Locate_Rle(200,500,mCW);
//	delay_ms(2000);
//	Locate_Rle(200,500,mCCW);
	 proc_status=0;
	 steer0=1950;
	 steer1=1830;
	 steer2=1900;
	 steer3=1830;
	 steer4=1880;
//while(1)
//{
//	steer4=1880;
//}
//	 while(1)
//	 {
//	int i;
//	while(1)
//	{
//		Locate_Rle(6000,1000,mCW);
//		delay_ms(10000);
//		while(TIM1->CR1&0x01)
//	{
//	}
//			Locate_Rle(1900,1000,mCCW);
//		delay_ms(10000);
//		while(TIM1->CR1&0x01)
//	{
//	}
//	break;
//	}
//	 }
//while(1)
//{
//	Locate_Rle(6000,500,mCW);
//	delay_ms(1000);
//			while(TIM1->CR1&0x01)
//	{
//	}
//		Locate_Rle(1900,500,mCCW);
//	delay_ms(1000);
//				while(TIM1->CR1&0x01)
//	{
//	}
//	break;
//}
////while(1)
//{
//		for(i=1950;i>1700;i--)
//	{
//		steer0=i;
//		steer1=i;
//		steer2=i;
//		steer3=i;
//		steer4=i;
//		delay_ms(100);
//	}
//	
//}
//1750合上
//1830打开
//1950 steer3
//1885 steer4
//1820 steer1
//1750 steer2
//while(1)
//{
//	steer0=1748;
//	delay_ms(10);
//}

	 while(1)
	 {
		follow_line_left();
		 	follow_line();		 
	 }
}


void TIM6_IRQHandler(void)
{

					status[0] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0);
	status[1] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1);
	status[2] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2);
	status[3] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3);
	status[4] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_4);
	status[5] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_5);
	status[6] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_6);
	status[7] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_7);
	status[8] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_8);
	status[9] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_9);
	status[10] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_10);
	status[11] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_11);
	status[12] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_12); 
	
//	if(status[0]==0) printf("1");
//	else printf("0");
		//printf("中断发生");
		printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\r\n",status[0],status[1],status[2],status[3],status[4],status[5],status[6],status[7],status[8],status[9],status[10],status[11],status[12]);
		//printf("%d",status[8]);
		printf(" %d  \r\n",proc_status);
		//printf(" %d\n",status[8]);
//		printf("s9 %d\n",status[9]); 
	//printf("%d,%d,%d,%d,%d,%d,%d\r\n",status[0],status[1],status[6],status[7]);
//	cycle_moto1=cycle_temp[0];
//	cycle_moto2=cycle_temp[1];
//	cycle_moto3=cycle_temp[2];
//	cycle_moto4=cycle_temp[3];
	TIM_ClearITPendingBit(TIM6, TIM_IT_Update);	//	 清空TIM3溢出中断响应函数标志位

	//printf("%d,%d,%d,%d",status[0],status[1],status[2],status[3]);
//	count_time++;
}



