/*
 * FIFO.c
 *
 *  Created on: 16 Aug 2023
 *      Author: Eldeeb
 */
#include "P2.h"



FIFO_Buf_Status FIFO_init(FIFO_Buf_t* fifo,Student_t* buf , uint32_t length)
{
	if (buf==NULL)
		return FIFO_null;

	fifo->base = buf;
	fifo->head = buf;
	fifo->tail = buf;
	fifo->length = length;
	fifo->count = 0;

	return FIFO_no_error;
}
FIFO_Buf_Status FIFO_enqueue(FIFO_Buf_t* fifo,Student_t item )
{
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;
	//fifo is full
	if(FIFO_IS_FULL(fifo)==FIFO_full)
		return FIFO_full;

	*(fifo->head)=item;
	fifo->count++;

	//circular fifo
	if(fifo->head == (fifo->base + (fifo->length * sizeof(Student_t))))
		fifo->head = fifo->base ;
	else
		fifo->head++;
	return FIFO_no_error;
}
FIFO_Buf_Status FIFO_dequeue(FIFO_Buf_t* fifo,Student_t* item )
{
	if (!fifo->base||!fifo->head||!fifo->tail)
		return FIFO_null;
	if(fifo->count==0)
		return FIFO_empty;

	*item = *(fifo->tail);
	fifo->count--;

	if(fifo->tail == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->tail = fifo->base ;
	else
		fifo->tail++;
	return FIFO_no_error;

}
FIFO_Buf_Status FIFO_IS_FULL(FIFO_Buf_t* fifo)
{
	if (!fifo->base||!fifo->head||!fifo->tail)
		return FIFO_null;
	if(fifo->count==fifo->length)
		return FIFO_full;
	return FIFO_no_error;
}
void FIFO_print(FIFO_Buf_t* fifo)
{
	Student_t* temp;
	int i ;
	if(fifo->count==0)
	{
		DPRINTF("fifo is empty \n");
	}
	else
	{
		temp = fifo->tail ;
		DPRINTF("\n ======fifo print====== \n");
		for(i=0 ; i<fifo->count ; i++)
		{
			DPRINTF("\t %X \n",*temp);
			temp++;
		}
		DPRINTF("=========\n");
	}
}


FIFO_Buf_Status Add_Student_Manually(FIFO_Buf_t* fifo)
{

	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;

	//fifo is full
	if(FIFO_IS_FULL(fifo)==FIFO_full)
		return FIFO_full;


	Student_t New_Student;
	int i , number_of_coarses;

	DPRINTF("******** Student Details ******** \n");
	DPRINTF("Enter Roll Number :");
	scanf("%d",&New_Student.Roll_Number);
	fflush(stdin);
	fflush(stdout);

	if (Search_The_Roll_Number(fifo,New_Student.Roll_Number)!=NULL)
	{
		DPRINTF("\nSorry Student Roll Number Exists");
		return FIFO_null;
	}

	DPRINTF("\nEnter Student First Name : ");
	scanf("%s",New_Student.First_Name);

	DPRINTF("\nEnter Student Last Name : ");
	scanf("%s",New_Student.Last_Name);

	DPRINTF("\nEnter Student GPA : ");
	scanf("%f",&New_Student.GPA);

	DPRINTF("\nEnter Number Of Coarses : ");
	scanf("%d",&number_of_coarses);

	for(i=0;i<number_of_coarses;i++)
	{
	DPRINTF("\nEnter Student Coarse Number %d :  ",i+1);
	scanf("%d",&New_Student.Courses[i]);
	}

	if(FIFO_enqueue(fifo,New_Student)==FIFO_no_error)
		return FIFO_no_error;


	else
		return FIFO_null;
}

FIFO_Buf_Status Add_Student_From_File(FIFO_Buf_t *fifo)
{
	FILE *Student_Data;
	int i,Courses_Number;
	Student_t New_Student;

	Student_Data = fopen("Student_Data.txt","r");
	fflush(stdin);
	fflush(stdout);

	if(Student_Data == NULL)
	{
		DPRINTF("Adding Data from file failed. \n");
		return FIFO_null;
	}

	while(!feof(Student_Data))
	{
		fscanf(Student_Data,"%d", &New_Student.Roll_Number);
		fflush(stdin);
		fflush(stdout);

		if(Search_The_Roll_Number (fifo, New_Student.Roll_Number)!=NULL)
		{
			DPRINTF("The Roll number %d is already exist \n",New_Student.Roll_Number);
			fscanf(Student_Data,"%*[^\n]");
			fflush(stdin);
			fflush(stdout);
			continue;
		}

		fscanf(Student_Data,"%s",New_Student.First_Name);
		fflush(stdin);
		fflush(stdout);
		fscanf(Student_Data,"%s",New_Student.Last_Name);
		fflush(stdin);
		fflush(stdout);
		fscanf(Student_Data,"%f",&New_Student.GPA);
		fflush(stdin);
		fflush(stdout);
		fscanf(Student_Data,"%d",&Courses_Number);
		fflush(stdin);
		fflush(stdout);
		for (i = 0; i < Courses_Number; i++)
		{
			fscanf(Student_Data, "%d", &New_Student.Courses[i]);
			fflush(stdin);
			fflush(stdout);
		}

		if((FIFO_enqueue(fifo, New_Student))== FIFO_no_error)
		{
			DPRINTF("Added successfully\n");
			return FIFO_no_error;
		}
		else
		{
			DPRINTF("Failed\n");
			return FIFO_null;
		}
	}

	fclose(Student_Data);
	return FIFO_no_error;
}


FIFO_Buf_Status Delete_By_Roll_Number(FIFO_Buf_t* fifo)
{
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;
	Student_t *Student;
	int Roll_Number;
	DPRINTF("\nEnter The Roll Number You Want to Delete : ");
	scanf("%d",&Roll_Number);
	Student = Search_The_Roll_Number(fifo,Roll_Number);
	if (Student==NULL)
	{
		DPRINTF("\nSorry Student Roll Number doesn't exist ");
		return FIFO_null;
	}
	else
	{
		if(FIFO_dequeue(fifo,Student)==FIFO_no_error)
		{
			DPRINTF("*****Delete Successfully*****");
			return FIFO_no_error;
		}
		else
		{
			DPRINTF("*****Delete Failed*****");
			return FIFO_null;
		}
	}
}




FIFO_Buf_Status Search_By_Roll_Number(FIFO_Buf_t* fifo)
{
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;

	//fifo is full
	if(FIFO_IS_FULL(fifo)==FIFO_full)
		return FIFO_full;

	int Roll_Number,i;

	DPRINTF("\nEnter The Roll Number : ");
	scanf("%d",&Roll_Number);
	if (Search_The_Roll_Number(fifo,Roll_Number)==NULL)
	{
		DPRINTF("\nSorry Student Roll Number Doesn't Exist");
		return FIFO_null;
	}
	else
		{
		Student_t *Exist_Student;
		Exist_Student=Search_The_Roll_Number(fifo,Roll_Number);
		DPRINTF("\nFirst Name Of Roll Number %d : %s",Roll_Number,Exist_Student->First_Name);
		DPRINTF("\nLast Name Of Roll Number %d : %s",Roll_Number,Exist_Student->Last_Name);
		DPRINTF("\nGPA Of Roll Number %d : %f",Roll_Number,Exist_Student->GPA);
		DPRINTF("\nCourses Of Roll Number %d : ",Roll_Number);
		for(i=0;Exist_Student->Courses[i]!=NULL;i++)
		{
			DPRINTF("%d ",Exist_Student->Courses[i]);
		}
	}
	return FIFO_no_error;
}

FIFO_Buf_Status Search_By_First_Name(FIFO_Buf_t* fifo)
{
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;

	//fifo is full
	if(FIFO_IS_FULL(fifo)==FIFO_full)
		return FIFO_full;

	Student_t *pt_student = fifo->tail;
	int i,counter=0 ;
	char Name[50];

	DPRINTF("\nEnter The First Name to search : ");
	scanf("%s",Name);
	fflush(stdin);
	fflush(stdout);
	for(i=0;i<fifo->count;i++)
	{

		if(!(strcmp(Name,pt_student->First_Name)))
		{
			DPRINTF("\nRoll Number Of First Name %s : %d",pt_student->First_Name,pt_student->Roll_Number);
			DPRINTF("\nLast Name Of First Name %s : %s",pt_student->First_Name,pt_student->Last_Name);
			DPRINTF("\nGPA Of First Name %s : %f",pt_student->First_Name,pt_student->GPA);
			DPRINTF("\nCourses Of First Name %s ",pt_student->First_Name);
			for(i=0;pt_student->Courses[i]!=NULL;i++)
			{
				DPRINTF("%d ",pt_student->Courses[i]);
			}
		}

		else
		{
			counter++;
		}

		if((pt_student+1)==(fifo->base + fifo->length))
		{
			pt_student = fifo->base;
		}
		else
		{
			pt_student++;
		}
	}

		if(counter==fifo->count)
		{
			DPRINTF("\nNo Student With This Name");
			return FIFO_empty;
		}

	return FIFO_no_error;
}

FIFO_Buf_Status Search_The_Courses(FIFO_Buf_t* fifo)
{
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;

	//fifo is full
	if(FIFO_IS_FULL(fifo)==FIFO_full)
		return FIFO_full;

	int i,j,Course_Number,counter=0;
	Student_t *Student=fifo->tail;
	DPRINTF("\nPlease Enter The Course Number : ");
	scanf("%d",&Course_Number);
	for (i=0;i<fifo->count;i++)
	{
		for(j=0;Student->Courses[j]!=NULL;j++)
		{
			if(Course_Number==Student->Courses[j])
			{
				DPRINTF("\nRoll Number Of Course_Number %d : %d",Course_Number,Student->Roll_Number);
				DPRINTF("\nFirst Name Of Course_Number %d : %s ",Course_Number,Student->First_Name);
				DPRINTF("\nLast Name Of Course_Number %d : %s",Course_Number,Student->Last_Name);
				DPRINTF("\nGPA Of Course_Number %d : %f",Course_Number,Student->GPA);
				counter++;
			}
		}
		if((Student+1)==(fifo->base + fifo->length))
			{
				Student = fifo->base;
			}
		else
			{
				Student++;
			}
	}
	if (counter==0)
		DPRINTF("No Student With This Coarse");
		return FIFO_null;

	return FIFO_no_error;

}


FIFO_Buf_Status Count_Students (FIFO_Buf_t* fifo)
{
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;

	DPRINTF("\nThe Number Of Students = %d",fifo->count);
	return FIFO_no_error;
}

FIFO_Buf_Status Update_Students (FIFO_Buf_t* fifo)
{
	Student_t *Student;
	int Roll_Number,x,number_of_coarses,i;
	DPRINTF("\nEnter The Roll Number You Want to Update");
	scanf("%d",&Roll_Number);
	Student = Search_The_Roll_Number(fifo,Roll_Number);
	if (Student==NULL)
	{
		DPRINTF("\nSorry Student Roll Number doesn't exist");
		return FIFO_null;
	}
	else
	{
		DPRINTF("\n*****Enter The choice you want*****");
		DPRINTF("\n1-Update First Name");
		DPRINTF("\n2-Update Last Name");
		DPRINTF("\n3-Update GPA");
		DPRINTF("\n4-Update Coarses\n");
		scanf("%d",&x);
		switch(x)
		{
		case 1:
			DPRINTF("\nEnter The Name you want:");
			scanf("%s",&Student->First_Name);
			break;
		case 2:
			DPRINTF("\nEnter The Name you want:");
			scanf("%s",&Student->Last_Name);
			break;
		case 3:
			DPRINTF("\nEnter GPA you want:");
			scanf("%s",&Student->GPA);
			break;
		case 4:
			DPRINTF("\nEnter Number Of Coarses : ");
			scanf("%d",&number_of_coarses);

			for(i=0;i<number_of_coarses;i++)
			{
			DPRINTF("\nEnter Student Coarse Number %d :  ",i+1);
			scanf("%d",&Student->Courses[i]);
			}
			break;
		}
			DPRINTF("*****Successfully******");
		return FIFO_no_error;
	}
}



FIFO_Buf_Status Show_All_Students(FIFO_Buf_t* fifo)
{
	int i,j;
	Student_t *Student = fifo->tail;
	if(fifo->count==0)
	{
		DPRINTF("\nThe List Is Empty.");
		return FIFO_null;
	}
	for(i=0;i<fifo->count;i++)
	{
		DPRINTF("\nRoll Number : %d",Student->Roll_Number);
		DPRINTF("\nFirst Name : %s",Student->First_Name);
		DPRINTF("\nLast Name : %s",Student->Last_Name);
		DPRINTF("\nGPA : %f",Student->GPA);
		DPRINTF("\nCourses :  ");
		for(j=0;Student->Courses[j]!=NULL;j++)
		{
			DPRINTF("%d ",Student->Courses[j]);
		}


		if((Student+1)==(fifo->base + fifo->length))
			{
				Student = fifo->base;
			}
			else
			{
				Student++;
			}
	}
	return FIFO_no_error;
}




 Student_t* Search_The_Roll_Number(FIFO_Buf_t* fifo, int Number)
{
	int i;
	Student_t *Current_Student=fifo->tail;
	for (i =0 ;i<fifo->count;i++)
	{
		if(Current_Student->Roll_Number==Number)
		{
			return Current_Student;
		}
		if((Current_Student+1)==(fifo->base + fifo->length))
		{
			Current_Student = fifo->base;
		}
		else
		{
			Current_Student++;
		}
	}
		Current_Student=NULL;
		return Current_Student;
}







