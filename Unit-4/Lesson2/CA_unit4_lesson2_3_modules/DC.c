/*
 * DC.c
 *
 *  Created on: 22 Aug 2023
 *      Author: Eldeeb
 */
#include "state.h"
#include "DC.h"


//variables
int DC_speed=0;

//STATE pointer to function
void(*DC_state)();

void DC_init()
{
	//init PWM
	printf("DC_init \n");
}

void DC_motor(int s)
{
	DC_speed=s;

	DC_state=STATE(DC_busy);

	printf("CA -----speed = %d----->CA \n",DC_speed);

}


STATE_define(DC_idle)
{

	//state name
	DC_state_id = DC_idle;

	//state action
	//CALL PWM to make speed = DC_speed
	printf("DC_Idle State : Speed = %d \n ",DC_speed);




}


STATE_define(DC_busy)
{

	//state name
	DC_state_id = DC_busy;

	//state action
	//CALL PWM to make speed = DC_speed
	DC_state=STATE(DC_idle);
	printf("DC_busy State : Speed = %d \n ",DC_speed);



}




