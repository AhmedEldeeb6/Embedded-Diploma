/*
 * LIFO.h
 *
 *  Created on: 14 Aug 2023
 *      Author: Eldeeb
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"



//User Configrations 
//select element type (uint8_t , uint16_t , uint32_t,....)
#define element_type uint8_t
//create buffer 1 
#define width1 5
element_type uart_buffer[width1];

//Lifo data types 
typedef struct LIFO_Buf {
	unsigned int length ;
	unsigned int count ;
	element_type * base;
	element_type * head;
}LIFO_Buf_t;

typedef enum {
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_Null
}LIFO_status;

//APIs
LIFO_status LIFO_init (LIFO_Buf_t* lifo_buf , element_type * buf ,uint32_t length);
LIFO_status LIFO_Add_item(LIFO_Buf_t* lifo_buf , element_type item);
LIFO_status LIFO_Get_item(LIFO_Buf_t* lifo_buf , element_type* item);
LIFO_status LIFO_IS_FULL(LIFO_Buf_t* lifo_buf);
void LIFO_Print(LIFO_Buf_t* lifo_buf);



#endif /* LIFO_H_ */
