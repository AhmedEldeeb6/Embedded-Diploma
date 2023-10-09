/*
 * KPD_PROGRAM.c
 *
 * Created: 9/13/2022 10:04:00 AM
 *  Author: AHMED ELDEEB
 */ 
/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_INTERFACE.h"

/*HAL*/
#include "KPD_INTERFACE.h"
#include "KPD_CONFIG.h"

void KPD_Get_Value(u8* returned_value )
{
	u8 KPD_COLS_PINS[4]={KPD_COL0_PIN,KPD_COL1_PIN,KPD_COL2_PIN,KPD_COL3_PIN};
	u8 KPD_ROWS_PINS[4]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
	u8 KPD_CHAR[4][4]= KPD_KEYS;
		
	if (returned_value != NULL)
	{
		*returned_value=KPD_NOT_PRESSED;
		u8 cols_counter,rows_counter;
		u8 Pin_value;
		u8 PinFlag=0;
		for(cols_counter=0;cols_counter<4;cols_counter++)
		{
			// ACTIVATE EACH COLOUMN
			DIO_SetPinValue(KPD_COLS_PORT,KPD_COLS_PINS[cols_counter],DIO_PIN_LOW);
		
			// LOOP TO CHECK ROWS VALUES 
			for(rows_counter=0;rows_counter<4;rows_counter++)
			{
			DIO_GetPinValue(KPD_ROWS_PORT,KPD_ROWS_PINS[rows_counter],&Pin_value);
			if (0==Pin_value)
			{
				*returned_value=KPD_CHAR[rows_counter][cols_counter];
				while(0==Pin_value)
				{
					DIO_GetPinValue(KPD_ROWS_PORT,KPD_ROWS_PINS[rows_counter],&Pin_value);

				}
				PinFlag =1;
				break;
			}
			}
			//DEACTIVATE CURRENT COL		
			DIO_SetPinValue(KPD_COLS_PORT,KPD_COLS_PINS[cols_counter],DIO_PIN_HIGH);
			if(1==PinFlag)
			{
				{
					break;
				}
			}		
		}
	}
}
