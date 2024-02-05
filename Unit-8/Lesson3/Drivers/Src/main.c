/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ahmed Mohamed Eldeeb
 * @brief          : Unit8_Lesson3_UART_Controller
 * 					 [CASE Study 2 with Debugging : using Interrupt mechanism]
 *
 *
 ******************************************************************************
 *		This application is used to test My USART driver for STM32F103x8 Based on LQFP48 Package.
 *		it is required to communicate with Virtual Terminal Through USART1,USART2,USART3 to test
 *		my Driver APIs especially send and receive for each USART instance in the Package using
 *		the following configurations:
 *
 *      BaudRate = 115200
 *      Parity = None
 *      Payload_width = 8 bit
 *      Stop Bits = 1
 *      Flow Control = None
 *		IRQ_Enable FOR RXNE Pin
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

//-----------------------------
//Includes
//-----------------------------

//UTILS
#include "STM32F103x8.h"

//MCALL
#include "STM32F103x8_GPIO_driver.h"
#include "STM32F103x8_USART_driver.h"

unsigned char IRQ_FLAG = 0;

void clock_init()
{

	RCC_GPIOA_CLK_EN();
	RCC_AFIO_CLK_EN();
}

unsigned char ch;

void UART_IRQ_Callback()
{
	MCAL_UART_ReceiveData(USART1, &ch, disable);
	MCAL_UART_SendData(USART1, &ch, enable);
}



int main(void)
{
	//Initializations
	clock_init();


	UART_Config UART_Cnfg;

	//USART1 init
	UART_Cnfg.BaudRate 			= UART_BaudRate_115200;
	UART_Cnfg.USART_Mode 		= UART_MODE_TX_RX;
	UART_Cnfg.Parity 			= UART_Parity__NONE;
	UART_Cnfg.Payload_Length 	= UART_Payload_Length_8B;
	UART_Cnfg.StopBits			= UART_StopBits__1;
	UART_Cnfg.HwFlowCtl			= UART_HwFlowCtl_NONE;

	UART_Cnfg.IRQ_Enable		= UART_IRQ_Enable_RXNEIE;
	UART_Cnfg.P_IRQ_CallBack	= UART_IRQ_Callback;

	MCAL_UART_Init(USART1, &UART_Cnfg);


	MCAL_UART_GPIO_Set_Pins(USART1);
	while(1)
	{

	}

}
