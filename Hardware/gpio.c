#include "head.h"
void Clock_Cmd(void)
{
    Clock_type APB1_Group[]=
    {
        CLK_TIM2,CLK_TIM3,CLK_TIM4,CLK_USART2,CLK_USART3
    };
    Clock_type APB2_Group[]=
    {
        CLK_USART1,CLK_TIM1,CLK_AFIO,CLK_GPIOA,CLK_GPIOB,CLK_GPIOC
    };
    unsigned char Group_Num=sizeof(APB1_Group)/sizeof(APB1_Group[0]);
    for (uint8_t i = 0; i < Group_Num; i++)
    {
        if(APB1_Group[i]==0)continue;
        RCC_APB1PeriphClockCmd(APB1_Group[i],ENABLE);
    }
    for (uint8_t j = 0; j < Group_Num; j++)
    {
        if(APB2_Group[j]==0)continue;
        RCC_APB2PeriphClockCmd(APB2_Group[j],ENABLE);
    }
}

struct GPIO_GROUP_S 
{
    GPIO_Type gpiox;
    GPIOPin_Type pinx;
	GPIOMode_Type modex;
    GPIOSpeed_Type speedx;
};

const struct GPIO_GROUP_S Servo_Group[]=
{
	{GPIOA,Pin_8},{GPIOA,Pin_15},
	{GPIOB,Pin_3},{GPIOB,Pin_4},{GPIOB,Pin_6},{GPIOB,Pin_7},{GPIOB,Pin_8},{GPIOB,Pin_9}
};

struct GPIO_FUN_S/*创建由函数指针组成的结构体*/
{
	void(*Servo_init)(GPIO_Type GPIOx,GPIOPin_Type pinx);
    void(*nled_init)(GPIO_Type GPIOx,GPIOPin_Type pinx);
};

const struct GPIO_FUN_S GPIO_Fun=/*给结构体的指针成员赋值*/
{
	.Servo_init=GPIO_Servo_ENABLE
};

void GPIO_Servo_Init(void)
{
    unsigned char Group_Num=sizeof(Servo_Group)/sizeof(Servo_Group[0]);
	for(uint8_t i=0;i<Group_Num;i++)
	{
		if(Servo_Group[i].gpiox==0)continue;/*放置数组越界程序跑飞的情况*/
        GPIO_Fun.Servo_init(Servo_Group[i].gpiox,Servo_Group[i].pinx);/*调用赋值后的结构体成员*/
    }
}
