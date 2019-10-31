#include "sys.h"

#define DIR0_2 0
#define DIR2_0 1
#define DIR1_3 2
#define DIR3_1 3
#define Rote_CW 4
#define Rote_ACW 5
#define STAY 6
#define DIR1_2 7
#define DIR2_1 8
#define DIR_R 9
#define DIR_L 10
#define DIR0_1 11
#define DIR_R_C 12
#define DIR_L_C 13
#define DIR_R_Catch_Sec_Flag 14
#define DIR_L_Catch_Sec_Flag 15
#define NULL_DIR 99

#define node_left 0
#define node_right 1
#define LEFT 0
#define RIGHT 1

#define FIND 100
#define SPECIAL 101
#define START 0
#define BETTER_WITHOUT_LINE 103
#define BACKWARD 104
#define NULL_PROC 99
#define MAX_SPECIAL_NUM 3


#define climb_air_break_time 400

extern u8 special_tangle;
extern u8 LR;
extern u8 FS;
extern u8 start_rfid;
extern u8 rfid_last;
extern u16 node_inc_judge_time_ms;

extern u8 line_num;
extern u8 next_dir;
extern u8 dir1_3_history_enable;

extern int  follow_speed ;
extern u8 vd3_1_main_close;
extern u8 vd3_1_branch;
extern u8 vd3_1_slow ;
extern u8 vd3_1_close;
extern u8 vd3_1_special_slow;
extern u8 vd1_3_fast;
extern u8 vd1_3_slow;
extern u8 vd0_2_main_fast;
extern u8 vd0_2_main_slow;
extern u8 vd0_2_withoutline;
extern u8 vd0_2_special_tango_speed;
extern u8 vdcw_fast;
extern u8 vd1_2_slow ;
extern u8 vd1_2_fast ;
extern u8 vd0_1 ;
extern u16 delaytime_ms;
extern u8 line_speed1;
extern u8 line_speed2;
extern u8 line_speed3;

extern u8 side;
extern volatile u32 count_time;
extern u8 cur_nodenum;
extern u8 cur_dir;
extern u8 node_dir;
extern u8 set_dir;
extern u8 status_last[6];
extern u8 set_node[2];
extern u8 proc_status;
extern int follow_speed;
extern u8 follow_dir;
extern float  distance[2]; 
extern u8 distance_follow_flag;
extern u8 set_block[2];
extern u8 status_history[10][6];
extern u8 receive_data[5];
extern u8 save_block[4];
extern u8 save_node[4];

extern u8 rfid_data[8];     //由RFID巡线程序得出的block值
extern u8 useful_flag;   		//表示当前已经抓到几个有效的旗帜（左边为红专并进，右边为理实交融），识别完4个有效旗帜则不再继续识别
extern u8 useful_block[4];

void follow_line_left(void);
void setspeed_rfid(void);
void setspeed_high(void);
void setspeed_low(void);
void follow_line(void);
void stay(void);
void follow_line_handler_L_FAST(void);	//左侧场地流程，“红专并进”
void follow_line_handler_L_SLOW(void);	//慢速版
void follow_line_handler_R_FAST(void);	//右侧场地流程，“理实交融”
void follow_line_handler_R_SLOW(void);	//慢速版
void follow_line_handler_L_rfid(void) ;
void follow_line_handler_R_rfid(void) ;
void set_next_node(void);
void save_history(void);
