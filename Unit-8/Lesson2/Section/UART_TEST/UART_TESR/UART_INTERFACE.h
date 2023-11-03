/*
 * UART.h
 *
 * Created: 03/11/2023 4:39:48 pm
 *  Author: lenovo
 */ 


#ifndef UART_H_
#define UART_H_

//UTILS
#include "ATMEGA32_REG.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"

//MCAL 
#include "DIO_INTERFACE.h"

char CH[100];
// APIs


void UART_init (void);


void UART_Send (u8 data);


u8 UART_Receive (void);

void UART_Send_String (char* p);
void UART_Receive_String (void);



#endif /* UART_H_ */