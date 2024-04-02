/*
* File: BlueMotor.c
* Author: create by lijie
* Date: 2024-03-25
* Description: This file contains an BlueMotor funtion of C code.
* Version: 1.0
*/

#include "BlueMotor.h"

/**************Globel**********************/
uint8_t Fore,Back,Left,Right;           //�����־λ
uint8_t BT_Flag=0;                      //������־λ
/******************************************/

void Blue_Tooth_Cmd(uint8_t Usart_Data)
{
	switch(Usart_Data)
	{
		case 'Z'://ֹͣ Z
			Fore=0,Back=0,Left=0,Right=0;
			break;
		case 'A'://ǰ�� 
			Fore=1,Back=0,Left=0,Right=0;
			break;
		case 'H'://��ǰ H
			Fore=1,Back=0,Left=1,Right=0;
			break;
		case 'B'://��ǰ B
			Fore=1,Back=0,Left=0,Right=1;
			break;
		case 'G'://��ת G
			Fore=0,Back=0,Left=1,Right=0;
			break;
		case 'C'://��ת C
			Fore=0,Back=0,Left=0,Right=1;
			break;
		case 'E'://���� E
			Fore=0,Back=1,Left=0,Right=0;
			break;
		case 'F'://��� F
			Fore=0,Back=1,Left=0,Right=1;
			break;
		case 'D'://�Һ� D
			Fore=0,Back=1,Left=1,Right=0;
			break;
	}
}

void BT_Control(void)//��������
{

		if((Fore==0)&&(Back==0)&&(Left==0)&&(Right==0))//ֹͣ
		{
				Motor_LEFT_Speed(0);
			  Motor_RIGHT_Speed(0);
		}
		if((Fore==1)&&(Back==0)&&(Left==0)&&(Right==0))//ǰ��
		{
				Motor_LEFT_Speed(-2000);
			  Motor_RIGHT_Speed(-2000);
		}
		if((Fore==0)&&(Back==1)&&(Left==0)&&(Right==0))//����
		{
				Motor_LEFT_Speed(2000);
			  Motor_RIGHT_Speed(2000);
		}
		if((Fore==0)&&(Back==0)&&(Left==1)&&(Right==0))//����
		{
				Motor_LEFT_Speed(-2000);
			  Motor_RIGHT_Speed(2000);
		}
		if((Fore==0)&&(Back==0)&&(Left==0)&&(Right==1))//����
		{
				Motor_LEFT_Speed(2000);
			  Motor_RIGHT_Speed(-2000);
		}
		if((Fore==1)&&(Back==0)&&(Left==1)&&(Right==0))//��ǰ
		{	
				Motor_LEFT_Speed(-600);
			  Motor_RIGHT_Speed(-2000);
		}
		if((Fore==1)&&(Back==0)&&(Left==0)&&(Right==1))//��ǰ
		{
				Motor_LEFT_Speed(-2000);
			  Motor_RIGHT_Speed(-600);
		}
		if((Fore==0)&&(Back==1)&&(Left==1)&&(Right==0))//���
		{
				Motor_LEFT_Speed(600);
			  Motor_RIGHT_Speed(2000);
		}
		if((Fore==0)&&(Back==1)&&(Left==0)&&(Right==1))//�Һ�
		{
				Motor_LEFT_Speed(2000);
			  Motor_RIGHT_Speed(600);
		}
}
