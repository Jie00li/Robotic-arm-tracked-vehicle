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
	USART1_Init();   //³õÊ¼»¯Openmv´®¿Ú1
	OLED_Init();
	BT_USART3_Init(9600);
	Motor_GPIO_Init();
	Servo_PWM_Init();
}

int main(void)
{
	Hardware_Init();
	OLED_Clear();
	OLED_ShowString(1,1,"TargerData:",11);
	while(1)
	{ 
		OLED_ShowNum(95,1,OpenMV_Data,1,1);
		BT_Control();
	}
}
