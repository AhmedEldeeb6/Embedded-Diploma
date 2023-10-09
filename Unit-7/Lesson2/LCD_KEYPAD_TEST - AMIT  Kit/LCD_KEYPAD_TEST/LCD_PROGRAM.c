/*
 * LCD_PROGRAM.c
 *
 * Created: 9/11/2022 11:28:29 AM
 *  Author: AHMED ELDEEB
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_INTERFACE.h"

/*HAL*/
#include "LCD_CONFIG.h"
#include "LCD_INTERFACE.h"

void LCD_Init(void)
{
	_delay_ms(35);
	
	//set Rs to 0 (write command)
	DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
	
	//set R/W to 0 to write
	DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	
	//WRITE THE MOST 4 BITS COMMANDS ON DATA PINS
	LCD_Write_Half_Port(0b0010);
	
	/*Enable pulse*/
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	
	// the initialization the 8 bits
	LCD_Send_Cmd(0b00101000);
	_delay_us(45);
	
	//Display on, cursor on,blink on
	LCD_Send_Cmd(0b00001100);
	_delay_us(45);
	
	//clear display 
	LCD_Send_Cmd(0b00000001);
	_delay_ms(1.6);
	
	//Entry mode 
	LCD_Send_Cmd(0b00000110);
	

}
void LCD_Send_Cmd(u8 Cmd)
{
	//set Rs to 0 (write command)
	DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
	
	//set R/W to 0 to write 
	DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	
	//WRITE THE MOST 4 BITS COMMANDS ON DATA PINS
	LCD_Write_Half_Port(Cmd>>4);
	
	/*Enable pulse*/
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	
	//WRITE THE LEAST 4 BITS COMMANDS ON DATA PINS
	LCD_Write_Half_Port(Cmd);
	
	/*Enable pulse*/
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
}

void LCD_Send_Char(u8 Data)
{
	//set Rs to 1 (write data)
	DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
	
	//set R/W to 0 to write
	DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
	
	//WRITE THE MOST 4 BITS DATA ON DATA PINS
	LCD_Write_Half_Port(Data>>4);
	
	/*Enable pulse*/
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
	
	//WRITE THE LEAST 4 BITS DATA ON DATA PINS
	LCD_Write_Half_Port(Data);
	
	/*Enable pulse*/
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN3,DIO_PIN_LOW);
}
void LCD_Send_string(u8 *str) //store address value of the string in pointer *str
{	
	if (str!=NULL)
	{
	int character=0;
	while(str[character]!='\0') // loop will go on till the NULL character in the string
	{
		LCD_Send_Char(str[character]); // sending data on LCD byte by byte
		character++;
	}
	}
	return;
}

void LCD_CLEAR(void)
{
	//clear display
	LCD_Send_Cmd(0b00000001);
	_delay_ms(1.6);
}

void LCD_SHIFT(u8 Shift_Direction)
{
	if (ShiftRight==Shift_Direction)
	{
		LCD_Send_Cmd(0b00011100);
		_delay_ms(1000);
	}
	else if (ShiftLeft==Shift_Direction)
	{
		LCD_Send_Cmd(0b00011000);
		_delay_ms(1000);
	}
}

void LCD_goToSpecificPosition(u8 LineNumber, u8 Position)
{
	if(LineNumber == Line_1)
	{
		if(Position <= 15)
		{
			LCD_Send_Cmd(0x80 + Position);
		}
	}

	else if (LineNumber == Line_2)
	{
		if(Position <= 15)
		{
			LCD_Send_Cmd (0xc0 + Position);
		}
	}
}


void CreateCustomCharacter (u8 *Pattern, u8 Position, u8 LineNumber,u8 Location)
{	if (LineNumber==Line_1)
	{
		
			if(Position <= 15)
			{
				LCD_Send_Cmd(0x80 + Position);
				int pattern_counter=0;
				LCD_Send_Cmd (0x40+(Location*8));     //Send the Address of CGRAM
				for (pattern_counter=0; pattern_counter<8; pattern_counter++)
				LCD_Send_string (Pattern [ pattern_counter ] );         //Pass the bytes of pattern on LCD
			}
		}

		else if (LineNumber == Line_2)
		{
			if(Position <= 15)
			{
				LCD_Send_Cmd(0xc0 + Position);
				int pattern_counter=0;
				LCD_Send_Cmd (0x40+(Location*8));     //Send the Address of CGRAM
				for (pattern_counter=0; pattern_counter<8; pattern_counter++)
				LCD_Send_string (Pattern [ pattern_counter ] );         //Pass the bytes of pattern on LCD
			}
		}
}

static void LCD_Write_Half_Port(u8 value)
{
	if(1 ==GET(value,0))
	{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
	}
	else 
	{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);	
	}
	
	if(1 ==GET(value,1))
	{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
	}
	else
	{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
	}
	
	if(1 ==GET(value,2))
	{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_HIGH);
	}
	else
	{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN6,DIO_PIN_LOW);
	}
	
	if(1 ==GET(value,3))
	{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
	}
	else
	{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_LOW);
	}
}
