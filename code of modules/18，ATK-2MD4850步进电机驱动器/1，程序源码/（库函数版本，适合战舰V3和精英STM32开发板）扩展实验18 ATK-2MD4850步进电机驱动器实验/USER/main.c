#include "sys.h"
#include "usart.h"
#include "delay.h"
#include "key.h"
#include "led.h"	 
#include "usmart.h"	
#include "driver.h"

//ALIENTEK战舰STM32开发板
//步进电机驱动器 测试代码  
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司
	
int main(void)
{	 
	u8 i;
	u8 keyval;
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 	//串口初始化为115200
	usmart_dev.init(72); 	//初始化USMART	
	LED_Init();			     //LED端口初始化
	KEY_Init();					//初始化按键
	Driver_Init();			//驱动器初始化
	TIM8_OPM_RCR_Init(999,72-1); //1MHz计数频率  单脉冲+重复计数模式	   
	while(1) 
	{		 	  
		keyval=KEY_Scan(0);
		if(keyval==WKUP_PRES)
		{
			Locate_Abs(0,500);//按下WKUP，回零点
		}else if(keyval==KEY0_PRES)
		{
			Locate_Rle(200,500,CW);//按下KEY0，以500Hz的频率 顺时针发200脉冲
		}else if(keyval==KEY1_PRES)
		{
			Locate_Rle(400,500,CCW);//按下KEY1，以500Hz的频率 逆时针发400脉冲
		}			
		delay_ms(10);
		i++;
		if(i==50)	
		{	
			i=0;
			LED1=!LED1;
		}
	}			
}

