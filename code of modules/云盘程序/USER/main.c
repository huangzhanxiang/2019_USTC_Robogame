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
  int i;	 
	u16 led0pwmval=0;    //u8 dir=1;	
	delay_init();	    	 //��ʱ������ʼ��	  
	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
	 
	   TIM1_PWM_Init(1439,1443999);//����Ƶ��PWMƵ��=72000/(899+1)=80Khz
     for(i=17;i<81;i++){
      		TIM_SetCompare1(TIM1,i);
		       delay_ms(50);}
		 delay_ms(3000);
     for(i=80;i>55;i--){
      		TIM_SetCompare1(TIM1,i);
		       delay_ms(50);}	
   	 delay_ms(3000);
	   for(i=55;i>30;i--){
      		TIM_SetCompare1(TIM1,i);
		       delay_ms(50);}
		 delay_ms(3000);
	   for(i=30;i>17;i--){
      		TIM_SetCompare1(TIM1,i);
		       delay_ms(50);}	   	 
	   
	   
	  
	 
	   while(1);
}

