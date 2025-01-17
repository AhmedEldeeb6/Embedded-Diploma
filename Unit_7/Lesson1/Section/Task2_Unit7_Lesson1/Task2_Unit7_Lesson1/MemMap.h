/*
 * MemMap.h
 *
 * Created: 30/09/2023 7:12:16 pm
 *  Author: Eldeeb
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_

#define DDRA		*(volatile unsigned char *)(0x3A)
#define PORTA		*(volatile unsigned char *)(0x3B)
#define PINA		*(volatile unsigned char *)(0x39)


#define DDRC		*(volatile unsigned char *)(0x34)
#define PORTC		*(volatile unsigned char *)(0x35)
#define PINC		*(volatile unsigned char *)(0x33)

#endif /* MEMMAP_H_ */