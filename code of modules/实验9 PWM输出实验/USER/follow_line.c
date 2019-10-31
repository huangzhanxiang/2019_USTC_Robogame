#include "follow_line.h"
#include "pid_ctrl.h"
#include "infrare.h"
#include "steer.h"
#include "motor.h"
#include "delay.h"
#include "rfid.h"
#include "led.h"
void slow_down(int speed)
{
	int  i;
	for(i=1;i<800;i++)
	{
		speed++;
		delay_ms(1);
	}
	
}
u8 follow_dir = DIR3_1;
int follow_speed = 100;
u8 proc_status=0;
u8 go_without_line=1;
	int speed_temp[4] = { 100,100,100,100 };
void follow_line()
{
//	if((status[0]==0)&&(status[1]==0)&&(status[2]==0)&&(status[3]==0))
//	{
//		setdir(1);
//		setspeed(800,800,800,800);
//	}
	setdir(1);
//	if(status[0]==1) cycle_moto1+=500;
//	if(status[1]==1) cycle_moto2+=500;
//	if(status[2]==1) cycle_moto4+=500;
//	if(status[3]==1) cycle_moto3+=500;
//	if(status[0]==1) cycle_moto1=900;
//	if(status[1]==1) cycle_moto2=900;
//	if(status[2]==1) cycle_moto4=900;
//	if(status[3]==1) cycle_moto3=900;
	if(status[0]==0&&status[1]==0|status[2]==0|status[3]==0)
	{
		cycle_temp[0]=850;
		cycle_temp[1]=850;
		cycle_temp[2]=850;
		cycle_temp[3]=850;
	}
	else
	{
	if(status[0]==1) {cycle_temp[0]=900;cycle_temp[2]=800;}
	else if(status[1]==1) {cycle_temp[1]=900;cycle_temp[3]=800;}
	//else cycle_temp[1]=850;
	else if(status[2]==1) {cycle_temp[2]=900;cycle_temp[0]=800;}
	//else cycle_temp[2]=850;
	else if(status[3]==1) {cycle_temp[3]=900;cycle_temp[1]=800;}
	else  
	{
				cycle_temp[0]=850;
		cycle_temp[1]=850;
		cycle_temp[2]=850;
		cycle_temp[3]=850;
	}
}
//	else
//	{
//		setdir(1);
//		setspeed(100,100,100,100);
//	}
}
		
void follow_line_left(void)
{
		switch (proc_status) 
	{
		case START:	
			follow_dir = DIR3_1;
			follow_speed =100;
			break;
		default : 
						follow_dir = DIR3_1;
			follow_speed =900;
	}
	
}

void follow_line_right()
{}
	

	
	
