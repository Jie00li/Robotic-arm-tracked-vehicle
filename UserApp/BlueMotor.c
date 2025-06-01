/*
* File: BlueMotor.c
* Author: create by lijie
* Date: 2024-03-25
* Description: This file contains an BlueMotor funtion of C code.
* Version: 1.0
*/

#include "BlueMotor.h"

/**************Globel**********************/
uint8_t Fore,Back,Left,Right;           //方向标志位
uint8_t BT_Flag=0;                      //蓝牙标志位
/******************************************/

void Blue_Tooth_Cmd(uint8_t Usart_Data)
{
	switch(Usart_Data)
	{
		case 'Z'://停止 Z
			Fore=0,Back=0,Left=0,Right=0;
			break;
		case 'A'://前进 
			Fore=1,Back=0,Left=0,Right=0;
			break;
		case 'H'://左前 H
			Fore=1,Back=0,Left=1,Right=0;
			break;
		case 'B'://右前 B
			Fore=1,Back=0,Left=0,Right=1;
			break;
		case 'G'://左转 G
			Fore=0,Back=0,Left=1,Right=0;
			break;
		case 'C'://右转 C
			Fore=0,Back=0,Left=0,Right=1;
			break;
		case 'E'://后退 E
			Fore=0,Back=1,Left=0,Right=0;
			break;
		case 'F'://左后 F
			Fore=0,Back=1,Left=0,Right=1;
			break;
		case 'D'://右后 D
			Fore=0,Back=1,Left=1,Right=0;
			break;
	}
}

void BT_Control(void)//蓝牙控制
{

		if((Fore==0)&&(Back==0)&&(Left==0)&&(Right==0))//停止
		{
				Motor_LEFT_Speed(0);
			  Motor_RIGHT_Speed(0);
		}
		if((Fore==1)&&(Back==0)&&(Left==0)&&(Right==0))//前进
		{
				Motor_LEFT_Speed(-2000);
			  Motor_RIGHT_Speed(-2000);
		}
		if((Fore==0)&&(Back==1)&&(Left==0)&&(Right==0))//后退
		{
				Motor_LEFT_Speed(2000);
			  Motor_RIGHT_Speed(2000);
		}
		if((Fore==0)&&(Back==0)&&(Left==1)&&(Right==0))//左旋
		{
				Motor_LEFT_Speed(-2000);
			  Motor_RIGHT_Speed(2000);
		}
		if((Fore==0)&&(Back==0)&&(Left==0)&&(Right==1))//右旋
		{
				Motor_LEFT_Speed(2000);
			  Motor_RIGHT_Speed(-2000);
		}
		if((Fore==1)&&(Back==0)&&(Left==1)&&(Right==0))//左前
		{	
				Motor_LEFT_Speed(-600);
			  Motor_RIGHT_Speed(-2000);
		}
		if((Fore==1)&&(Back==0)&&(Left==0)&&(Right==1))//右前
		{
				Motor_LEFT_Speed(-2000);
			  Motor_RIGHT_Speed(-600);
		}
		if((Fore==0)&&(Back==1)&&(Left==1)&&(Right==0))//左后
		{
				Motor_LEFT_Speed(600);
			  Motor_RIGHT_Speed(2000);
		}
		if((Fore==0)&&(Back==1)&&(Left==0)&&(Right==1))//右后
		{
				Motor_LEFT_Speed(2000);
			  Motor_RIGHT_Speed(600);
		}
}
