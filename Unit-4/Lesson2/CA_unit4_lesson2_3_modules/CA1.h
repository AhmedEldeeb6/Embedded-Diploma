/*
 * CA1.h
 *
 *  Created on: 22 Aug 2023
 *      Author: Eldeeb
 */

#ifndef CA1_H_
#define CA1_H_
#include "state.h"
#include "stdio.h"
#include "stdlib.h"

//Define States
enum{
	CA_waiting,
	CA_driving
}CA_state_id;

//declare states functions CA

STATE_define(CA_waiting);
STATE_define(CA_driving);

extern void (*CA_state)();


#endif /* CA1_H_ */
