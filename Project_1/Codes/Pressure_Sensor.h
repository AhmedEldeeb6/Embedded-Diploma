/*
 * Pressure_Sensor.h
 *
 *  Created on: 30 Aug 2023
 *      Author: lenovo
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "state.h"

//Define States
enum
{
	Pressure_Sensor_Waiting,
	Pressure_Sensor_Reading

}Pressure_Sensor_State_t;

//Pointer to function
extern void (*Pressure_Sensor_State)();

void Pressure_Sensor_init();
void set_pressure_val(int Val);

STATE_define(Presure_Sensor_Waiting);
STATE_define(Presure_Sensor_Reading);

#endif /* PRESSURE_SENSOR_H_ */
