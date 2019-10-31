#include "led.h"
#include "delay.h"
#include "sys.h"
#include "pwm.h"
//ALIENTEK Mini STM32开发板范例代码8
//PWM输出实验   
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司

 int main(void)
 {
  int i,a=1;	 
	u16 led0pwmval=0;    //u8 dir=1;	
	delay_init();	    	 //延时函数初始化	  
	LED_Init();		  	//初始化与LED连接的硬件接口
	 TIM1_PWM_Init(1439,1443999);//不分频。PWM频率=72000/(143999+1)=50hz
	 led0pwmval=25;
	 TIM_SetCompare1(TIM1,led0pwmval);//爪子张开
	 delay_ms(3000); //延迟3s   
	 led0pwmval=37;
	 TIM_SetCompare1(TIM1,led0pwmval);//爪子闭合
}

