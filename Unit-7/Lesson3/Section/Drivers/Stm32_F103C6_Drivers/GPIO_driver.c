/*
 * GPIO_driver.c
 *
 *  Created on: Oct 5, 2023
 *      Author: Eldeeb
 */


#include "GPIO_driver.h"
#include "STM32_F103C6.h"

uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch(PinNumber)
	{
	case GPIO_PIN_0:
		return 0 ;
		break;

	case GPIO_PIN_1:
		return 4;
		break;

	case GPIO_PIN_2:
		return 8;
		break;

	case GPIO_PIN_3:
		return 12;
		break;

	case GPIO_PIN_4:
		return 16;
		break;

	case GPIO_PIN_5:
		return 20;
		break;

	case GPIO_PIN_6:
		return 24;
		break;

	case GPIO_PIN_7:
		return 28;
		break;

	//CRH
	case GPIO_PIN_8:
		return 0;
		break;

	case GPIO_PIN_9:
		return 4;
		break;

	case GPIO_PIN_10:
		return 8;
		break;

	case GPIO_PIN_11:
		return 12;
		break;

	case GPIO_PIN_12:
		return 16;
		break;

	case GPIO_PIN_13:
		return 20;
		break;

	case GPIO_PIN_14:
		return 24;
		break;

	case GPIO_PIN_15:
		return 28;
		break;


	}
	return 0;
}


/**================================================================
 * @Fn				-MCAL_GPIO_Init
 * @brief 			-Initializes the GPIOx PINy periphral according to the specified parameters in the PinConfiguration
 * @param [in] 		-GPIOx: Where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in] 		-PinConfig pointer to a GPIO_PinConfig_t structure that contains the configuration information for the specified GPIO peripheral
 * @retval 			-None
 * Note				-Stm32F103C6 MCU has GPIO A,B,C,D,E Modules But LQFP48 Package has only GPIO A,B,Part of C,D exported as external PINS from the MCU
 */

void MCAL_GPIO_Init(GPIO_Typedef *GPIOx,GPIO_PINConfig_t* PinConfig)
{
	//Port configuration register low (GPIOx_CRL) Configure PINS from 0 >> 7
	//Port configuration register high (GPIOx_CRH) Configure PINS from 8 >> 15
	volatile uint32_t* ConfigRegister =(PinConfig->GPIO_PinNumber <GPIO_PIN_8)? &GPIOx->CRL : &GPIOx->CRH ; ;
	volatile uint8_t pin_config =0;


	//clear CNFx[1:0] MODEx[1:0] [4 bits]
	(*ConfigRegister) &= ~(0xf << Get_CRLH_Position(PinConfig->GPIO_PinNumber));

	//check if selected mode is OUTPUT
	if((PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP ) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD)|| (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP)|| (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD) )
	{
		pin_config = ( (( (PinConfig->GPIO_MODE - 4) << 2 ) | (PinConfig->GPIO_OUTPUT_SPEED)) & 0x0f) ;

	}
	else{ 	//configure pins if selected mode is INTPUT MODEx[1:0]=0x00


		if( (PinConfig->GPIO_MODE == GPIO_MODE_Analog) || (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO) )
		{

			pin_config = ( (( (PinConfig->GPIO_MODE ) << 2 ) | 0x00 ) & 0x0f) ;

		}
		else if(PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT)
		{ //considered as floating input

			pin_config = ( (( (GPIO_MODE_INPUT_FLO) << 2 ) | 0x00 ) & 0x0f) ;

		}
		else
		{

			pin_config = ( (( (GPIO_MODE_INPUT_PU) << 2 ) | 0x00 ) & 0x0f) ;

			//to select between PullUp and PullDown modes
			if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU){

				//table 20.Port bit configuration table : PxODR -> 1
				GPIOx->ODR |= (PinConfig->GPIO_PinNumber);

			}
			else
			{
				//table 20.Port bit configuration table : PxODR -> 1
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
			}
		}
	}
	//write on CRL or CRH
	(*ConfigRegister) |= ((pin_config)<<Get_CRLH_Position(PinConfig->GPIO_PinNumber));

}


/**================================================================
 * @Fn				-MCAL_GPIO_DeInit
 * @brief 			-Reset all GPIO Registers
 * @param [in] 		-GPIOx: Where x can be (A..E depending on device used) to select the GPIO peripheral
 * @retval 			-None
 * Note				-None
 */

void MCAL_GPIO_DeInit(GPIO_Typedef *GPIOx)
{
	if (GPIOx == GPIOA){

		RCC->APB2RSTR |=  (1 << 2) ;  //Bit 2 IOPARST: IO port A reset
		RCC->APB2RSTR &= ~(1 << 2) ;

	}
	else if (GPIOx == GPIOB){

		RCC->APB2RSTR |=  (1 << 3) ;  //Bit 3 IOPBRST: IO port B reset
		RCC->APB2RSTR &= ~(1 << 3) ;

	}
	else if (GPIOx == GPIOC){

		RCC->APB2RSTR |=  (1 << 4) ;  //Bit 4 IOPCRST: IO port C reset
		RCC->APB2RSTR &= ~(1 << 4) ;

	}
	else if (GPIOx == GPIOD){

		RCC->APB2RSTR |=  (1 << 5) ;  //Bit 5 IOPDRST: IO port D reset
		RCC->APB2RSTR &= ~(1 << 5) ;

	}
	else{

		RCC->APB2RSTR |=  (1 << 6) ;  //Bit 6 IOPERST: IO port E reset
		RCC->APB2RSTR &= ~(1 << 6) ;

	}

}

/**================================================================
 * @Fn				-MCAL_GPIO_ReadPin
 * @brief 			-Read Specific Pin
 * @param [in] 		-GPIOx: Where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in]		-PinNumber: Set Pin number According to @ref GPIO_PINS_define
 * @retval 			-the input pin value (two values based on @ref GPIO_PIN_state)
 * Note				-None
 */

uint8_t MCAL_GPIO_ReadPin(GPIO_Typedef *GPIOx,uint16_t PinNumber)
{
	if((GPIOx->IDR & PinNumber) != (uint32_t)GPIO_PIN_RESET )
	{

		return GPIO_PIN_SET;
	}
	else
	{

		return GPIO_PIN_RESET ;
	}
}


/**================================================================
 * @Fn				-MCAL_GPIO_ReadPort
 * @brief 			-Read Input Port Value
 * @param [in] 		-GPIOx: Where x can be (A..E depending on device used) to select the GPIO peripheral
 * @retval 			-the input port value
 * Note				-None
 */

uint16_t MCAL_GPIO_ReadPort(GPIO_Typedef *GPIOx)
{
	return (uint16_t)GPIOx->IDR;
}

/**================================================================
 * @Fn				-MCAL_GPIO_WritePin
 * @brief 			-Write Specific Pin
 * @param [in] 		-GPIOx: Where x can be (A..G depending on device used) to select the GPIO peripheral
 * @param [in]		-PinNumber: specifies the port bit to read. Set By @ref GPIO_PINS_define
 * @retval 			-None
 * Note				-None
 */

void MCAL_GPIO_WritePin(GPIO_Typedef *GPIOx,uint16_t PinNumber,uint8_t Value)
{

	//We can use ODR and Also we can use BSRR to reset and BRR to set pin value
	//i'm using BSRR to reset and BRR to set pin values

	if(Value == (uint8_t)GPIO_PIN_SET)
	{
		/*  Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
	These bits are write-only and can be accessed in Word mode only.
	0: No action on the corresponding ODRx bit
	1: Set the corresponding ODRx bit              */

		GPIOx->BSRR = (uint32_t)PinNumber;
	}

	else
	{

		/*	Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
	These bits are write-only and can be accessed in Word mode only.
	0: No action on the corresponding ODRx bit
	1: Reset the corresponding ODRx bit				*/

		GPIOx->BRR = (uint32_t)PinNumber;
	}
}

/**================================================================
 * @Fn				-MCAL_GPIO_WritePort
 * @brief 			-Write Output Port Value
 * @param [in] 		-GPIOx: Where x can be (A..G depending on device used) to select the GPIO peripheral
 * @retval 			-None
 * Note				-None
 */

void MCAL_GPIO_WritePort(GPIO_Typedef *GPIOx,uint16_t Value)
{
	GPIOx->ODR = (uint32_t)Value;
}

/**================================================================
 * @Fn				-MCAL_GPIO_TogglePin
 * @brief 			-Toggle The Specified GPIO pin
 * @param [in] 		-GPIOx: Where x can be (A..G depending on device used) to select the GPIO peripheral
 * @param [in]		-PinNumber: specifies the port bit to read. Set By @ref GPIO_PINS_define
 * @retval 			-None
 * Note				-None
 */

void MCAL_GPIO_TogglePin(GPIO_Typedef *GPIOx,uint16_t PinNumber)
{
	GPIOx->ODR ^= (uint32_t)PinNumber;
}

/**================================================================
 * @Fn				-MCAL_GPIO_LockPin
 * @brief 			-The Locking Mechanism allows the IO configuration to be Frozen
 * @param [in] 		-GPIOx: Where x can be (A..G depending on device used) to select the GPIO peripheral
 * @param [in]		-PinNumber: specifies the port bit to read. Set By @ref GPIO_PINS_define
 * @retval 			-Ok if piN Config is locked Or Error if pin is not locked (OK and ERROR are define @ref GPIO_RETURN_LOCK)
 * Note				-None
 */


uint8_t MCAL_GPIO_LockPin(GPIO_Typedef *GPIOx,uint16_t PinNumber)
{


		// Bit 16 LCKK[16]: Lock key
		// This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
		// 0: Port configuration lock key not active
		// 1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
		// LOCK key writing sequence:
		// Write 1
		// Write 0
		// Write 1
		// Read 0
		// Read 1 (this read is optional but confirms that the lock is active)
		//		Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
		//		Any error in the lock sequence will abort the lock.

		// Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
		//	These bits are read write but can only be written when the LCKK bit is 0.
		//	0: Port configuration not locked
		//	1: Port configuration locked.

		//Set LCCK[16]
		volatile uint32_t temp= 1<<16;


		//write 1 in the selected pin
		GPIOx->LCKR |= (uint32_t)PinNumber;

		//Bit 16 LCKK[16]: Lock key Lock sequence:

		temp |= (uint32_t)PinNumber;
		// Write 1
		GPIOx->LCKR = temp;

		// Write 0
		GPIOx->LCKR = (uint32_t)PinNumber;

		// Write 1
		GPIOx->LCKR = temp;

		// Read 0
		temp = GPIOx->LCKR;

		// Read 1 (this read is optional but confirms that the lock is active)
		if((uint32_t)(GPIOx->LCKR & (1<<16)))
		{
			return GPIO_RETURN_LOCK_ENABLE;
		}
		else
		{
			return GPIO_RETURN_LOCK_ERROR;
		}
}
