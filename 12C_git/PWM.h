#ifndef _PWM_H_
#define _PWM_H_
#include	<config.h>
void PWMInit();
void addPWM(unsigned char dat);
void reducePWM(unsigned char dat);
void setPWM(unsigned char dat);
sbit PWM=P1^3;

#endif
