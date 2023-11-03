/*
 * UART_TESR.c
 *
 * Created: 03/11/2023 4:37:12 pm
 * Author : Eldeeb
 */ 

#define F_CPU 8000000UL

//MCAL 
#include "UART_INTERFACE.h"

//HAL
#include "LCD_CONFIG.h"
#include "LCD_INTERFACE.h"
#include "KPD_CONFIG.h"
#include "KPD_INTERFACE.h"

void DIO_init(void)
{
		//lcd pins
		DIO_SetPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);//data lcd
		DIO_SetPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);//data lcd
		DIO_SetPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);//data lcd
		DIO_SetPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);//data lcd
		DIO_SetPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);// lcd RS
		DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);// lcd RW
		DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);// lcd EN
		
		//uart
		DIO_SetPinDirection(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);
		DIO_SetPinDirection(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);

				};

int main(void)
{

	DIO_init();
	LCD_Init();
	LCD_Send_string("UART TR");
	LCD_Send_Cmd(0xC0);
	
	UART_init();
	UART_Send_String("Ahmed");
	UART_Send('T');
	u8 x;
    /* Replace with your application code */
    while (1) 
    {
		LCD_Send_Cmd(0xC0);

		x=UART_Receive();

		LCD_Send_Char(x);
    }
}

