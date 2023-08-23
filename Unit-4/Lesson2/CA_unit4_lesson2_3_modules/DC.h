/*
 * DC.h
 *
 *  Created on: 22 Aug 2023
 *      Author: Eldeeb
 */

#ifndef DC_H_
#define DC_H_
#include "state.h"
#include "stdio.h"
#include "stdlib.h"

//Define States
enum{
	DC_idle,
	DC_busy
}DC_state_id;

//declare states functions CA

STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();
extern void (*DC_state)();



#endif /* DC_H_ */
