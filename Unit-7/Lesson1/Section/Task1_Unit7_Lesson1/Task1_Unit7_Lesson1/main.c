/*
 * Task1_Unit7_Lesson1.c
 *
 * Created: 30/09/2023 7:06:10 pm
 * Author : Eldeeb
 */ 

#include "MemMap.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	DDRA = 0b11111111;
    /* Replace with your application code */
    while (1) 
    {
		int i;
		for(i=0;i<=7;i++)
		{
			PORTA |=(1<<i); 
			_delay_ms(100);
		}
		for(i=7;i>=0;i--)
		{
			PORTA &=~(1<<i);
			_delay_ms(100);
		}
    }
}

