/*
 * Utils.h
 *
 * Created: 01/10/2023 8:54:20 pm
 *  Author: Eldeeb
 */ 


#ifndef UTILS_H_
#define UTILS_H_
	
#define SetBit(reg,bit)			(reg = reg|(1<<bit))
#define ClearBit(reg,bit)		(reg =reg&~(1<<bit))
#define ReadBit(reg,bit)		((reg>>bit) & 1)
#define ToggleBit(reg,bit)		(reg =reg^(1<<bit))

#endif /* UTILS_H_ */