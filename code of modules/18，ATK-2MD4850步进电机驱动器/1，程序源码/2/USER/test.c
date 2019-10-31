#include "sys.h"
#include "delay.h"
#include "usart.h" 
#include "led.h" 		 	 
#include "key.h"
#include "usmart.h"
#include "driver.h"

//ALIENTEKս��STM32������
//������������� ���Դ���  
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾  

int main(void)
{					    
	u8 i;
	u8 keyval;
	Stm32_Clock_Init(9);	//ϵͳʱ������
	uart_init(72,115200);	//���ڳ�ʼ��Ϊ115200
	delay_init(72);	   	 	//��ʱ��ʼ�� 
	usmart_dev.init(72); 	//��ʼ��USMART				 	
	LED_Init();		  		//��ʼ����LED���ӵ�Ӳ���ӿ�
 	KEY_Init();					//��ʼ������
	Driver_Init();			//��������ʼ��
	TIM8_OPM_RCR_Init(999,72-1); //1MHz����Ƶ��  ������+�ظ�����ģʽ	   
	while(1) 
	{		 	  
		keyval=KEY_Scan(0);
		if(keyval==WKUP_PRES)
		{
			Locate_Abs(0,500);//����WKUP�������
		}else if(keyval==KEY0_PRES)
		{
			Locate_Rle(200,1000,CW);//����KEY0����500Hz��Ƶ�� ˳ʱ�뷢200����
		}else if(keyval==KEY1_PRES)
		{
			Locate_Rle(400,1000,CCW);//����KEY1����500Hz��Ƶ�� ��ʱ�뷢400����
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























