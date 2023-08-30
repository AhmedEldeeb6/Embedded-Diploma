#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "Alarm_Actuator.h"
#include "Alarm_Monitor.h"
#include "MainAlgo.h"
#include "Pressure_Sensor.h"

void setup()
{
	//inizialization of drivers
	GPIO_INITIALIZATION();
	Alarm_Actuator_init();
	Pressure_Sensor_init();

	//Set States
	Alarm_Actuator_State = STATE(alarmOFF);
	Alarm_Monitor_State = STATE(alarm_monitor_OFF);
	Pressure_State = STATE(High_Pressure_Not_Detected_state);
	Pressure_Sensor_State = STATE(Presure_Sensor_Reading);
}

int main ()
{
	setup();
	GPIO_INITIALIZATION();
	while (1)
	{
		//Implement your Design 
		Alarm_Actuator_State();
		Alarm_Monitor_State();
		Pressure_State();
		Pressure_Sensor_State();
		Delay(10);
	}

}
