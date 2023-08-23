/*
 * main.c
 *
 *  Created on: 22 Aug 2023
 *      Author: Eldeeb
 */


#include "CA1.h"

void setup()
{
	//init all the drivers
	//init IQR ....
	//init HAL US_Driver Dc_Driver
	//init BLOCK
	//Set States pointers for each block
	CA_state = STATE(CA_waiting);

}

void main()
{
	setup();
	while(1)
	{
		//call state for each block
		CA_state();
	}
}
