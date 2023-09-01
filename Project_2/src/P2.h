/*
 * P2.h
 *
 *  Created on: 1 Sep 2023
 *      Author: Eldeeb
 */

#ifndef P2_H_
#define P2_H_
#include "stdio.h"
#include "stdint.h"
#include <string.h>
#include "stdlib.h"

//USER Configuration
//select the element type (uint8_t , uint16_t, uint32_t,...)
//Student structure

#define DPRINTF(...)    {fflush(stdout);\
						fflush(stdin);\
						printf(__VA_ARGS__);\
						fflush(stdout);\
						fflush(stdin);}
#define element_type uint8_t
//create buffer 1


typedef struct{
	char First_Name[50];
	char Last_Name[50];
	int Roll_Number;
	float GPA;
	int Courses[50];
}Student_t;


//FIFO data types
typedef struct {
	unsigned int length ;
	unsigned int count ;
	Student_t* base;
	Student_t* head;
	Student_t* tail;
}FIFO_Buf_t;

typedef enum {
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_null
}FIFO_Buf_Status;


//APIs
FIFO_Buf_Status FIFO_init(FIFO_Buf_t* fifo,Student_t* buf , uint32_t length);
FIFO_Buf_Status FIFO_enqueue(FIFO_Buf_t* fifo,Student_t item );
FIFO_Buf_Status FIFO_dequeue(FIFO_Buf_t* fifo,Student_t* item );
FIFO_Buf_Status FIFO_IS_FULL(FIFO_Buf_t* fifo);
void FIFO_print(FIFO_Buf_t* fifo);
FIFO_Buf_Status Add_Student_Manually(FIFO_Buf_t* fifo);
FIFO_Buf_Status Add_Student_From_File(FIFO_Buf_t *fifo);
FIFO_Buf_Status Delete_By_Roll_Number(FIFO_Buf_t* fifo);
FIFO_Buf_Status Search_By_Roll_Number(FIFO_Buf_t* fifo);
FIFO_Buf_Status Search_By_First_Name(FIFO_Buf_t* fifo);
Student_t* Search_The_Roll_Number(FIFO_Buf_t* fifo, int Number);
FIFO_Buf_Status Count_Students (FIFO_Buf_t* fifo);
FIFO_Buf_Status Update_Students (FIFO_Buf_t* fifo);
FIFO_Buf_Status Show_All_Students(FIFO_Buf_t* fifo);

#endif /* P2_H_ */
