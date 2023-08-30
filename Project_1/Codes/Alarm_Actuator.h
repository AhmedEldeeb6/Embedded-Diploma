/*
 * Alarm_Actuator.h
 *
 *  Created on: 30 Aug 2023
 *      Author: lenovo
 */

#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_

#include "state.h"

enum
{
	alarmON,
	alarmOFF
}Alarm_Actuator_State_t;

extern void(*Alarm_Actuator_State)();

void Alarm_Actuator_init();
void StartAlarm();
void StopAlarm();

STATE_define(alarmON);
STATE_define(alarmOFF);

#endif /* ALARM_ACTUATOR_H_ */
