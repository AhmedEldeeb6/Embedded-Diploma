/*
 * main.c
 *
 *  Created on: 1 Sep 2023
 *      Author: Eldeeb
 */


#include "P2.h"
#define width1 5
Student_t uart_buffer[width1];
int main()
{
	FIFO_Buf_t FIFO_UART;
	if (FIFO_init(&FIFO_UART,uart_buffer,50)==FIFO_no_error)
		DPRINTF("Fifo init --- Done \n");
	int x;
	while (1)
	{
		DPRINTF("\n============");

		DPRINTF("\n\t Choose one of the following options: ");

		DPRINTF("\n1:Add Student Manually ");

		DPRINTF("\n2:Delete Student ");

		DPRINTF("\n3:Search With Roll Number ");

		DPRINTF("\n4:Search With First Name");

		DPRINTF("\n5:Search With Courses");

		DPRINTF("\n6:Count Students");

		DPRINTF("\n7:Update Student");

		DPRINTF("\n8:Add_From_File");

		DPRINTF("\n9:Show All Students");

		DPRINTF("\nEnter an Option : ");

		scanf("%d",&x);

		DPRINTF("\n============\n");

		switch(x)
		{
		case 1:
			Add_Student_Manually(&FIFO_UART);
			break;
		case 2:
			Delete_By_Roll_Number(&FIFO_UART);
			break;
		case 3:
			Search_By_Roll_Number(&FIFO_UART);
			break;
		case 4:
			Search_By_First_Name(&FIFO_UART);
			break;
		case 5:
			Search_The_Courses(&FIFO_UART);
			break;
		case 6:
			Count_Students(&FIFO_UART);
			break;
		case 7:
			Update_Students(&FIFO_UART);
			break;
		case 8:
			Add_Student_From_File(&FIFO_UART);
			break;
		case 9:
			Show_All_Students(&FIFO_UART);
			break;
		default:
			DPRINTF("\n wrong option");
			break;
		}
	}
	return 0;
}



