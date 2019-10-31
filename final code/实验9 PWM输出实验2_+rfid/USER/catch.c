#include "delay.h"
#include "driver.h"
#include "led.h"
void catch_first()
{
		int i;
	steer0=1950;
	while(1)
{
	Locate_Rle(2800,1000,mCCW);
		for(i=0;i<20;i++)
	{
		delay_ms(100);
	}
		while(TIM1->CR1&0x01)
	{
	}
		for(i=1830;i>1750;i=i-10)
	{
		steer3=i;
		delay_ms(2);
	}
	delay_ms(1000);
		Locate_Rle(2800,1000,mCW);
		for(i=0;i<20;i++)
	{
		delay_ms(100);
	}
		while(TIM1->CR1&0x01)
	{
	}
	steer0=1885;
	break;
}
//	Locate_Rle(5000,5000,mCW);
//	delay_ms(10000);
//	Locate_Rle(5000,5000,mCCW);
//	delay_ms(10000);	
//	steer0=1950;
//	Locate_Rle(5000,5000,mCW);

//	for(i=0;i<20;i++)
//	{
//		delay_ms(500);
//	}
//		while(TIM1->CR1&0x01)
//	{
//	}
//	for(i=1830;i>1750;i=i-10)
//	{
//		steer3=i;
//		delay_ms(2);
//	}
//	Locate_Rle(5000,5000,mCCW);
//	while(TIM1->CR1&0x01)
//	{
//	}
//	for(i=0;i<20;i++)
//	{
//		delay_ms(500);
//	}
//	delay_ms(10000);
//	delay_ms(10000);
//	for(i=1830;i>1750;i=i-10)
//	{
//		steer3=i;
//		delay_ms(2);
//	}
//	Locate_Rle(5000,500,mCCW);
//	delay_ms(10000);
}


void catch_init()
{
	int i;
	steer0=1950;
	while(1)
	{
		Locate_Rle(6000,1000,mCW);
		delay_ms(10000);
//		for(i=0;i<24;i++)
//	{
//		delay_ms(500);
//	}
		while(TIM1->CR1&0x01)
	{
	}
	break;
	}
	
}

void catch_second()
{
	int i;
	while(1)
	{
		Locate_Rle(2000,1000,mCCW);
		for(i=0;i<20;i++)
	{
		delay_ms(100);
	}
		while(TIM1->CR1&0x01)
	{
	}
		for(i=1830;i>1750;i=i-10)
	{
		steer4=i;
		delay_ms(2);
	}
	delay_ms(1000);
	steer0=1820;
	break;
	
	}

}

void catch_third()
{
	int i;
	while(1)
	{
		Locate_Rle(1900,1000,mCCW);//2100
		for(i=0;i<20;i++)
	{
		delay_ms(100);
	}
		while(TIM1->CR1&0x01)
	{
	}
		for(i=1830;i>1750;i=i-10)
	{
		steer1=i;
		delay_ms(2);
	}
	delay_ms(1000);
//	Locate_Rle(3900,1000,mCW);
//		for(i=0;i<20;i++)
//	{
//		delay_ms(100);
//	}
//		while(TIM1->CR1&0x01)
//	{
//	}
	steer0=1750;
	break;
	
	}
	
}

void catch_forth()
{
		int i;
	while(1)
	{
		Locate_Rle(1900,1000,mCCW);//2100+1900=4000;
		for(i=0;i<20;i++)
	{
		delay_ms(100);
	}
		while(TIM1->CR1&0x01)
	{
	}
		for(i=1830;i>1750;i=i-10)
	{
		steer1=i;
		delay_ms(2);
	}
	delay_ms(1000);
//	Locate_Rle(3900,1000,mCW);
//		for(i=0;i<20;i++)
//	{
//		delay_ms(100);
//	}
//		while(TIM1->CR1&0x01)
//	{
//	}
//	steer0=1750;
	break;
	
	}
}

void catch_stop()
{
		int i;
	while(1)
	{
			Locate_Rle(3900,1000,mCW);//6000;
		for(i=0;i<20;i++)
	{
		delay_ms(100);
	}
		while(TIM1->CR1&0x01)
	{
	}
	break;
	
	}

}

void release_first()
{
	steer0=1950;
	delay_ms(5000);
	steer3=1830;
}

void release_second()
{
	steer0=1885;
	delay_ms(5000);
	steer4=1880;
}

void release_third()
{
		steer0=1820;
	delay_ms(5000);
	steer1=1830;
}

void release_forth()
{
	steer0=1750;
	delay_ms(5000);
	steer2=1880;
}

