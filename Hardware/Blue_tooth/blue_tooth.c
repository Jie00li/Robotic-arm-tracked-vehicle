/*
* File: blue_tooth.c
* Author: create by lijie
* Date: 2024-03-25
* Description: This file contains an blue_tooth Init of C code.
* Version: 1.0
*/

#include "blue_tooth.h"

/**************Globel**********************/
uint8_t BT_temp=0;            //蓝牙接收数据，接收状态标记;
/******************************************/

void BT_USART3_Init(uint32_t bound)
{
	GPIO_InitTypeDef GPIO_InitStructure;     //GPIO初始化结构体声明
	USART_InitTypeDef USART_InitStructure;   //串口初始化结构体声明
	NVIC_InitTypeDef    NVIC_InitStructure;  //NVIC初始化结构体声明
		

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);      //使能PB端口时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);    //USART3时钟
	
	//USART3 TX
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	//USART3 RX
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
		
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;             //中断通道为USART3_IRQn
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;     //设置抢占优先级2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;            //设置响应优先级2 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;               //通道使能
	NVIC_Init(&NVIC_InitStructure);                      //调用NVIC_Init()函数完成端口初始化
		
	USART_InitStructure.USART_BaudRate=bound;             //设置波特率为9600
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;                      //数据位8位
	USART_InitStructure.USART_StopBits=USART_StopBits_1;                           //停止位1位
	USART_InitStructure.USART_Parity=USART_Parity_No;                              //无校验位
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;  //无硬件流控
	USART_InitStructure.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;   //接受和发送模式都打开
	USART_Init(USART3,&USART_InitStructure);	        //调用USART_Init()函数完成端口初始化

	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);      //使能接收中断

	USART_Cmd(USART3,ENABLE);                           //使能串口3
}

void USART3_IRQHandler(void)
{
	if(USART_GetITStatus(USART3,USART_IT_RXNE))//判断中断位
	{
		USART_ClearITPendingBit(USART3, USART_IT_RXNE);
		BT_temp = USART_ReceiveData(USART3); //接收数据 
		USART_SendData(USART3,BT_temp);
		Blue_Tooth_Cmd((uint8_t)BT_temp);
	}
}
