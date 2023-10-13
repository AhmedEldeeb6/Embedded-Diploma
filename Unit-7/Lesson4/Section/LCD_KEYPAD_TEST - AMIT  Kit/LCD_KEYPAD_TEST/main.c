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

	LCD_Init();
	LCD_Send_string("Learn In Depth");
	LCD_goToSpecificPosition(1,0);
	LCD_Send_string("Made By Ahmed");

    /* Replace with your application code */
    while (1) 
    {


    }
}

