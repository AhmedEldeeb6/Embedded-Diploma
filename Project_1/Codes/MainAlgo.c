/*
 * MainAlgo.c
 *
 *  Created on: 30 Aug 2023
 *      Author: lenovo
 */


#include "driver.h"
#include "MainAlgo.h"
#include "Alarm_Monitor.h"

int Main_Pval=0;
int Threshold=10;

void (*Pressure_State)();

void set_pressure_val(int Val)
{
	if(Val>Threshold)
		Pressure_State=STATE(High_Pressure_Detected_state);
	else
		Pressure_State=STATE(High_Pressure_Not_Detected_state);
}

STATE_define(High_Pressure_Not_Detected_state)
{
	Pressure_State_t = High_Pressure_Not_Detected;

	//State

	Main_Pval = getPressureVal();

	set_pressure_val(Main_Pval);
}

STATE_define(High_Pressure_Detected_state)
{
	Pressure_State_t = High_Pressure_Detected;

	//State

	HighPressureDetected();

	Main_Pval = getPressureVal();

	set_pressure_val(Main_Pval);
}

