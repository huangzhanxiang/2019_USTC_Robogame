#ifndef __INFRARE_H
#define __INFRARE_H	 
#include "sys.h"

void Infrare_Init(void);//红外对管IO口初始化程序
extern u8 status[16];
extern u16 status_GPIOF;//16位GPIOF状态
extern u16 status_GPIOC;//16位GPIOC状态
extern u16 status_GPIOA;//16位GPIOF状态

#endif

