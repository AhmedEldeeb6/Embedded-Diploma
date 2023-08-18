/*
 * main.c
 *
 *  Created on: 14 Aug 2023
 *      Author: Eldeeb
 */
#include "lifo.h"
#include "stdio.h"
#include "stdlib.h"


unsigned int buffer1[7]; // 5*4=20 Bytes at data memory


void main()
{
	element_type i,temp=0;
	LIFO_Buf_t uart_lifo,I2C_lifo;
	//static allocation
	if (LIFO_init(&uart_lifo,buffer1,5)==LIFO_no_error)
		printf("Lifo_Uart init ---- Done \n ");
	//dynamic allocation
	element_type* buffer2 = (element_type*)malloc (7* sizeof(element_type ));//5*4=20 B
	if (LIFO_init (&I2C_lifo,buffer2,5)==LIFO_no_error) // at heap
		printf("Lifo_I2C init ---- Done \n ");

	for (i=0;i<7;i++)
	{
			printf("LIFO Add (%x) \n ", i);

		if (LIFO_Add_item(&uart_lifo,i)==LIFO_no_error)
			printf("UART_LIFO add : %d is done \n",i);	
		else 
			printf("UART_LIFO add : %d is failed \n",i);
	}
	LIFO_Print(&uart_lifo);

	for (i=0;i<2;i++)
		{
		if (LIFO_Get_item(&uart_lifo,&temp)==LIFO_no_error)
			printf("\n(UART)LIFO:delete : %d \n",temp);
		}
	LIFO_Print(&uart_lifo);
}
