#include "infrare.h"
u8 status[16] = { 0};
u16 status_GPIOF = 0;//16λGPIOF״̬


//����GPIO�ڵ���PF��PE�����ã�ȫ������Ϊ��������
void Infrare_Init(void)
{
	
		GPIO_InitTypeDef GPIO_InitStructure;
  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOA, ENABLE);	//ʹ��PA�˿�ʱ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOF, &GPIO_InitStructure);
	
}
