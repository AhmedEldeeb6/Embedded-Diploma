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
int US_Get_distance_random(int l , int r , int count);


STATE_define(CA_waiting)
{

	//state name
	CA_state_id = CA_waiting;

	//state action
	CA_speed=0;
	//DC_motor(speed)

	//event check
	//US_Get_distance(CA_distance)
	CA_distance=US_Get_distance_random(45,55,1);
	(CA_distance <= CA_threshold)?  (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("CA_Waiting State : distance = %d Speed = %d \n ",CA_distance,CA_speed);
}


STATE_define(CA_driving)
{

	//state name
	CA_state_id = CA_driving;

	//state action
	CA_speed=30;
	//DC_motor(speed)

	//event check
	//US_Get_distance(CA_distance)
	CA_distance=US_Get_distance_random(45,55,1);
	(CA_distance <= CA_threshold)?  (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("CA_Driving State : distance = %d Speed = %d \n ",CA_distance,CA_speed);
}

int US_Get_distance_random(int l , int r , int count)
{
	// generate random from l to r
	int i;
	for(i=0;i<count;i++)
	{
		int rand_num = (rand() % (r-l+1))+l;
		return rand_num;
	}
}
