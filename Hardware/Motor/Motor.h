#ifndef	__MOTOR_H
#define	__MOTOR_H
#include "sys.h"

#define AIN1 PAout(7)
#define AIN2 PAout(6)

#define BIN1 PBout(0)
#define BIN2 PBout(1)

void Motor_GPIO_Init(void);
void Motor_PWM_Init(void);
void Motor_LEFT_Speed(int32_t Speed);
void Motor_RIGHT_Speed(int32_t Speed);
#endif
