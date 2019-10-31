#include "sys.h"
#include "usart.h"
#include "delay.h"
#include "key.h"
#include "led.h"	 
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
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
	usmart_dev.init(72); 	//��ʼ��USMART	
	LED_Init();			     //LED�˿ڳ�ʼ��
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
			Locate_Rle(200,500,CW);//����KEY0����500Hz��Ƶ�� ˳ʱ�뷢200����
		}else if(keyval==KEY1_PRES)
		{
			Locate_Rle(400,500,CCW);//����KEY1����500Hz��Ƶ�� ��ʱ�뷢400����
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

