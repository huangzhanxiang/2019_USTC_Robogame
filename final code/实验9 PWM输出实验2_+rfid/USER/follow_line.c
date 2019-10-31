#include "follow_line.h"
#include "pid_ctrl.h"
#include "infrare.h"
#include "steer.h"
#include "motor.h"
#include "delay.h"
#include "rfid.h"
#include "led.h"
#include "catch.h"
#include "driver.h"
int j;
void slow_down(int speed)
{
	int  i;
	for(i=1;i<800;i++)
	{
		speed++;
		delay_ms(1);
	}
	
}
u8 follow_dir = go_str;
int follow_speed = 100;
int speed2_nor=3200;
int speed2_nor2=2000;
int speed1_2=4200;
int speed2_2=5000;
//int speed3_2=5500;

int speed_nor=1500;
int speed_nor2=2200;
int speed1=3800;
int speed2=5000;
int speed3=6000;


int speed3_nor=500;
int speed_nor3_2=2200;
int speed3_1=4600;
int speed3_2=5000;
int speed3_3=6000;

int speed4_nor=2400;
int speed4_nor2=3000;
int speed4_1=4600;
int speed4_2=5000;
int speed4_3=6000;

int speed5_nor=500;
int speed5_1=3000;
int speed5_2=3700;
int speed5_3=3900;
//last
//int speed5_nor=500;
//int speed5_1=2500;
//int speed5_2=3000;
//int speed5_3=3800;
//int speed5_nor=3000;
//int speed5_1=4500;
//int speed5_2=5500;
//int speed5_3=6000;
//int speed_nor=2200;
//int speed_nor2=2500;
//int speed1=3000;
//int speed2=3500;
//int speed3=4200;

//int down_nor=2000;
//int down_speed1=1500;
//int down_speed2=1000;
//int down_speed3=500;
int down_nor=1000;
int down_speed1=4500;
int down_speed2=5000;
int down_speed3=6660;


int down4_nor=1000;


int down2_nor=100;
int down2_speed1=2500;
int down2_speed2=3500;
int down2_speed3=5200;

int down3_nor=1800;
int down3_speed1=3500;
int down3_speed2=4000;
int down3_speed3=6660;


int flag1=0;
int flag2=0;
u8 proc_status;
u8 go_without_line=1;
	int speed_temp[4] = { 100,100,100,100 };
void follow_line()
{
		switch(follow_dir)
		{
			case stay_here:
			//	setdir(5);
			 cycle_moto1=0;
			 cycle_moto2=0;
			 cycle_moto3=0;
			 cycle_moto4=0;
		//	delay_ms(5000);
				break;
			

			case stay_up:

			break;
			case go_rotate_r :
				setdir(6);//顺转
			cycle_moto1=3000;
		  cycle_moto2=3000;
			cycle_moto3=3000;
			cycle_moto4=3000;
			break;
			
			case go_rotate_l :
				setdir(4);
						cycle_moto1=3000;
		  cycle_moto2=3000;
			cycle_moto3=3000;
			cycle_moto4=3000;
			break;
			case go_str:
				setdir(1);
			if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==0) cycle_moto2=speed_nor;
			else if(status[0]==0 && status[1]==0 && status[2] ==1 && status[3]==0) {cycle_moto2=speed1;}
			else if(status[0]==0 && status[1]==0 && status[2] ==1 && status[3]==1) cycle_moto2=speed2;
			else if(status[0]==0 && status[1]==0 && status[2] ==0 && status[3]==1) cycle_moto2=speed3;
			else cycle_moto2=speed_nor;
			
			if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==0) cycle_moto1=speed_nor;
			else if(status[0]==0 && status[1]==1 && status[2] ==0 && status[3]==0) cycle_moto1=speed1;
			else if(status[0]==1 && status[1]==1 && status[2] ==0 && status[3]==0 ) cycle_moto1=speed2;
			else if(status[0]==1 && status[1]==0 && status[2] ==0 && status[3]==0) cycle_moto1=speed3;
			else cycle_moto1=speed_nor;
			
//			cycle_moto4=speed_nor;
//			cycle_moto3=speed_nor;
			if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==0) cycle_moto4=speed_nor;
			else if(status[4]==0 && status[5]==0 && status[6] ==1 && status[7]==0) {cycle_moto4=speed1; }
			else if(status[4]==0 && status[5]==0 && status[6] ==1 && status[7]==1 )  cycle_moto4=speed2;
			else if(status[4]==0 && status[5]==0 && status[6] ==0 && status[7]==1) cycle_moto4=speed3;
			else cycle_moto4=speed_nor;
			
			if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==0) cycle_moto3=speed_nor;
			else if(status[4]==0 && status[5]==1 && status[6] ==0 && status[7]==0) {cycle_moto3=speed1;}
			else if(status[4]==1 && status[5]==1 && status[6] ==0 && status[7]==0) cycle_moto3=speed2;
			else if(status[4]==1 && status[5]==0 && status[6] ==0 && status[7]==0) cycle_moto3=speed3;
			else cycle_moto3=speed_nor;			
			break;
			
						case go_str5:
				setdir(1);
			if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==0) cycle_moto2=speed5_nor;
			else if(status[0]==0 && status[1]==0 && status[2] ==1 && status[3]==0) {cycle_moto2=speed5_1;}
			else if(status[0]==0 && status[1]==0 && status[2] ==1 && status[3]==1) cycle_moto2=speed5_2;
			else if(status[0]==0 && status[1]==0 && status[2] ==0 && status[3]==1) cycle_moto2=speed5_3;
			else cycle_moto2=speed5_nor;
			
			if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==0) cycle_moto1=speed5_nor;
			else if(status[0]==0 && status[1]==1 && status[2] ==0 && status[3]==0) cycle_moto1=speed5_1;
			else if(status[0]==1 && status[1]==1 && status[2] ==0 && status[3]==0 ) cycle_moto1=speed5_2;
			else if(status[0]==1 && status[1]==0 && status[2] ==0 && status[3]==0) cycle_moto1=speed5_3;
			else cycle_moto1=speed5_nor;
			
//			cycle_moto4=speed_nor;
//			cycle_moto3=speed_nor;
			if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==0) cycle_moto4=speed5_nor;
			else if(status[4]==0 && status[5]==0 && status[6] ==1 && status[7]==0) {cycle_moto4=speed5_1; }
			else if(status[4]==0 && status[5]==0 && status[6] ==1 && status[7]==1 )  cycle_moto4=speed5_2;
			else if(status[4]==0 && status[5]==0 && status[6] ==0 && status[7]==1) cycle_moto4=speed5_3;
			else cycle_moto4=speed5_nor;
			
			if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==0) cycle_moto3=speed5_nor;
			else if(status[4]==0 && status[5]==1 && status[6] ==0 && status[7]==0) {cycle_moto3=speed5_1;}
			else if(status[4]==1 && status[5]==1 && status[6] ==0 && status[7]==0) cycle_moto3=speed5_2;
			else if(status[4]==1 && status[5]==0 && status[6] ==0 && status[7]==0) cycle_moto3=speed5_3;
			else cycle_moto3=speed5_nor;			
			break;
			
			
						case go_str3:
				setdir(1);
			if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==0) cycle_moto2=speed3_nor;
			else if(status[0]==0 && status[1]==0 && status[2] ==1 && status[3]==0) {cycle_moto2=speed3_1;}
			else if(status[0]==0 && status[1]==0 && status[2] ==1 && status[3]==1) cycle_moto2=speed3_2;
			else if(status[0]==0 && status[1]==0 && status[2] ==0 && status[3]==1) cycle_moto2=speed3_3;
			else cycle_moto2=speed_nor;
			
			if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==0) cycle_moto1=speed3_nor;
			else if(status[0]==0 && status[1]==1 && status[2] ==0 && status[3]==0) cycle_moto1=speed3_1;
			else if(status[0]==1 && status[1]==1 && status[2] ==0 && status[3]==0 ) cycle_moto1=speed3_2;
			else if(status[0]==1 && status[1]==0 && status[2] ==0 && status[3]==0) cycle_moto1=speed3_3;
			else cycle_moto1=speed3_nor;
			
			cycle_moto4=speed_nor;
			cycle_moto3=speed_nor;
			break;
			
									case go_str4:
				setdir(1);
			if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==0) cycle_moto2=speed4_nor;
			else if(status[0]==0 && status[1]==0 && status[2] ==1 && status[3]==0) {cycle_moto2=speed4_1;}
			else if(status[0]==0 && status[1]==0 && status[2] ==1 && status[3]==1) cycle_moto2=speed4_2;
			else if(status[0]==0 && status[1]==0 && status[2] ==0 && status[3]==1) cycle_moto2=speed4_3;
			else cycle_moto2=speed4_nor;
			
			if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==0) cycle_moto1=speed4_nor;
			else if(status[0]==0 && status[1]==1 && status[2] ==0 && status[3]==0) cycle_moto1=speed4_1;
			else if(status[0]==1 && status[1]==1 && status[2] ==0 && status[3]==0 ) cycle_moto1=speed4_2;
			else if(status[0]==1 && status[1]==0 && status[2] ==0 && status[3]==0) cycle_moto1=speed4_3;
			else cycle_moto1=speed4_nor;
						if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==0) cycle_moto4=speed4_nor;
			else if(status[4]==0 && status[5]==0 && status[6] ==1 && status[7]==0) {cycle_moto4=speed4_1; }
			else if(status[4]==0 && status[5]==0 && status[6] ==1 && status[7]==1 )  cycle_moto4=speed4_2;
			else if(status[4]==0 && status[5]==0 && status[6] ==0 && status[7]==1) cycle_moto4=speed4_3;
			else cycle_moto4=speed4_nor;
			
			if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==0) cycle_moto3=speed4_nor;
			else if(status[4]==0 && status[5]==1 && status[6] ==0 && status[7]==0) {cycle_moto3=speed4_1;}
			else if(status[4]==1 && status[5]==1 && status[6] ==0 && status[7]==0) cycle_moto3=speed4_2;
			else if(status[4]==1 && status[5]==0 && status[6] ==0 && status[7]==0) cycle_moto3=speed4_3;
			else cycle_moto3=speed4_nor;			
			break;
//			if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==0) cycle_moto4=speed3_nor;
//			else if(status[4]==0 && status[5]==0 && status[6] ==1 && status[7]==0) {cycle_moto4=speed3_1; }
//			else if(status[4]==0 && status[5]==0 && status[6] ==1 && status[7]==1 )  cycle_moto4=speed3_2;
//			else if(status[4]==0 && status[5]==0 && status[6] ==0 && status[7]==1) cycle_moto4=speed3_3;
//			else cycle_moto4=speed3_nor;
//			
//			if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==0) cycle_moto3=speed3_nor;
//			else if(status[4]==0 && status[5]==1 && status[6] ==0 && status[7]==0) {cycle_moto3=speed3_1;}
//			else if(status[4]==1 && status[5]==1 && status[6] ==0 && status[7]==0) cycle_moto3=speed3_2;
//			else if(status[4]==1 && status[5]==0 && status[6] ==0 && status[7]==0) cycle_moto3=speed3_3;
//			else cycle_moto3=speed3_nor;			
//			break;
			
						case go_str2:
				setdir(1);
			if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==0) cycle_moto2=speed2_nor;
			else if(status[0]==0 && status[1]==0 && status[2] ==1 && status[3]==0) {cycle_moto2=speed1_2;}
			else if(status[0]==0 && status[1]==0 && status[2] ==1 && status[3]==1) cycle_moto2=speed3_2;
			else if(status[0]==0 && status[1]==0 && status[2] ==0 && status[3]==1) cycle_moto2=speed3_2;
			else cycle_moto2=speed2_nor;
			
			if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==0) cycle_moto1=speed2_nor;
			else if(status[0]==0 && status[1]==1 && status[2] ==0 && status[3]==0) cycle_moto1=speed1_2;
			else if(status[0]==1 && status[1]==1 && status[2] ==0 && status[3]==0 ) cycle_moto1=speed2_2;
			else if(status[0]==1 && status[1]==0 && status[2] ==0 && status[3]==0) cycle_moto1=speed3_2;
			else cycle_moto1=speed2_nor;
			
//			cycle_moto4=speed_nor;
//			cycle_moto3=speed_nor;
			if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==0) cycle_moto4=speed2_nor;
			else if(status[4]==0 && status[5]==0 && status[6] ==1 && status[7]==0) {cycle_moto4=speed1_2; }
			else if(status[4]==0 && status[5]==0 && status[6] ==1 && status[7]==1 )  cycle_moto4=speed2_2;
			else if(status[4]==0 && status[5]==0 && status[6] ==0 && status[7]==1) cycle_moto4=speed3_2;
			else cycle_moto4=speed2_nor;
			
			if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==0) cycle_moto3=speed2_nor;
			else if(status[4]==0 && status[5]==1 && status[6] ==0 && status[7]==0) {cycle_moto3=speed1_2;}
			else if(status[4]==1 && status[5]==1 && status[6] ==0 && status[7]==0) cycle_moto3=speed2_2;
			else if(status[4]==1 && status[5]==0 && status[6] ==0 && status[7]==0) cycle_moto3=speed3_2;
			else cycle_moto3=speed_nor;			
			break;
			
			case r_go_str:
			setdir(7);
			if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==0) cycle_moto2=speed_nor;
			else if(status[0]==0 && status[1]==0 && status[2] ==1 && status[3]==0) {cycle_moto2=speed1;}
			else if(status[0]==0 && status[1]==0 && status[2] ==1 && status[3]==1) cycle_moto2=speed3;
			else if(status[0]==0 && status[1]==0 && status[2] ==0 && status[3]==1) cycle_moto2=speed3;
			else cycle_moto2=speed_nor;
			
			if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==0) cycle_moto1=speed_nor;
			else if(status[0]==0 && status[1]==1 && status[2] ==0 && status[3]==0) cycle_moto1=speed1;
			else if(status[0]==1 && status[1]==1 && status[2] ==0 && status[3]==0 ) cycle_moto1=speed2;
			else if(status[0]==1 && status[1]==0 && status[2] ==0 && status[3]==0) cycle_moto1=speed3;
			else cycle_moto1=speed_nor;
			
//			cycle_moto4=speed_nor;
//			cycle_moto3=speed_nor;
			if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==0) cycle_moto4=speed_nor;
			else if(status[4]==0 && status[5]==0 && status[6] ==1 && status[7]==0) {cycle_moto4=speed1; }
			else if(status[4]==0 && status[5]==0 && status[6] ==1 && status[7]==1 )  cycle_moto4=speed2;
			else if(status[4]==0 && status[5]==0 && status[6] ==0 && status[7]==1) cycle_moto4=speed3;
			else cycle_moto4=speed_nor;
			
			if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==0) cycle_moto3=speed_nor;
			else if(status[4]==0 && status[5]==1 && status[6] ==0 && status[7]==0) {cycle_moto3=speed1;}
			else if(status[4]==1 && status[5]==1 && status[6] ==0 && status[7]==0) cycle_moto3=speed2;
			else if(status[4]==1 && status[5]==0 && status[6] ==0 && status[7]==0) cycle_moto3=speed3;
			else cycle_moto3=speed_nor;			
			break;
			
			case go_right:
				setdir(4);
				cycle_moto1=3400;
	cycle_moto2=3400;
	cycle_moto4=3400;
	cycle_moto3=3400;
			break;
			
			case go_up :
				setdir(1);
							if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==0) cycle_moto2=speed_nor;
			else if(status[0]==0 && status[1]==0 && status[2] ==1 && status[3]==0) {cycle_moto2=speed1;flag1=0;}
			else if(status[0]==0 && status[1]==0 && status[2] ==0 && status[3]==0 && flag1==0) cycle_moto2=speed2;
			else if(status[0]==0 && status[1]==0 && status[2] ==0 && status[3]==1) cycle_moto2=speed3;
			else if(status[0]==1 && status[1]==1 && status[2] ==1 && status[3]==1) cycle_moto2=speed_nor;
			else if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==1) cycle_moto2=speed_nor;
		//	else if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==1) cycle_moto2=speed_nor;
			else cycle_moto2=speed_nor;
			
			if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==0) cycle_moto1=speed_nor;
			else if(status[0]==0 && status[1]==1 && status[2] ==0 && status[3]==0) {cycle_moto1=speed1;flag1=1;}
			else if(status[0]==0 && status[1]==0 && status[2] ==0 && status[3]==0 && flag1==1) cycle_moto1=speed2;
			else if(status[0]==1 && status[1]==0 && status[2] ==0 && status[3]==0) cycle_moto1=speed3;
						else if(status[0]==1 && status[1]==1 && status[2] ==1 && status[3]==1) cycle_moto1=speed_nor;
						else if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==1) cycle_moto1=speed_nor;
			else cycle_moto2=speed_nor;
			
			if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==0) cycle_moto4=speed_nor2;
			else if(status[4]==0 && status[5]==0 && status[6] ==1 && status[7]==0) {cycle_moto4=speed1; flag2=0;}
			else if(status[4]==0 && status[5]==0 && status[6] ==0 && status[7]==0 && flag2==0)  cycle_moto4=speed2;
			else if(status[4]==0 && status[5]==0 && status[6] ==0 && status[7]==1) cycle_moto4=speed3;
			else if(status[4]==1 && status[5]==1 && status[6] ==1 && status[7]==1) cycle_moto4=speed_nor2;
			else if(status[4]==1 && status[5]==1 && status[6] ==1 && status[7]==1) cycle_moto4=speed_nor2;
			else if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==1) cycle_moto4=speed_nor2;
			else cycle_moto2=speed_nor;
			
			if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==0) cycle_moto3=speed_nor2;
			else if(status[4]==0 && status[5]==1 && status[6] ==0 && status[7]==0) {cycle_moto3=speed1;flag2=1;}
			else if(status[4]==0 && status[5]==0 && status[6] ==0 && status[7]==0) cycle_moto3=speed2;
			else if(status[4]==1 && status[5]==0 && status[6] ==0 && status[7]==0) cycle_moto3=speed3;
						else if(status[4]==1 && status[5]==1 && status[6] ==1 && status[7]==1) cycle_moto3=speed_nor2;
			else if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==1) cycle_moto4=speed_nor2;
			else cycle_moto2=speed_nor;
			break;
			
			case go_down :
			setdir(1);
			if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==0) cycle_moto2=down_nor;
			else if(status[0]==0 && status[1]==0 && status[2] ==1 && status[3]==0) {cycle_moto2=down_speed1;}
			else if(status[0]==0 && status[1]==0 && status[2] ==1 && status[3]==1) cycle_moto2=down_speed2;
			else if(status[0]==0 && status[1]==0 && status[2] ==0 && status[3]==1) cycle_moto2= down_speed3;
			else cycle_moto2=down_nor;
			
			if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==0) cycle_moto1=down_nor;
			else if(status[0]==0 && status[1]==1 && status[2] ==0 && status[3]==0) cycle_moto1=down_speed1;
			else if(status[0]==1 && status[1]==1 && status[2] ==0 && status[3]==0 ) cycle_moto1=down_speed2;
			else if(status[0]==1 && status[1]==0 && status[2] ==0 && status[3]==0) cycle_moto1=down_speed3;
			else cycle_moto1=down_nor;

			if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==0) cycle_moto4=down_nor;
			else if(status[4]==0 && status[5]==0 && status[6] ==1 && status[7]==0) {cycle_moto4=down_speed1; }
			else if(status[4]==0 && status[5]==0 && status[6] ==1 && status[7]==1 )  cycle_moto4=down_speed2;
			else if(status[4]==0 && status[5]==0 && status[6] ==0 && status[7]==1) cycle_moto4=down_speed3;
			else cycle_moto4=down_nor;
			
			if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==0) cycle_moto3=down_nor;
			else if(status[4]==0 && status[5]==1 && status[6] ==0 && status[7]==0) {cycle_moto3=down_speed1;}
			else if(status[4]==1 && status[5]==1 && status[6] ==0 && status[7]==0) cycle_moto3=down_speed2;
			else if(status[4]==1 && status[5]==0 && status[6] ==0 && status[7]==0) cycle_moto3=down_speed3;
			else cycle_moto3=down_nor;			
			break;

//			case go_down :
//			setdir(1);
//			if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==0) cycle_moto1=down_nor;//1加2减
//			else if(status[0]==0 && status[1]==0 && status[2] ==1 && status[3]==0) cycle_moto1=down_speed1;
//			else if(status[0]==0 && status[1]==0 && status[2] ==1 && status[3]==1) cycle_moto1=down_speed2;
//			else if(status[0]==0 && status[1]==0 && status[2] ==0 && status[3]==1) cycle_moto1= down_speed3;
//			else cycle_moto1=down_nor;
//			
//			if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==0) cycle_moto2=down_nor;
//			else if(status[0]==0 && status[1]==1 && status[2] ==0 && status[3]==0) cycle_moto2=down_speed1;
//			else if(status[0]==1 && status[1]==1 && status[2] ==0 && status[3]==0 ) cycle_moto2=down_speed2;
//			else if(status[0]==1 && status[1]==0 && status[2] ==0 && status[3]==0) cycle_moto2=down_speed3;
//			else cycle_moto2=down_nor;
//			
//			cycle_moto3=down3_nor;
//			cycle_moto4=down4_nor;
//			break;
//			if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==0) cycle_moto3=down_nor;
//			else if(status[4]==0 && status[5]==0 && status[6] ==1 && status[7]==0) {cycle_moto3=down_speed1; }
//			else if(status[4]==0 && status[5]==0 && status[6] ==1 && status[7]==1 )  cycle_moto3=down_speed2;
//			else if(status[4]==0 && status[5]==0 && status[6] ==0 && status[7]==1) cycle_moto3=down_speed3;
//			else cycle_moto3=down_nor;
//			
//			if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==0) cycle_moto4=down_nor;
//			else if(status[4]==0 && status[5]==1 && status[6] ==0 && status[7]==0) {cycle_moto4=down_speed1;}
//			else if(status[4]==1 && status[5]==1 && status[6] ==0 && status[7]==0) cycle_moto4=down_speed2;
//			else if(status[4]==1 && status[5]==0 && status[6] ==0 && status[7]==0) cycle_moto4=down_speed3;
//			else cycle_moto4=down_nor;			
			
			
			case go_down2 :
			setdir(1);
			if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==0) cycle_moto2=down2_nor;
			else if(status[0]==0 && status[1]==0 && status[2] ==1 && status[3]==0) {cycle_moto2=down2_speed1;}
			else if(status[0]==0 && status[1]==0 && status[2] ==1 && status[3]==1) cycle_moto2=down2_speed2;
			else if(status[0]==0 && status[1]==0 && status[2] ==0 && status[3]==1) cycle_moto2= down2_speed3;
			else cycle_moto2=down2_nor;
			
			if(status[0]==0 && status[1]==1 && status[2] ==1 && status[3]==0) cycle_moto1=down3_nor;
			else if(status[0]==0 && status[1]==1 && status[2] ==0 && status[3]==0) cycle_moto1=down3_speed1;
			else if(status[0]==1 && status[1]==1 && status[2] ==0 && status[3]==0 ) cycle_moto1=down3_speed2;
			else if(status[0]==1 && status[1]==0 && status[2] ==0 && status[3]==0) cycle_moto1=down3_speed3;
			else cycle_moto1=down3_nor;
			
//			cycle_moto4=speed_nor;
//			cycle_moto3=speed_nor;
			if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==0) cycle_moto4=down3_nor;
			else if(status[4]==0 && status[5]==0 && status[6] ==1 && status[7]==0) {cycle_moto4=down3_speed1; }
			else if(status[4]==0 && status[5]==0 && status[6] ==1 && status[7]==1 )  cycle_moto4=down3_speed2;
			else if(status[4]==0 && status[5]==0 && status[6] ==0 && status[7]==1) cycle_moto4=down3_speed3;
			else cycle_moto4=down3_nor;
			
			if(status[4]==0 && status[5]==1 && status[6] ==1 && status[7]==0) cycle_moto3=down2_nor;
			else if(status[4]==0 && status[5]==1 && status[6] ==0 && status[7]==0) {cycle_moto3=down2_speed1;}
			else if(status[4]==1 && status[5]==1 && status[6] ==0 && status[7]==0) cycle_moto3=down2_speed2;
			else if(status[4]==1 && status[5]==0 && status[6] ==0 && status[7]==0) cycle_moto3=down2_speed3;
			else cycle_moto3=down2_nor;			
			break;
			
			
			case go_y_r:
				setdir(2);
			  			cycle_moto1=3000;
		  cycle_moto2=3000;
			cycle_moto3=3000;
			cycle_moto4=3000;
				break;
			default :
			setdir(1);
			setspeed(5000,5000,5000,5000);
		}
	}
		
//	setdir(1);
////	setspeed(5700,5700,5700,5700);
//	setspeed(5000,5000,5000,5000);

		
void follow_line_left(void)
{
	int i;
//	proc_status=3;
		switch (proc_status) 
	{

		case START:	
			//直行
			follow_dir = go_str5;
			follow_speed =5000;
		  go_without_line=0;
		  if(status[8]==1 && status[9]==1 ) proc_status=1;
			break;
		case 1:
			follow_dir = go_str5;
			follow_speed =5000;
		  go_without_line=0;
		  if(status[8]==0 && status[9]==1 ) proc_status=2;
			break;
		
		case 2:
			follow_dir = go_str5;
			follow_speed =5000;
		  go_without_line=0;
		  if(status[8]==0 && status[9]==0 ) proc_status=49;
			break;
		case 49:
			follow_dir = go_str5;
			follow_speed =5000;
		  go_without_line=0;
		  if(status[8]==0 && status[9]==1 ) proc_status=56;
			break;
		case 56:
			follow_dir = go_str5;
			follow_speed =5000;
		  go_without_line=0;
		  if(status[8]==0 && status[9]==0 ) proc_status=50;
			break;
		case 50:
			follow_dir = go_str;
			follow_speed =5000;
		  go_without_line=0;
		  if(status[8]==0 && status[9]==1 ) proc_status=60;
			break;
			
		case 60:
			cycle_moto1=0;
			cycle_moto2=0;
			cycle_moto3=0;
			cycle_moto4=0;
		  go_without_line=1;
		  setdir(5);
		  delay_ms(1000);
		catch_init();
		proc_status=3;
		break;
		case 3:
			follow_dir = go_str;
			follow_speed =5000;
		  go_without_line=0;
		  if(status[8]==1 && status[9]==0 ) proc_status=4;
			break;
		
		case 4:
			//停止
		  //此状态需要舵机和步进电机协同工作完成，最好用一个函数完成
			follow_dir=catch1;
		  cycle_moto1=0;
			cycle_moto2=0;
			cycle_moto3=0;
			cycle_moto4=0;
		  go_without_line=1;
		  setdir(5);
		  delay_ms(1000);
		  catch_first();
		  proc_status=5;
			break;
		case 5://直行
			follow_dir = go_str4;
			follow_speed =5000;
		  go_without_line=0;
		  if(status[10]==1) proc_status=6;
      break;		
		case 6://原地右转
			follow_dir = go_rotate_r;
		  go_without_line=1;
		  if(status[2]==1 ) proc_status=7;
		break;
		case 7://直行上坡
			follow_dir = go_str;
		  go_without_line=0;
		 // if(status[8]==1 && status[9]==0 ) proc_status=51;
		if(status[11]==1 ) proc_status=8;
		break;
		
		case 51:
			follow_dir = go_str;
		  go_without_line=0;
		delay_ms(1);
		  if(status[11]==1 ) proc_status=8;
		break;
		
			case 52:
			follow_dir = go_str;
		  go_without_line=0;
		delay_ms(1);
		  if(status[11]==1 ) proc_status=8;
		break;
		
		case 8://停止
			//抓取
		  follow_dir = stay_up;
		  go_without_line=1;
		  setdir(1);
			cycle_moto1=6000;
			cycle_moto2=6000;
			cycle_moto3=6000;
			cycle_moto4=6000;
			catch_second();
		  delay_ms(1000);
		  proc_status=9;
			break;
		case 9://直行上坡
			follow_dir = go_str;
		  go_without_line=0;
		  if(status[8]==0 && status[9]==0 ) proc_status=10;
		break;
		case 10:
			follow_dir = go_str;
		  go_without_line=0;
		  if(status[8]==1 && status[9]==0 ) proc_status=11;
		break;			
		case 11://停止
			//抓取
			  follow_dir = stay_here;
		  go_without_line=1;
		  setdir(5);
		  delay_ms(1000);
			catch_third();
		  proc_status=40;
		break;
				
		case 40:
			follow_dir = go_y_r;
		  if(status[11]==1) proc_status=54;
		break;
		
		case 54:
			follow_dir = go_y_r;
		delay_ms(10);
		  if(status[11]==1) proc_status=42;
		break;
		
		case 42:
			follow_dir = go_rotate_r;
			if(status[1]==0 && status[2]==0) proc_status=43;
		break;
		case 43:
			follow_dir =go_rotate_r;
			if(status[2]==1 && status[1]==1) proc_status=12;
break;
		case 12://下坡
			follow_dir = go_down;
		  go_without_line=1;
		  if(status[8]==0 && status[9]==1 ) proc_status=45;//45
		break;
		
		case 15://下坡
			follow_dir = go_down;
		  go_without_line=1;
		  if(status [5]==1 && status[6]==1 ) proc_status=45;
		break;
		
		case 45:
			follow_dir = go_down2;
		//follow_dir = go_down;
		  go_without_line=1;
		  if(status [0]==1 && status[1]==1) proc_status=46;
		break;			
		
		case 46:
		follow_dir = go_down2;
		//follow_dir = go_down;
		  go_without_line=1;
		  //if(status [0]==0 && status[1]==0 && status[2]==0 && status[3]==0) proc_status=13;
		if(status [12]==1 ) proc_status=13;
		break;			
		case 53:
			follow_dir = go_down2;
		//follow_dir = go_down;
			delay_ms(1);
		  go_without_line=1;
		  if(status [0]==0 && status[1]==0 && status[2]==0 && status[3]==0) proc_status=13;
		break;			
//    case 13://顺转
//						follow_dir = go_rotate_r;
//		  go_without_line=1;
//		  if(status[3]==1 && status[2]==1) proc_status=14;
//		break;
//		
//		case 14://下坡
//			follow_dir = go_down;
//		  go_without_line=0;
//		if(status[8]==1 && status[9]==0) proc_status=15;
//		break;
		
		case 13://逆转90度
			
			follow_dir = go_rotate_l;
		  go_without_line=1;
		if(status[2]==0 && status[1]==0 ) proc_status=14;
		break;
		
		case 14://逆转90度
			follow_dir = go_rotate_l;
		  go_without_line=1;
		if( status[1]==1 && status[2]==1 ) proc_status=16;
		break;
				
		case 16://转完直行
			follow_dir = go_str3;
		  go_without_line=0;
		  if(status[12]==1) proc_status=61;
		break;
		
//		case 17:
//		follow_dir = go_rotate_l;
//		go_without_line=1;
//		if(status[1]==1 && status[9]==0) proc_status=18;
//		break;
//	
		case 61:
						follow_dir=catch1;
		  cycle_moto1=0;
			cycle_moto2=0;
			cycle_moto3=0;
			cycle_moto4=0;
		  go_without_line=1;
		  setdir(5);
		  delay_ms(1000);
		  catch_stop();
		  proc_status=62;
			break;
		case 62:
					follow_dir = go_str3;
		  go_without_line=0;
		  if(status[12]==1) proc_status=18;
		break;
		
		
	  case 18:
		follow_dir = go_rotate_l;
		go_without_line=1;
		if(status[1]==0 && status[2]==0) proc_status=19;
		break;
		
	  case 19:
		follow_dir = go_rotate_l;
		go_without_line=1;
		if(status[2]==1 && status[1]==1) proc_status=20;
		break;
		
		case 20:
		follow_dir = go_str;
		 go_without_line=0;
		if(status[8]==1 && status[9]==0) proc_status=21;
		break;
		
				case 21:
			//停止
		  follow_dir = stay_here;
		  go_without_line=1;
		  setdir(5);
		  delay_ms(5000);
		  proc_status=47;
			break;
				
		case 47:
		follow_dir = go_str;
		 go_without_line=0;
		if(status[8]==0&&status[9]==0 ) proc_status=22;
		break;
		
			case 22:
			follow_dir = go_str;
		  go_without_line=0;
		if(status[10]==1 ) proc_status=23;
		break;
			
			case 23://原地右转
			follow_dir = go_rotate_r;
		  go_without_line=1;
		  if(status[1]==0 && status[2]==0) proc_status=48;
		break;
			
			case 48:
			follow_dir = go_rotate_r;
		  go_without_line=1;
		  if(status[1]==1 && status[2]==1) proc_status=24;
		break;
			
			case 24:
		  follow_dir = go_str;
		  go_without_line=0;
		  if(status[8]==1 && status[9]==0) proc_status=25;
			break;
			
			case 25:
			follow_dir=catch1;
		  cycle_moto1=0;
			cycle_moto2=0;
			cycle_moto3=0;
			cycle_moto4=0;
		  go_without_line=1;
		  setdir(5);
		  delay_ms(1000);
		  release_first();
		  proc_status=70;
			break;
			
			case 70://过第一个黑条
		follow_dir = go_str;
		 go_without_line=0;
		if(status[8]==0 && status[9]==0) proc_status=63;
			break;
			
		case 63:
		 follow_dir = go_str;
		 go_without_line=0;
		if(status[8]==1 && status[9]==0) proc_status=64;
			break;
			
			case 64:
			follow_dir=catch1;
		  cycle_moto1=0;
			cycle_moto2=0;
			cycle_moto3=0;
			cycle_moto4=0;
		  go_without_line=1;
		  setdir(5);
		  delay_ms(1000);
		  release_second();
		  proc_status=71;
			break;
		
			case 71://过第二个黑条
			follow_dir = go_str;
		 go_without_line=0;
		if(status[8]==0 && status[9]==0) proc_status=65;
			
			case 65:
			follow_dir = go_str;
		 go_without_line=0;
		if(status[8]==1 && status[9]==0) proc_status=66;
			break;
			
			case 66:
			follow_dir=catch1;
		  cycle_moto1=0;
			cycle_moto2=0;
			cycle_moto3=0;
			cycle_moto4=0;
		  go_without_line=1;
		  setdir(5);
		  delay_ms(1000);
		  release_third();
		  proc_status=72;
				break;
			
			case 72://第三个
							follow_dir = go_str;
		 go_without_line=0;
		if(status[8]==0 && status[9]==0) proc_status=67;
				break;
			
			case 67://第四个
			follow_dir = go_str;
		 go_without_line=0;
		if(status[8]==1 && status[9]==0) proc_status=73;
			break;
		  
		case 73:
		follow_dir = go_str;
		 go_without_line=0;
		if(status[8]==0 && status[9]==0) proc_status=75;
		break;
		
		case 75://6
		follow_dir = go_str;
		 go_without_line=0;
		if(status[8]==1 && status[9]==0) proc_status=76;
		break;			
		
		case 76:
		follow_dir = go_str;
		go_without_line=0;
		if(status[8]==0 && status[9]==0) proc_status=77;
		break;			
		
		case 77:
			follow_dir=catch1;
		  cycle_moto1=0;
			cycle_moto2=0;
			cycle_moto3=0;
			cycle_moto4=0;
		  go_without_line=1;
		  setdir(5);
		  delay_ms(1000);
		  release_forth();
		  proc_status=80;
				break;			
		
		case 80:
					follow_dir=catch1;
		  cycle_moto1=0;
			cycle_moto2=0;
			cycle_moto3=0;
			cycle_moto4=0;
		  go_without_line=1;
		  setdir(5);
		  delay_ms(1000);
		  proc_status=80;
		break;
		
		default : 
			follow_dir = go_str;
			follow_speed =900;
	
	}
}

//void follow_line_right()
//{
//	
//			switch (proc_status) 
//	{
//		case START:	
//			//直行
//			follow_dir = r_go_str;
//			follow_speed =5000;
//		  go_without_line=0;
//		  if(status[8]==1 && status[9]==1 ) proc_status=1;
//			break;
//		case 1:
//			follow_dir = r_go_str;
//			follow_speed =5000;
//		  go_without_line=0;
//		  if(status[8]==0 && status[9]==1 ) proc_status=2;
//			break;
//		
//		case 2:
//			follow_dir = r_go_str;
//			follow_speed =5000;
//		  go_without_line=0;
//		  if(status[8]==0 && status[9]==0 ) proc_status=3;
//			break;

//		case 3:
//			follow_dir = go_str;
//			follow_speed =5000;
//		  go_without_line=0;
//		  if(status[8]==1 && status[9]==0 ) proc_status=4;
//			break;
//		
//		case 4:
//			//停止
//		  //此状态需要舵机和步进电机协同工作完成，最好用一个函数完成
//		  follow_dir = stay_here;
//		  go_without_line=1;
//		  setdir(5);
//		  delay_ms(5000);
//		 // catch_first();
//		  proc_status=5;
//			break;
//		case 5://直行
//			follow_dir = go_str;
//			follow_speed =5000;
//		  go_without_line=0;
//		  if(status[0]==1 && status[1]==1 && status[2]==1) proc_status=6;
//      break;		
//		case 6://原地右转
//			follow_dir = go_rotate_r;
//		  go_without_line=1;
//		  if(status[5]==1 && status[6]==1 ) proc_status=7;
//		break;
//		case 7://直行上坡
//			follow_dir = go_str;
//		  go_without_line=0;
//		  if(status[8]==1 && status[9]==0 ) proc_status=8;
//		break;
//		case 8://停止
//			//抓取
//		  follow_dir = stay_up;
//		  go_without_line=1;
//		  setdir(1);
//			cycle_moto1=6200;
//			cycle_moto2=6200;
//			cycle_moto3=6200;
//			cycle_moto4=6200;
//		  delay_ms(5000);
//		  proc_status=9;
//			break;
//		case 9://直行上坡
//			follow_dir = go_str;
//		  go_without_line=0;
//		  if(status[8]==0 && status[9]==0 ) proc_status=10;
//		break;
//		case 10:
//			follow_dir = go_str;
//		  go_without_line=0;
//		  if(status[8]==1 && status[9]==0 ) proc_status=11;
//		break;			
//		case 11://停止
//			//抓取
//			  follow_dir = stay_here;
//		  go_without_line=1;
//		  setdir(5);
//		  delay_ms(5000);
//		  proc_status=12;
//		break;
//		case 12://下坡
//			follow_dir = go_rotate_r;
//		  go_without_line=1;
//		  if(status[1]==0 && status[2]==0) proc_status=13;
//		break;
//    case 13://顺转
//						follow_dir = go_rotate_r;
//		  go_without_line=1;
//		  if(status[3]==1 && status[2]==1) proc_status=14;
//		break;
//		
//		case 14://下坡
//			follow_dir = go_down;
//		  go_without_line=0;
//		if(status[8]==1 && status[9]==0) proc_status=15;
//		break;
//		
//		case 15://逆转90度
//			follow_dir = go_rotate_l;
//		  go_without_line=1;
//		if(status[2]==1 && status[1]==1 ) proc_status=16;
//		break;
//		
//		case 16://转完直行
//			follow_dir = go_str;
//		  go_without_line=0;
//		  if(status[8]==1 && status[9]==0 ) proc_status=18;
//		break;
//		
////		case 17:
////		follow_dir = go_rotate_l;
////		go_without_line=1;
////		if(status[1]==1 && status[9]==0) proc_status=18;
////		break;
////		
//	  case 18:
//		follow_dir = go_rotate_l;
//		go_without_line=1;
//		if(status[1]==0 && status[2]==0) proc_status=19;
//		break;
//		
//	  case 19:
//		follow_dir = go_rotate_l;
//		go_without_line=1;
//		if(status[2]==1 && status[1]==1) proc_status=20;
//		break;
//		
//		case 20:
//		follow_dir = go_str;
//		 go_without_line=0;
//		if(status[8]==1 && status[9]==0) proc_status=21;
//		break;
//		
//				case 21:
//			//停止
//		  follow_dir = stay_here;
//		  go_without_line=1;
//		  setdir(5);
//		  delay_ms(5000);
//		  proc_status=22;
//			break;
//				
//			case 22:
//			follow_dir = go_str;
//		  go_without_line=0;
//		if(status[8]==0 && status[9]==1) proc_status=23;
//		break;
//			
//			case 23://原地右转
//			follow_dir = go_rotate_r;
//		  go_without_line=1;
//		  if(status[1]==1 && status[2]==1) proc_status=24;
//		break;
//			
//			case 24:
//		  follow_dir = go_str;
//		  go_without_line=0;
//		  if(status[8]==1 && status[9]==0) proc_status=25;
//			break;
//			
//			case 25:
//						  follow_dir = stay_here;
//		  go_without_line=1;
//		  setdir(5);
//		  delay_ms(5000);
//		  proc_status=25;
//			break;
//		
//		  
//		default : 
//			follow_dir = go_str;
//			follow_speed =900;
//	}
//}
	

	
	
