/*
 * US.c
 *
 *  Created on: 22 Aug 2023
 *      Author: Eldeeb
 */
#include "state.h"
#include "US.h"


//variables

int US_distance=0;

//STATE pointer to function
void(*US_state)();
int US_Get_distance_random(int l , int r , int count);

void US_init()
{
	//init US Driver
	printf("US_init \n");
}

STATE_define(US_busy)
{
	//state name
	US_state_id = US_busy;
	//State Action
	US_distance=US_Get_distance_random(45,55,1);

	printf("US_Waiting State : distance = %d \n ",US_distance);
	US_Set_distance(US_distance);
	//Loop
	US_state = STATE(US_busy);

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
