/*
 * CA1.c
 *
 *  Created on: 22 Aug 2023
 *      Author: Eldeeb
 */
#include "state.h"
#include "CA1.h"


//variables
int CA_speed=0;
int CA_distance=0;
int CA_threshold=50;

//STATE pointer to function
void(*CA_state)();


void US_Set_distance(int d)
{
	CA_distance=d;
	(CA_distance <= CA_threshold)?  (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("US -----distance = %d----->CA \n",CA_distance);
}


STATE_define(CA_waiting)
{

	//state name
	CA_state_id = CA_waiting;
	printf("CA_Waiting State : distance = %d Speed = %d \n ",CA_distance,CA_speed);


	//state action
	CA_speed=0;
	DC_motor(CA_speed);

	//DC_motor(speed)

	//event check
	//US_Get_distance(CA_distance)
}


STATE_define(CA_driving)
{

	//state name
	CA_state_id = CA_driving;
	printf("CA_Driving State : distance = %d Speed = %d \n ",CA_distance,CA_speed);


	//state action
	CA_speed=30;
	DC_motor(CA_speed);

	//event check
	//US_Get_distance(CA_distance)
}


