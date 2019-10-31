#ifndef __RFID_H
#define __RFID_H	 
#include "sys.h"


extern	u8 data[100];
extern u8 uid[8];
extern u8 uid2[8];
extern u8 block[4];
extern u8 block2[4];
u8 RFID_READ(u8 *uid,u8 *block);//读取rfid第一块数据
u8 RFID_Init(void);//初始化读卡器，使能天线
u8 RFID_Disableantenna(void);//关闭天线，减少发热
u8 GET_UID(u8 *uid);//获取UID

u8 RFID2_READ(u8 *uid,u8 *block);//读取rfid第一块数据
u8 RFID2_Init(void);//初始化读卡器，使能天线
u8 RFID2_Disableantenna(void);//关闭天线，减少发热
u8 GET_UID2(u8 *uid);//获取UID
		 				    
#endif

