/*
 * Task3_Unit7_Lesson1.c
 *
 * Created: 01/10/2023 10:16:12 pm
 * Author : Eldeeb
 */ 

#include "MemMap.h"
#include "Utils.h"
#define F_CPU 8000000UL
#include <util/delay.h>


//static unsigned char SegmentNumber[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	
int main(void)
{	int flag=7;
	DDRD = 0b11111000;
    /* Replace with your application code */
    while (1) 
    {
		
		if(ReadBit(PIND,0)==1)
		{
			if (flag>4)
			{
			SetBit(PORTD,flag);
			flag--;
			}
			else if (flag==4)
			{
					SetBit(PORTD,flag);
					_delay_ms(1000);
					ClearBit(PORTD,flag);
					flag--;
			}
			else
			{
				PORTD=0;
				flag=7;
			}
				while( ReadBit(PIND,0) == 1 );
		}

		_delay_ms(100);
    }
}

