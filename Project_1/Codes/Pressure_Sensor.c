/*
 * Pressure_Sensor.c
 *
 *  Created on: 30 Aug 2023
 *      Author: lenovo
 */

#include "Pressure_Sensor.h"
#include "driver.h"
#include "MainAlgo.h"


int Pval=0;
int P_sensor_pull_timer=100;

void Pressure_Sensor_init()
{
	//Initializing Sensor
}

void (*Pressure_Sensor_State)();

STATE_define(Presure_Sensor_Waiting)
{
	Pressure_Sensor_State_t = Pressure_Sensor_Reading;

	//State

	Delay(P_sensor_pull_timer);

	Pressure_Sensor_State = STATE(Presure_Sensor_Reading);
}

STATE_define(Presure_Sensor_Reading)
{
	Pressure_Sensor_State_t = Pressure_Sensor_Reading;

	//State

	Pval = getPressureVal();

	set_pressure_val(Pval);

	Pressure_Sensor_State = STATE(Presure_Sensor_Waiting);
}


