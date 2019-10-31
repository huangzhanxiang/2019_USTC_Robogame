#include "sys.h"
#include "delay.h"
#include "usart.h" 
#include "led.h" 		 	 
#include "key.h"
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
	Stm32_Clock_Init(9);	//系统时钟设置
	uart_init(72,115200);	//串口初始化为115200
	delay_init(72);	   	 	//延时初始化 
	usmart_dev.init(72); 	//初始化USMART				 	
	LED_Init();		  		//初始化与LED连接的硬件接口
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
			Locate_Rle(200,1000,CW);//按下KEY0，以500Hz的频率 顺时针发200脉冲
		}else if(keyval==KEY1_PRES)
		{
			Locate_Rle(400,1000,CCW);//按下KEY1，以500Hz的频率 逆时针发400脉冲
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























