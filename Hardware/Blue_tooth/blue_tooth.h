#ifndef	__BLUE_TOOTH_H
#define	__BLUE_TOOTH_H
#include "sys.h"
#include "BlueMotor.h"

void BT_GPIO_Init(void);
void BT_USART3_Init(uint32_t bound);
void Blue_Tooth_Cmd(uint8_t Usart_Data);
#endif
