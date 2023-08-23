/*
 * state.h
 *
 *  Created on: 22 Aug 2023
 *      Author: Eldeeb
 */

#ifndef STATE_H_
#define STATE_H_

//Automatic State function generated
#define STATE_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_)  ST_##_statFUN_


//States connection
void US_Set_distance(int d);
void DC_motor(int s);

#endif /* STATE_H_ */
