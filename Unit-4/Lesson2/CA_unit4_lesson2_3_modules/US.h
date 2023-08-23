/*
 * US.h
 *
 *  Created on: 22 Aug 2023
 *      Author: Eldeeb
 */

#ifndef US_H_
#define US_H_
#include "state.h"
#include "stdio.h"
#include "stdlib.h"

//Define States
enum{
	US_busy
}US_state_id;

//declare states functions CA

STATE_define(US_busy);

void US_init();

extern void (*US_state)();


#endif /* US_H_ */
