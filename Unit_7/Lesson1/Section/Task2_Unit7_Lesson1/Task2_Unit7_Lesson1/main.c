/*
 * Task2_Unit7_Lesson1.c
 *
 * Created: 01/10/2023 8:52:49 pm
 * Author : Eldeeb
 */ 

#include "MemMap.h"
#include "Utils.h"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
	DDRA = 0bff;
	ClearBit(DDRC,0);
	SetBit(PORTC,0);
	unsigned char flag =0;
	int i;
    /* Replace with your application code */
    while (1) 
    {
		if (ReadBit(PINC,0)==0)
		{
			for(i=0;i<=flag;i++)
			{
				SetBit(PORTA,i);	
			}
			flag++;
			_delay_ms(500);
		}
    }
}

