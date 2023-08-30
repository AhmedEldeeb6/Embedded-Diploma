/*
 * Alarm_Monitor.c
 *
 *  Created on: 30 Aug 2023
 *      Author: lenovo
 */

#include "Alarm_Monitor.h"
#include "driver.h"
#include "Alarm_Actuator.h"

int Alarm_Timer = 60;

void HighPressureDetected()
{
	Alarm_Monitor_State = STATE(alarm_monitor_ON);
}

void (*Alarm_Monitor_State)();

STATE_define(alarm_monitor_ON)
{
	Alarm_Monitor_State_t = alarm_monitor_ON;

	//State

	StartAlarm();

	Alarm_Monitor_State = STATE(alarm_monitor_waiting);

}

STATE_define(alarm_monitor_OFF)
{
	Alarm_Monitor_State_t = alarm_monitor_OFF;

	//State

	StopAlarm();

	Alarm_Monitor_State = STATE(alarm_monitor_OFF);

}

STATE_define(alarm_monitor_waiting)
{
	Alarm_Monitor_State_t = alarm_monitor_waiting;

	//State

	Delay(Alarm_Timer);

	Alarm_Monitor_State = STATE(alarm_monitor_OFF);

}


