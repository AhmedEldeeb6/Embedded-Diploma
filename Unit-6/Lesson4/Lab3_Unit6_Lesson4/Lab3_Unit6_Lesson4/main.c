/*
 * Lab3_Unit6_Lesson4.c
 *
 * Created: 20/09/2023 1:45:56 am
 * Author : Eldeeb
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

typedef unsigned char uint8_t;

//PORTS
#define DDRB			*(volatile uint8_t *) (0x37)
#define DDRD			*(volatile uint8_t *) (0x31)
#define PORTD			*(volatile uint8_t *) (0x32)

//MCU CONTROL
#define MCUCR			*(volatile uint8_t *) (0x55)

//MCU STATUS AND CONTROL
#define MCUCSR			*(volatile uint8_t *) (0x54)

//GENERAL INTERRUPT CONTROL
#define GICR			*(volatile uint8_t *) (0x5B)

//GENERAL INTERRUPT FLAG
#define GIFR			*(volatile uint8_t *) (0x5A)

//STATUS REGISTER
#define SREG			*(volatile uint8_t *) (0x5F)

void INT_Enable(void)
{

	SREG |= (1<<7);

} 
void EXT0_INIT(void)
{
	//INTERRUPT 0 ANY LOGICAL CHANGE
	MCUCR |= (1<<0);
		
	//Enable Interrupt 0
	GICR |=(1<<6);
	
}

void EXT1_INIT(void)
{
	//INTERRUPT 1 ANY RISING EDGE
	MCUCR |= (1<<2);
	MCUCR |= (1<<3);
	
	//Enable Interrupt 1
	GICR |=(1<<7);
	
}

void EXT2_INIT(void)
{
	//INTERRUPT 2 FALLING EDGE
	MCUCSR &= ~(1<<6);
	
	//Enable Interrupt 2
	GICR |=(1<<5);
}
int main(void)
{
	//INTERRUPT PINS INPUT
	DDRD  &= ~(1<<2);
	DDRD  &= ~(1<<3);
	DDRB  &= ~(1<<2);
	
	//LED PINS OUTPUT 
	DDRD  |= (1<<5);
	DDRD  |= (1<<6);
	DDRD  |= (1<<7);
	
	
	INT_Enable();
	EXT0_INIT();
	EXT1_INIT();
	EXT2_INIT();
	
    /* Replace with your application code */
    while (1) 
    {
		//LEDS ARE OFF 
		PORTD &= ~(1<<5);
		PORTD &= ~(1<<6);
		PORTD &= ~(1<<7);
    }
}

ISR(INT0_vect)
{
	//LED ON
	PORTD |= (1<<5);
	
	_delay_ms(1000);
	
	//RISE FLAG
	GIFR |= (1<<6);
	
}

ISR(INT1_vect)
{
	//LED ON
	PORTD |= (1<<6);
	
	_delay_ms(1000);
	
	//RISE FLAG
	GIFR |= (1<<7);
	
}

ISR(INT2_vect)
{
	//LED ON
	PORTD |= (1<<7);
	
	_delay_ms(1000);
	
	//RISE FLAG
	GIFR |= (1<<5);
	
}