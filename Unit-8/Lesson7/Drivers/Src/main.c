/**
 **************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 **************************
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
 **************************
 */

#if !defined(_SOFT_FP) && defined(_ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

//#define MCU_Act_As_Master
#define MCU_Act_As_Slave

#include "stm32f103x8_gpio_driver.h"
#include "STM32F103x8.h"
#include "stm32f103x8_EXTI_driver.h"
#include "stm32f103x8_USART_driver.h"
#include "stm32f103x8_SPI_driver.h"

unsigned char ch ;

void clock_init()
{

	RCC_GPIOA_CLK_EN();
	RCC_AFIO_CLK_EN();
}

void Ahmed_SPI1_IRQ_Callback (struct S_IRQ_SRC irq_src)
{
#ifdef MCU_Act_As_Slave
	if (irq_src.RXNE)
	{
		ch=0xf;
		MCAL_SPI_TX_RX(SPI1, &ch, PollingDisable);
		MCAL_UART_SendData(USART1, &ch, enable);
	}
#endif
}

void Eldeeb_UART_IRQ_CallBack (void)
{
#ifdef MCU_Act_As_Master

	MCAL_UART_ReceiveData(USART1,&ch, disable);
    MCAL_UART_SendData(USART1,&ch, enable ) ;
    //Send to SPI
    MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
    MCAL_SPI_TX_RX(SPI1, &ch, PollingEnable);
    MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);

#endif
}


void wait (int x)
{
	unsigned int i , j ;
	for (i= 0 ; i<x ; i++)
		for (j= 0 ; j<255 ; j++);
}

int main(void)
{

	clock_init();
	GPIO_PinConfig_t Pin_Cfg ;


	//==================UART INIT====================
	//PA9 -> TX
	//PA10 -> RX
	//PA11 -> CTS
	//PA12 -> RTS


	UART_Config UART_Cnfg;

	//USART1 init
	UART_Cnfg.BaudRate 			= UART_BaudRate_115200;
	UART_Cnfg.USART_Mode 		= UART_MODE_TX_RX;
	UART_Cnfg.Parity 			= UART_Parity__NONE;
	UART_Cnfg.Payload_Length 	= UART_Payload_Length_8B;
	UART_Cnfg.StopBits			= UART_StopBits__1;
	UART_Cnfg.HwFlowCtl			= UART_HwFlowCtl_NONE;

	UART_Cnfg.IRQ_Enable		= UART_IRQ_Enable_RXNEIE;
	UART_Cnfg.P_IRQ_CallBack	= Eldeeb_UART_IRQ_CallBack;

	MCAL_UART_Init(USART1, &UART_Cnfg);


	MCAL_UART_GPIO_Set_Pins(USART1);



	//==================SPI INIT====================
	//PA4 >> SPI1_NSS
	//PA5 >> SPI1_SCK
	//PA6 >> SPI1_MISO
	//PA7 >> SPI1_MOSI

	SPI_Config_t SPI1SFG ;

	//Common configuration
	SPI1SFG.CLK_Phase = SPI_Clock_Phase_2EDGE_first_data_capture_edge ;
	SPI1SFG.CLK_Polarity = SPI_Clock_Polarity_HIGH_when_Idle ;
	SPI1SFG.Data_Size = SPI_Frame_Format_8B ;
	SPI1SFG.Frame_Format = SPI_Frame_Format_MSB_transmitted_first ;
	//Assume by default pclk2 = 8MHz
	SPI1SFG.SPI_BAUDRATEPRESCALER = SPI_BaudRatePrescaler_8 ;
	SPI1SFG.Communication_Mode = SPI_DIRECTION_2LINES ;

#ifdef MCU_Act_As_Master

	SPI1SFG.Device_Mode = SPI_Device_Mode_MASTER ;
	SPI1SFG.IRQ_Enable = SPI_IRQ_Enable_NONE ;
	SPI1SFG.NSS = SPI_NSS_SW_NSSInternalSoft_Set ;
	SPI1SFG.P_IRQ_CallBack = NULL ;

#endif

	MCAL_SPI_Init(SPI1, &SPI1SFG) ;
	MCAL_SPI_GPIO_Set_Pins(SPI1);

	//Configure SS on PA.4 By GPIO
	Pin_Cfg.GPIO_PinNumber = GPIO_PIN_4 ;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP ;
	Pin_Cfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
	MCAL_GPIO_Init(GPIOA, &Pin_Cfg);

    //Force the slave select (High) idle mode
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);

	while (1)
	{

	}

}
