#include "sys.h"
//follow_dir
#define go_str 0
#define go_up 1
#define go_right 2
#define stay_here 3
#define go_rotate_r 4
#define go_down 5
#define go_rotate_l 6
#define stay_up 7
#define go_down2 9
#define go_y_r 10
#define go_str2 11
#define r_go_str 8
#define go_str3 12
#define go_str4 13
#define go_str5 14
#define catch1 15
//proc_status
#define START 0

extern int  follow_speed ;
extern u8 proc_status;
extern u8 line_speed1;
extern u8 line_speed2;
extern u8 line_speed3;

void follow_line_left(void);
void follow_line_right(void);
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
