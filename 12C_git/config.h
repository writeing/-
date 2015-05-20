#ifndef _CONFIG_H_
#define _CONFIG_H_
#include 	<STC12C5A60S2.H>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

#define uchar unsigned char
#define uint unsigned int  

void UartInit(void);		//9600bps@11.0592MHz
void UART1_Send_String(unsigned char *str);
void UART1_Send_Byte(unsigned char ddata);
#endif
