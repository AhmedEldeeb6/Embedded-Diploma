/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdint.h>

typedef volatile unsigned int  vint32_t;

//register address

//RCC 
#define RCC_BASE 		0x40021000
#define RCC_APB2ENR		*(volatile uint32_t *) (RCC_BASE + 0x18)
#define RCC_IOPAEN 		(1<<2)

//PORTA 
#define PORTA_BASE 		0x40010800
#define GPIOA_CRL		*(volatile uint32_t *) (PORTA_BASE + 0x00)
#define GPIOA_CRH    	*(volatile uint32_t *) (PORTA_BASE + 0x04)
#define GPIOA_ODR		*(volatile uint32_t *) (PORTA_BASE + 0x0C)
#define GPIOA13	 		(1UL<<13)

//EXTI 
#define EXTI_BASE 		0x40010400
#define EXTI_IMR		*(volatile uint32_t *) (EXTI_BASE + 0x00)
#define EXTI_RTSR		*(volatile uint32_t *) (EXTI_BASE + 0x08)
#define EXTI_PR			*(volatile uint32_t *) (EXTI_BASE + 0x14)

//AFIO
#define AFIO_BASE 		0x40010000
#define AFIO_EXTICR1	*(volatile uint32_t *) (AFIO_BASE + 0x08)


#define NVIC_EXTIE0		*(volatile uint32_t *) (0XE000E100)

void Clock_init()
{
	//Enable clock GPIOA 
	RCC_APB2ENR |= RCC_IOPAEN;
	
	
	//Bit 0 AFIOEN: Alternate function I/O clock enable
	RCC_APB2ENR |= (1<<0);
}

void GPIO_init()
{
	//pin 13 in port a output bin 
	GPIOA_CRH &=0xFF0FFFFF;
	GPIOA_CRH |=0x00200000;
	
	//PinA 0: 01 Floating input (reset state)
	GPIOA_CRL |= (1<<2);
	
}

int main(void)
{
	Clock_init();
	GPIO_init();
	//: EXTI0 configuration (x= 0 ) TO PORTA0 
	AFIO_EXTICR1 = 0;
	//Enable Rising Trigger
	EXTI_RTSR |= (1<<0);

	//Enable External line 0 (Mask 1)
	EXTI_IMR |= (1<<0);
	
	//Enable NVIC Irq6 <<>> EXTI0
	NVIC_EXTIE0 |= (1<<6);
	
	
	while(1);


	return 0;
}

void EXTI0_IRQHandler(void)
{
	//IQR is Happened EXTI0 >>> PORTA pin 0 _|- rising edge 
	//toggle led pinA 13
	GPIOA_ODR ^=(1<<13);

	//Clear Pending request for line 1 
	EXTI_PR |= (1<<0);
}
