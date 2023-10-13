 /*
 * DIO_PROGRAM.c
 *
 * Created: 9/6/2022 11:32:49 AM
 *  Author: Ahmed Eldeeb
 */ 
 
 /* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_INTERFACE.h"
/* Pin Apis */
void DIO_SetPinDirection(u8 PortId,u8 PinId,u8 PinDirection )
{
	if((PortId<=3) && (PinId<=7) && ((PinDirection==DIO_PIN_OUTPUT) || (PinDirection==DIO_PIN_INPUT)))
	{
	switch(PortId)
	{
		case 0: // DIO_PORTA
		if (DIO_PIN_OUTPUT==PinDirection)
		{
			SET(DDRA,PinId);
		}
		else 
		{
			RESET(DDRA,PinId);
		}
		break;
		
		case 1: // DIO_PORTB
		if (DIO_PIN_OUTPUT==PinDirection)
		{
			SET(DDRB,PinId);
		}
		else
		{
			RESET(DDRB,PinId);
		}
		break;
		
		case 2: // DIO_PORTC
		if (DIO_PIN_OUTPUT==PinDirection)
		{
			SET(DDRC,PinId);
		}
		else
		{
			RESET(DDRC,PinId);
		}
		break;
		
		case 3: // DIO_PORTD
		if (DIO_PIN_OUTPUT==PinDirection)
		{
			SET(DDRD,PinId);
		}
		else
		{
			RESET(DDRD,PinId);
		}
		break;
	}
	}
}
void DIO_SetPinValue(u8 PortId,u8 PinId,u8 PinValue)
{
	if ((PortId<=3) && (PinId<=7) && ((PinValue==DIO_PIN_HIGH) || (PinValue==DIO_PIN_LOW) ))
	{
		switch(PortId)
		{
			case 0: //DIO_PORTA
					if (DIO_PIN_HIGH==PinValue)
					{
						SET(PORTA,PinId);
					}	
					else
					RESET(PORTA,PinId);
					break;
					
			case 1: //DIO_PORTB
			if (DIO_PIN_HIGH==PinValue)
			{
				SET(PORTB,PinId);
			}
			else
			RESET(PORTB,PinId);
			break;
			
			case 2: //DIO_PORTC
			if (DIO_PIN_HIGH==PinValue)
			{
				SET(PORTC,PinId);
			}
			else
			RESET(PORTC,PinId);
			break;
			
			case 3: //DIO_PORTD
			if (DIO_PIN_HIGH==PinValue)
			{
				SET(PORTD,PinId);
			}
			else
			RESET(PORTD,PinId);  
			break;
		}
	}
}
void DIO_GetPinValue(u8 PortId,u8 PinId,u8* PinValue)
{
	if ((PortId<=3) && (PinId<=7) && (PinValue!=NULL))
	{
		switch(PortId)
		{
			case 0 : //DIO_PORTA
			if (DIO_PIN_HIGH== GET(PINA,PinId))
			{
				*PinValue=DIO_PIN_HIGH;
			} 
			else 
			{
				*PinValue=DIO_PIN_LOW;
			}
			break;
			
			case 1 : //DIO_PORTB
			if (DIO_PIN_HIGH== GET(PINB,PinId))
			{
				*PinValue=DIO_PIN_HIGH;
			}
			else
			{
				*PinValue=DIO_PIN_LOW;
			}
			break;
			
			case 2 : //DIO_PORTC
			if (DIO_PIN_HIGH== GET(PINC,PinId))
			{
				*PinValue=DIO_PIN_HIGH;
			}
			else
			{
				*PinValue=DIO_PIN_LOW;
			}
			break;
			
			case 3 : //DIO_PORTD
			if (DIO_PIN_HIGH== GET(PIND,PinId))
			{
				*PinValue=DIO_PIN_HIGH;
			}
			else
			{
				*PinValue=DIO_PIN_LOW;
			}
			break;

		}
	}
}
void DIO_TogglePinValue	(u8 PortId,u8 PinId)
{
	if ((PortId<=3) && (PinId<=7))
	{
		switch(PortId)
		{
			case 0: //DIO_PORTA
			TOG(PORTA,PinId);
			break;
			
			case 1: //DIO_PORTB
			TOG(PORTB,PinId);
			break;
			
			case 2: //DIO_PORTC
			TOG(PORTC,PinId);
			break;
			
			case 3: //DIO_PORTD
			TOG(PORTD,PinId);
			break;
			
		}
	}
}
void DIO_setInputPinResistance(u8 PortId, u8 PinId)
{
	if((PortId<=3) && (PinId<=7))
	{
		switch(PortId)
		{
			case 0:
			SET(PORTA,PinId);
			break;
			
			case 1:
			SET(PORTB,PinId);
			break;
			
			case 2:
			SET(PORTC,PinId);
			break;
			
			case 3:
			SET(PORTD,PinId);
			break;
		}
	}
}
void DIO_SetPortDirection(u8 PortId,u8 PortDirection )
{
		if ((PortId<=3) && ((DIO_PORT_OUTPUT==PortDirection) || (DIO_PORT_INPUT==PortDirection)))
		{
			switch (PortId) 
			{
				case 0:
				if (DIO_PORT_OUTPUT==PortDirection)
				{
					DDRA=0xff;
				}
				else 
				{
					DDRA=0x00;
				}
				break;
				
				case 1:
				if (DIO_PORT_OUTPUT==PortDirection)
				{
					DDRB=0xff;
				}
				else
				{
					DDRB=0x00;
				}
				break;
				
				case 2:
				if (DIO_PORT_OUTPUT==PortDirection)
				{
					DDRC=0xff;
				}
				else
				{
					DDRC=0x00;
				}
				break;
				
				case 3:
				if (DIO_PORT_OUTPUT==PortDirection)
				{
					DDRD=0xff;
				}
				else
				{
					DDRD=0x00;
				}
				break;
			}
		}	
}
void DIO_SetPortValue(u8 PortId,u8 PortValue)
{
	if ((PortId<=3))
	{
		switch (PortId)
		{
		case 0:
		PORTA=PortValue;
		break;
		
		case 1:
		PORTB=PortValue;
		break;
		
		case 2:
		PORTC=PortValue;
		break;
		
		case 3:
		PORTD=PortValue;
		break;
		}
	}
}
void DIO_GetPortValue(u8 PortId,u8* PortValue)
{
	if ((PortId<=3) && PortValue!= NULL)
	{
		switch(PortId)
		{
			case 0:
			*PortValue=PINA;
			break;
			
			case 1:
			*PortValue=PINB;
			break;
			
			case 2:
			*PortValue=PINC;
			break;
			
			case 3:
			*PortValue=PIND;
			break;
		}
	}
}
void DIO_TogglePortValue(u8 PortId)
{
	if (PortId<=3)
	{
		switch(PortId)
		{
			case 0:
			PORTA = ~PORTA;
			break;
			
			case 1:
			PORTB = ~PORTB;
			break;
			
			case 2:
			PORTC = ~PORTC;
			break;
			
			case 3:
			PORTD = ~PORTD;
			break;
		}
	}
}
void DIO_setInputPortResistance(u8 PortId)
{
	if(PortId<=3)
	{
		switch(PortId)
		{
			case 0:
			PORTA = 0xff;
			break;
			
			case 1:
			PORTB = 0xff;
			break;
			
			case 2:
			PORTC = 0xff;
			break;
			
			case 3:
			PORTD = 0xff;
			break;
		}
	}
}