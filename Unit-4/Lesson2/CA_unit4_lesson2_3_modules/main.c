/*
 * main.c
 *
 *  Created on: 22 Aug 2023
 *      Author: Eldeeb
 */


#include "CA1.h"
#include "US.h"
#include "DC.h"

void setup()
{
	//init all the drivers
	//init IQR ....
	//init HAL US_Driver Dc_Driver
	//init BLOCK
	US_init();
	DC_init();
	//Set States pointers for each block
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);


}

void main()
{
	setup();
	while(1)
	{
		//call state for each block
		US_state();
		CA_state();
		DC_state();
	}
}
