/*
* File: blue_tooth.c
* Author: create by lijie
* Date: 2024-03-25
* Description: This file contains an blue_tooth Init of C code.
* Version: 1.0
*/

#include "blue_tooth.h"

/**************Globel**********************/
uint8_t BT_temp=0;            //�����������ݣ�����״̬���;
/******************************************/

void BT_USART3_Init(uint32_t bound)
{
	GPIO_InitTypeDef GPIO_InitStructure;     //GPIO��ʼ���ṹ������
	USART_InitTypeDef USART_InitStructure;   //���ڳ�ʼ���ṹ������
	NVIC_InitTypeDef    NVIC_InitStructure;  //NVIC��ʼ���ṹ������
		

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);      //ʹ��PB�˿�ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);    //USART3ʱ��
	
	//USART3 TX
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	//USART3 RX
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
		
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;             //�ж�ͨ��ΪUSART3_IRQn
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;     //������ռ���ȼ�2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;            //������Ӧ���ȼ�2 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;               //ͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);                      //����NVIC_Init()������ɶ˿ڳ�ʼ��
		
	USART_InitStructure.USART_BaudRate=bound;             //���ò�����Ϊ9600
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;                      //����λ8λ
	USART_InitStructure.USART_StopBits=USART_StopBits_1;                           //ֹͣλ1λ
	USART_InitStructure.USART_Parity=USART_Parity_No;                              //��У��λ
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;  //��Ӳ������
	USART_InitStructure.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;   //���ܺͷ���ģʽ����
	USART_Init(USART3,&USART_InitStructure);	        //����USART_Init()������ɶ˿ڳ�ʼ��

	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);      //ʹ�ܽ����ж�

	USART_Cmd(USART3,ENABLE);                           //ʹ�ܴ���3
}

void USART3_IRQHandler(void)
{
	if(USART_GetITStatus(USART3,USART_IT_RXNE))//�ж��ж�λ
	{
		USART_ClearITPendingBit(USART3, USART_IT_RXNE);
		BT_temp = USART_ReceiveData(USART3); //�������� 
		USART_SendData(USART3,BT_temp);
		Blue_Tooth_Cmd((uint8_t)BT_temp);
	}
}
