/*
 * LIFO.c
 *
 *  Created on: 14 Aug 2023
 *      Author: Eldeeb
 */
#include "LIFO.h"

LIFO_status LIFO_init (LIFO_Buf_t* lifo_buf , element_type * buf ,uint32_t length)
{
	if(buf == NULL)
		return LIFO_Null;
	lifo_buf->base = buf;
	lifo_buf->head = buf;
	lifo_buf->length = length;
	lifo_buf->count = 0;

	return LIFO_no_error;
}



LIFO_status LIFO_Add_item(LIFO_Buf_t* lifo_buf , element_type item)
{
	//check lifo is valid
	if (!lifo_buf->base || !lifo_buf->head)
		return LIFO_Null;
	//check lifo is full
	//if(lifo_buf->head >=(lifo_buf->base + (lifo_buf->length*4)))
	//	if(lifo_buf->count==lifo_buf->length)
		//	return LIFO_full;
	if (LIFO_IS_FULL(lifo_buf)==LIFO_full)
		return LIFO_full;

	//add value
		*(lifo_buf->head)=item;
		lifo_buf->head++;
		lifo_buf->count++;

	return LIFO_no_error;
}

LIFO_status LIFO_Get_item(LIFO_Buf_t* lifo_buf , element_type* item)
{
	//check lifo is valid
	if (!lifo_buf->base || !lifo_buf->head)
		return LIFO_Null;
	//check lifo is empty
	if (lifo_buf->count==0)
		return LIFO_empty;

	lifo_buf->head -- ;
	*item = *(lifo_buf->head);
	lifo_buf->count--;

	return LIFO_no_error;
}

void LIFO_Print(LIFO_Buf_t* lifo_buf)
{
	element_type* temp;
	int i;
	if(lifo_buf->count==0)
		printf("lifo is empty");
	else
	{
		temp = lifo_buf->base ;
		printf("\n ======lifo print====== \n");
		for(i=0 ; i<lifo_buf->count ; i++)
		{
			printf("\t %X \n",*temp);
			temp++;
		}
		printf("=========\n");

	}
	
}

LIFO_status LIFO_IS_FULL(LIFO_Buf_t* lifo_buf)
{
	if (!lifo_buf->base || !lifo_buf->head)
		return LIFO_Null;
	if(lifo_buf->count==lifo_buf->length)
			return LIFO_full;
	return LIFO_no_error;
	

}

