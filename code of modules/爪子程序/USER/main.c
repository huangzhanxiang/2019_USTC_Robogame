#include "led.h"
#include "delay.h"
#include "sys.h"
#include "pwm.h"
//ALIENTEK Mini STM32�����巶������8
//PWM���ʵ��   
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾

 int main(void)
 {
  int i,a=1;	 
	u16 led0pwmval=0;    //u8 dir=1;	
	delay_init();	    	 //��ʱ������ʼ��	  
	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
	 TIM1_PWM_Init(1439,1443999);//����Ƶ��PWMƵ��=72000/(143999+1)=50hz
	 led0pwmval=25;
	 TIM_SetCompare1(TIM1,led0pwmval);//צ���ſ�
	 delay_ms(3000); //�ӳ�3s   
	 led0pwmval=37;
	 TIM_SetCompare1(TIM1,led0pwmval);//צ�ӱպ�
}

