/*
* File: OpenMv.c
* Author: create by lijie
* Date: 2024-03-22
* Description: This file contains an OpenMv funtion of C code.
* Version: 1.0
*/

#include "OpenMv.h"

int openmv[4];//stm32接收数据数组
int8_t OpenMV_Data;          /*OPENMV 识别人的数据*/

void Openmv_Receive_Data(int16_t data)//接收Openmv传过来的数据
{
	static u8 state = 0;
	int i=0;
	if(state==0&&data==0x2C)
	{
		state=1;
		openmv[0]=data;
	}
	else if(state==1&&data==0x12)
	{
		state=2;
		openmv[1]=data;
	}
	else if(state==2)
	{
		state=3;
		openmv[2]=data;
	}
	else if(state==3)		//检测是否接受到结束标志
	{
        if(data == 0x5B)
        {
            state = 0;
            openmv[3]=data;
            Openmv_Data();
        }
        else if(data != 0x5B)
        {
            state = 0;
            for(i=0;i<4;i++)
            {
                openmv[i]=0x00;
            }           
        }
	}    
	else
		{
			state = 0;
            for(i=0;i<5;i++)
            {
                openmv[i]=0x00;
            }
		}
}

void Openmv_Data(void)
{
    OpenMV_Data=openmv[2];
}
