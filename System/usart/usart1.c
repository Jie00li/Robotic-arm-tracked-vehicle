/*
* File: USART1.c
* Author: create by lijie
* Date: 2024-03-22
* Description: This file contains an USART1 Init of C code.
* Version: 1.0
*/

#include "usart1.h"
#include "oled.h"
#include "stdio.h"
#include "OpenMv.h"

void USART1_Init(void)
{
	  //USART1_TX:PA 9   
	  //USART1_RX:PA10
		GPIO_InitTypeDef GPIO_InitStructure;     //串口端口配置结构体变量
		USART_InitTypeDef USART_InitStructure;   //串口参数配置结构体变量
		NVIC_InitTypeDef NVIC_InitStructure;     //串口中断配置结构体变量

		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);   //打开PA端口时钟

    //USART1_TX   PA9
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;          		 //PA9
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  		 //设定IO口的输出速度为50MHz
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	   		 //复用推挽输出
    GPIO_Init(GPIOA, &GPIO_InitStructure);             	 	 //初始化PA9
    //USART1_RX	  PA10
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;             //PA10
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  //浮空输入
    GPIO_Init(GPIOA, &GPIO_InitStructure);                 //初始化PA10 

    //USART1 NVIC 配置
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0 ;  //抢占优先级0
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;		    //子优先级2
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			      //IRQ通道使能
		NVIC_Init(&NVIC_InitStructure);	                          //根据指定的参数初始化VIC寄存器

    //USART 初始化设置
		USART_InitStructure.USART_BaudRate = 115200;                  //串口波特率为115200
		USART_InitStructure.USART_WordLength = USART_WordLength_8b;   //字长为8位数据格式
		USART_InitStructure.USART_StopBits = USART_StopBits_1;        //一个停止位
		USART_InitStructure.USART_Parity = USART_Parity_No;           //无奇偶校验位
		USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;   //无硬件数据流控制
		USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	                  //收发模式
    USART_Init(USART1, &USART_InitStructure);                     //初始化串口1

    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); //使能中断
    USART_Cmd(USART1, ENABLE);                     //使能串口1

  	//如下语句解决第1个字节无法正确发送出去的问题
	  USART_ClearFlag(USART1, USART_FLAG_TC);        //清串口1发送标志
		
}


//USART1 全局中断服务函数
void USART1_IRQHandler(void)			 
{
		u8 com_data;
	
#if SYSTEM_SUPPORT_OS 		//如果SYSTEM_SUPPORT_OS为真，则需要支持OS.
	OSIntEnter();    
#endif
	
	if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
	{
			USART_ClearFlag(USART1,USART_FLAG_RXNE);
      com_data = USART1->DR;
			Openmv_Receive_Data(com_data);     //openmv数据处理函数
			Openmv_Data();		                 //openmv数据处理函数		
  } 
#if SYSTEM_SUPPORT_OS 	//如果SYSTEM_SUPPORT_OS为真，则需要支持OS.
	OSIntExit();  											 
#endif
		
}
