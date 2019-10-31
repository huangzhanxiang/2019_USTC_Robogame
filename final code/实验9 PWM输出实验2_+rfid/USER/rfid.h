#ifndef __RFID_H
#define __RFID_H	 
#include "sys.h"


extern	u8 data[100];
extern u8 uid[8];
extern u8 uid2[8];
extern u8 block[4];
extern u8 block2[4];
u8 RFID_READ(u8 *uid,u8 *block);//��ȡrfid��һ������
u8 RFID_Init(void);//��ʼ����������ʹ������
u8 RFID_Disableantenna(void);//�ر����ߣ����ٷ���
u8 GET_UID(u8 *uid);//��ȡUID

u8 RFID2_READ(u8 *uid,u8 *block);//��ȡrfid��һ������
u8 RFID2_Init(void);//��ʼ����������ʹ������
u8 RFID2_Disableantenna(void);//�ر����ߣ����ٷ���
u8 GET_UID2(u8 *uid);//��ȡUID
		 				    
#endif

