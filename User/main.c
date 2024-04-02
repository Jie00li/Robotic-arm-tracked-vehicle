/*
* File: main.c
* Author: create by lijie
* Date: 2024-03-20
* Description: This file contains an main Init of C code.
* Version: 1.0
*/

#include "head.h"

void Hardware_Init()
{
	delay_init();
	USART1_Init();   //��ʼ��Openmv����1
	OLED_Init();
	BT_USART3_Init(9600);  //��ʼ����������3
	Motor_GPIO_Init();
}

void Oled_flushed()
{
		OLED_ShowString(95,1,"NULL",4);
		delay_ms(5000);
		OLED_ShowString(95,1,"R   ",4);
		delay_ms(1000);
}

int main(void)
{
	Hardware_Init();
	OLED_Clear();
	OLED_ShowString(1,1,"TargerData:",11);
	while(1)
	{ 
		Oled_flushed();
		BT_Control();
	}
}
