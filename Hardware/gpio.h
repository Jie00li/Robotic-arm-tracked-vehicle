#include "head.h"
#ifndef __GPIO_H
#define __GPIO_H

/*1.时钟组*/
#define Clock_type uint32_t
#define CLK_TIM2 RCC_APB1Periph_TIM2
#define CLK_TIM3 RCC_APB1Periph_TIM3
#define CLK_TIM4 RCC_APB1Periph_TIM4
#define CLK_USART2 RCC_APB1Periph_USART2
#define CLK_USART3 RCC_APB1Periph_USART3
#define CLK_USART1 RCC_APB2Periph_USART1
#define CLK_TIM1 RCC_APB2Periph_TIM1
#define CLK_AFIO RCC_APB2Periph_AFIO
#define CLK_GPIOA RCC_APB2Periph_GPIOA
#define CLK_GPIOB RCC_APB2Periph_GPIOB
#define CLK_GPIOC RCC_APB2Periph_GPIOC
/****************************************/

/*2.GPIO组*/
#define GPIO_Type GPIO_TypeDef*//GPIO组
#define GPIOPin_Type uint16_t//Pin口
#define GPIOMode_Type GPIOMode_TypeDef//输出模式
#define GPIOSpeed_Type  GPIOSpeed_TypeDef

#define Pin_0 GPIO_Pin_0
#define Pin_1 GPIO_Pin_1
#define Pin_2 GPIO_Pin_2
#define Pin_3 GPIO_Pin_3
#define Pin_4 GPIO_Pin_4
#define Pin_5 GPIO_Pin_5
#define Pin_6 GPIO_Pin_6
#define Pin_7 GPIO_Pin_7
#define Pin_8 GPIO_Pin_8
#define Pin_9 GPIO_Pin_9
#define Pin_10 GPIO_Pin_10
#define Pin_11 GPIO_Pin_11
#define Pin_12 GPIO_Pin_12
#define Pin_13 GPIO_Pin_13
#define Pin_14 GPIO_Pin_14
#define Pin_15 GPIO_Pin_15

#define Mode_AIN GPIO_Mode_AIN
#define Mode_INF GPIO_Mode_IN_FLOATING
#define Mode_IPD GPIO_Mode_IPD
#define Mode_IPU GPIO_Mode_IPU
#define Mode_OOD GPIO_Mode_Out_OD
#define Mode_OPP GPIO_Mode_Out_PP
#define Mode_AOD GPIO_Mode_AF_OD
#define Mode_APP GPIO_Mode_AF_PP

#define  Speed_10MHz GPIO_Speed_10MHz
#define  Speed_2MHz GPIO_Speed_2MHz
#define  Speed_50MHz GPIO_Speed_50MHz

#endif
