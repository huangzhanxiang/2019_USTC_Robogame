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
/************************************************
 ALIENTEK��ӢSTM32������ʵ��9
 PWM���ʵ��  
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/
//�����pwm:PC6,7,8,9
//�޸�ռ�ձȣ�cycle_moto1 cycle_moto2 cycle_moto3 cycle_moto4
//MOTOR1:A13,G7 MOTOR2��A6,G3 MOTOR3:A7,G4 MOTOR4:A5,G5
//���������pwm PB6  cycle_step_moto step_shutdown step_dir
//�����PB10��PB11 cycle_steer_down cycle_steer_catch
//    0  1
//4					6
//5					7
//    2  3

//1���ֶ�Ӧ0
int temp,temp1;
volatile u32 count_time=0;

 int main(void)
 {		
	int i;
	 	u8 t=0;
	//nvic_init();
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	 	delay_init();
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
 	LED_Init();			     //LED�˿ڳ�ʼ��

	//exti_init();
	TIM3_PWM_Init(999,71);//���PWMƵ��1Khz ����4�����pwm���
	TIM2_PWM_Init(19999,71); //���pwmƵ��50HZ
	TIM4_PWM_Init(999,71);//�������PWMƵ��1Khz 
	//MOTOR_Init();						//�ײ����������IO�ڳ�ʼ������
	Infrare_Init();
	//TIM5_Int_Init(29999,71);//30ms����һ�Σ����ڼ���ʵʱ����
	TIM6_Int_Init(9999,7100);		//1ms����һ�Σ����ڴ���Թ���Ϣ
//	cycle_moto4=800;
	 cycle_steer_down=9999;
	 cycle_steer_catch=9999;
	 cycle_step_moto=800;
//setspeed(900,800,700,600);
//	while(1)
//	{
//		setdir(1);
//	//printf("dfsjafd85;
//		delay_ms(500);
//	}
	cycle_moto1=850;
	cycle_moto2=850;
	cycle_moto4=850;
	cycle_moto3=850;
	
	//setspeed(800,800,800,800);
	 while(1)
	 {
		follow_line_left();
		 	follow_line();		 
	 }
}
 
 
//void TIM5_IRQHandler(void){
//	//Pid_ctrl();
//	//printf("�ɹ�ִ��");
////	uart_send_mydata(cmdf, sizeof(cmdf));
////  uart_send_mydata((u8 *)Speed, sizeof(Speed));
////	uart_send_mydata(cmdr, sizeof(cmdr));
////	follow_line();

//// save_history();
////	printf("%d %d %d %d %d%d\n",proc_status,cur_nodenum,status[0],status[1],status[2],status[3])
//	TIM_ClearITPendingBit(TIM5, TIM_IT_Update);		//���TIM3����ж���Ӧ������־λ
//}


//void TIM3_IRQHandler(void)   //TIM3�ж�
//{
//	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //���TIM3�����жϷ������
//		{
//				status[0] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0);
//	status[1] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1);
//	status[2] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2);
//	status[3] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3);
//	status[4] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_4);
//	status[5] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_5);
//	status[6] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_6);
//	TIM_ClearITPendingBit(TIM6, TIM_IT_Update);	//	 ���TIM3����ж���Ӧ������־λ
//	printf("dkdsf");
//		TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //���TIMx�����жϱ�־ 
//		}
//}

void TIM6_IRQHandler(void)
{
//	status_GPIOF = GPIO_ReadInputData(GPIOF);
//	status[0] = status_GPIOF & 0x00ff;
//	status[1] = status_GPIOF & 0x0002;
//	status[2] = status_GPIOF & 0x0004;
//status[3] = status_GPIOF & 0x0008;
//status[4] = status_GPIOF & 0x0010;
//	status[5] = status_GPIOF & 0x0020;
//	status[6] = status_GPIOF & 0x0040;
	
					status[0] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0);
	status[1] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1);
	status[2] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2);
	status[3] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3);
	status[4] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_4);
	status[5] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_5);
	status[6] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_6);
	status[7] = GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_7);
//	if(status[0]==0) printf("1");
//	else printf("0");
		//printf("�жϷ���");
		printf("%d,%d,%d,%d,%d,%d,%d,%d\r\n",status[0],status[1],status[2],status[3],status[4],status[5],status[6],status[7]);
	//printf("%d,%d,%d,%d,%d,%d,%d\r\n",status[0],status[1],status[6],status[7]);
	cycle_moto1=cycle_temp[0];
	cycle_moto2=cycle_temp[1];
	cycle_moto3=cycle_temp[2];
	cycle_moto4=cycle_temp[3];
	TIM_ClearITPendingBit(TIM6, TIM_IT_Update);	//	 ���TIM3����ж���Ӧ������־λ

	//printf("%d,%d,%d,%d",status[0],status[1],status[2],status[3]);
//	count_time++;
}

//void EXTI0_IRQHandler(void)
//{
//	EXTI_ClearITPendingBit(EXTI_Line0);
//	RotateNum[0]++;
//}

//void EXTI1_IRQHandler(void)
//{
//	EXTI_ClearITPendingBit(EXTI_Line1);
//	RotateNum[1]++;
//}
//void EXTI2_IRQHandler(void)
//{
//	EXTI_ClearITPendingBit(EXTI_Line2);
//	RotateNum[2]++;
//}

//void EXTI3_IRQHandler(void)
//{
//	EXTI_ClearITPendingBit(EXTI_Line3);
//	RotateNum[3]++;
//}


