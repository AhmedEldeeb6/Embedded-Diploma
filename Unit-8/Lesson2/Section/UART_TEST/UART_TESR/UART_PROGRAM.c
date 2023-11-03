/*
 * UART.c
 *
 * Created: 03/11/2023 4:39:33 pm
 *  Author: ELDEEB
 */ 

#include "UART_INTERFACE.h"

// APIs

void UART_init (void)
{
	// BoadRate
	UBRRL = 51 ;
	
	UCSRA &= ~(1<<1);
	
	//Frame
	
	//no parity
	// 8-bit data
	
	// Enable
	
	UCSRB |= (0b11<<3);
	
}

void UART_Send (u8 data)
{
	while( !((UCSRA>> 5) & 1) );
	UDR= data ;
}

u8 UART_Receive (void)
{
	while( !((UCSRA >> 7) & 1) );
	return UDR ;
}

void UART_Send_String (char* p)
{
	while(*p){
		UART_Send(*p);
		p++;
	}
}

void UART_Receive_String (void)
{
	for(int i=0 ; i<100 ; i++)
	{
		if (CH[i] == 0) break;
		CH[i] = 0 ;
	}
	u8* PCH = CH ;
	while (1)
	{
		*PCH = UART_Receive();
		if(*PCH == '!' )
		{
			*PCH = 0 ;
			break;
		}
		PCH++ ;
	}
}


