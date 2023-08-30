/*
 * MainAlgo.h
 *
 *  Created on: 30 Aug 2023
 *      Author: lenovo
 */

#ifndef MAINALGO_H_
#define MAINALGO_H_

#include "state.h"

enum
{
	High_Pressure_Not_Detected,
	High_Pressure_Detected
}Pressure_State_t;


extern void (*Pressure_State)();

void set_pressure_val(int Val);

STATE_define(High_Pressure_Not_Detected_state);
STATE_define(High_Pressure_Detected_state);


#endif /* MAINALGO_H_ */
