/*
 * Alarm_Monitor.h
 *
 *  Created on: 30 Aug 2023
 *      Author: lenovo
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "state.h"

enum
{
	alarm_monitor_ON,
	alarm_monitor_OFF,
	alarm_monitor_waiting
}Alarm_Monitor_State_t;

extern void (*Alarm_Monitor_State)();

void HighPressureDetected();

STATE_define(alarm_monitor_ON);
STATE_define(alarm_monitor_OFF);
STATE_define(alarm_monitor_waiting);


#endif /* ALARM_MONITOR_H_ */
