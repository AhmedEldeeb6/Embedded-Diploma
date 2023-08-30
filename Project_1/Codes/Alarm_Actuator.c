/*
 * Alarm_Actuator.c
 *
 *  Created on: 30 Aug 2023
 *      Author: lenovo
 */

#include "driver.h"
#include "Alarm_Actuator.h"

void(*Alarm_Actuator_State)();

void Alarm_Actuator_init()
{
	//initialization
}

void StartAlarm()
{
	Alarm_Actuator_State = STATE(alarmON);
}

void StopAlarm()
{
	Alarm_Actuator_State = STATE(alarmOFF);
}

STATE_define(alarmON)
{
	//State_Name
	Alarm_Actuator_State_t = alarmON;

	//State action
	Set_Alarm_actuator(0);
}

STATE_define(alarmOFF)
{
	//State_Name
	Alarm_Actuator_State_t = alarmOFF;

	//State action
	Set_Alarm_actuator(1);
}
