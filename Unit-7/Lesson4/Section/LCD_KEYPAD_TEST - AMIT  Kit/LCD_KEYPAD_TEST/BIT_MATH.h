 /*
 * DIO_PROGRAM.c
 *
 * Created: 9/6/2022 11:32:49 AM
 *  Author: Ahmed Eldeeb
 */ 
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET(VAR,BIT_NUM)	VAR|=(1<<BIT_NUM)
#define RESET(VAR,BIT_NUM) 	VAR&=(~(1<<BIT_NUM))
#define TOG(VAR,BIT_NUM) 	VAR^=(1<<BIT_NUM)
#define GET(VAR,BIT_NUM) 	((VAR>>BIT_NUM)&1)





#endif