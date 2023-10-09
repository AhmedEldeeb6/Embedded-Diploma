/*
 * LCD_KEYPAD_TEST_AMIT.c
 *
 * Created: 05/10/2023 5:00:25 pm
 * Author : Eldeeb
 */ 

#define F_CPU 8000000UL
#include "util/delay.h"

//Utils
#include "ATMEGA32_REG.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"

//MCAL
#include "DIO_INTERFACE.h"

//HAL
#include "LCD_CONFIG.h"
#include "LCD_INTERFACE.h"
#include "KPD_INTERFACE.h"
#include "KPD_CONFIG.h"


int main(void)
{
	//lcd pins 
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);//data lcd
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);//data lcd
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);//data lcd
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);//data lcd
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);// lcd RS
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);// lcd RW
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);// lcd EN
	
	//Keypad pins 
	DIO_SetPinDirection(KPD_COLS_PORT,KPD_COL0_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(KPD_COLS_PORT,KPD_COL1_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(KPD_COLS_PORT,KPD_COL2_PIN,DIO_PIN_OUTPUT);
	DIO_SetPinDirection(KPD_COLS_PORT,KPD_COL3_PIN,DIO_PIN_OUTPUT);
	
	DIO_SetPinDirection(KPD_ROWS_PORT,KPD_ROW0_PIN,DIO_PIN_INPUT);
	DIO_SetPinDirection(KPD_ROWS_PORT,KPD_ROW1_PIN,DIO_PIN_INPUT);
	DIO_SetPinDirection(KPD_ROWS_PORT,KPD_ROW2_PIN,DIO_PIN_INPUT);
	DIO_SetPinDirection(KPD_ROWS_PORT,KPD_ROW3_PIN,DIO_PIN_INPUT);
	
	DIO_setInputPinResistance(KPD_ROWS_PORT,KPD_ROW0_PIN);
	DIO_setInputPinResistance(KPD_ROWS_PORT,KPD_ROW1_PIN);
	DIO_setInputPinResistance(KPD_ROWS_PORT,KPD_ROW2_PIN);
	DIO_setInputPinResistance(KPD_ROWS_PORT,KPD_ROW3_PIN);
	
	LCD_Init();
	u8 KPD_KEY,counter;

    /* Replace with your application code */
    while (1) 
    {
		KPD_Get_Value(&KPD_KEY);
		if(KPD_NOT_PRESSED!=KPD_KEY)
		{
			if(counter ==16)
			{
				
				LCD_goToSpecificPosition(Line_2,0);
			}
			else if (counter>32)
			{
				
				counter=0;
				LCD_CLEAR();
			}
			if (KPD_KEY=='!')
			{
				LCD_CLEAR();
				counter=0;
			}
			else
			{
			LCD_Send_Char(KPD_KEY);
			DIO_SetPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);
			DIO_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);
			counter++;
			}
			
		}

    }
}

