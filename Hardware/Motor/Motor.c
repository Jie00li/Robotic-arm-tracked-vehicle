/*
* File: Motor.c
* Author: create by lijie
* Date: 2024-03-25
* Description: This file contains an Motor Init of C code.
* Version: 1.0
*/

#include "Motor.h"

void Motor_GPIO_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//推挽输出
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_0;   //BIN1、BIN2
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//推挽输出
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6|GPIO_Pin_7;   //AIN1、AIN2
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	Motor_PWM_Init();
}

void Motor_PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;		//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 36 - 1;		//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;		//CCR
	
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);	
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);
  
	TIM_Cmd(TIM2, ENABLE);
}
	
void Motor_LEFT_Speed(int8_t Speed)		
{
	if (Speed >= 0)    //左电机正转
	{
			AIN1 = 0;
			AIN2 = 1;
		  TIM_SetCompare3(TIM2, Speed);
	}
	else               //左电机反转
	{
			AIN1 = 1;
			AIN2 = 0;
		  TIM_SetCompare3(TIM2, Speed);
	} 
}

void Motor_RIGHT_Speed(int8_t Speed)		
{
	if (Speed >= 0)   //右电机正转
	{
			BIN1 = 0;
			BIN2 = 1;
		  TIM_SetCompare4(TIM2, Speed);
	}
	else             //右电机反转
	{
			BIN1 = 1;
			BIN2 = 0;
		  TIM_SetCompare4(TIM2, Speed);
	}
}
