#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK��ӢSTM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
#define step_shutdown PDout(11)// PB5
#define step_dir PDout(12)
//#define Down_b7 PDout(13)
#define dir_moto1_1 PDout(13)// PB5
#define dir_moto2_1 PAout(6)
#define dir_moto3_1 PAout(7)
#define dir_moto4_1  PAout(5)
//#define Up5 PDout(11)

#define dir_moto1_2 PGout(7)
#define dir_moto2_2 PGout(3)
#define dir_moto3_2 PGout(4)
#define dir_moto4_2 PGout(5)

#define status0 PFin(0);
#define status1 PFin(1);
#define status2 PFin(2);
#define status3 PFin(3);
#define status4 PFin(4);
#define status5 PFin(5);
#define status6 PFin(6);
#define status7 PFin(7);
 void LED_Init(void);//��ʼ��

		 				    
#endif
