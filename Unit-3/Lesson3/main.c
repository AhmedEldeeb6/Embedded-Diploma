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
#define RCC_BASE 		0x40021000
#define PORTA_BASE 		0x40010800
#define RCC_APB2ENR		*(volatile uint32_t *) (RCC_BASE + 0x18)
#define GPIOA_CRH    	*(volatile uint32_t *) (PORTA_BASE + 0x04)
#define GPIOA_ODR		*(volatile uint32_t *) (PORTA_BASE + 0x0C)

//bit fields 
#define RCC_IOPAEN 		(1<<2)
#define GPIOA13	 		(1UL<<13)

extern void NMI_Hnadler(void)
{

}

extern void Bus_Fault(void)
{
	
}


typedef union {
	vint32_t allfields;
	struct {
		vint32_t reserved:13;
		vint32_t pin13:1;
	}pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR =(volatile R_ODR_t*)(PORTA_BASE + 0x0C);
unsigned char g_variables[3]={1,2,3};
unsigned char const const_variables[3]={1,2,3};
volatile unsigned char bss_var[3];

int main(void)
{
	RCC_APB2ENR |=RCC_IOPAEN;
	GPIOA_CRH &=0xFF0FFFFF;
	GPIOA_CRH |=0x00200000;

	while(1)
	{
		//GPIOA_ODR |= 1<<13; //SET BIT 13
		R_ODR->pin.pin13=1;
		for(int i=0;i<5000;i++);
		//GPIOA_ODR &= ~(1<<13); //clear BIT 13
		R_ODR->pin.pin13=0;
		for(int i=0;i<5000;i++);
	}
	return 0;
}