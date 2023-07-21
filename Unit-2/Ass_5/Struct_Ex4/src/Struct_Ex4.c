/*
 ============================================================================
 Name        : Struct_Ex4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct student
{
	char name[50];
	int roll;
	float marks;
};

struct student class[10];
void main(void)
{
	int i;
	printf("Enter information of students:\n\n");
	for(i=0;i<10;i++)
	{
		class[i].roll=i+1;
		printf("For roll number %d\nEnter name :",class[i].roll);
		fflush(stdin);
		fflush(stdout);
		scanf("%s",&class[i].name);
		printf("Enter marks : ");
		fflush(stdin);
		fflush(stdout);
		scanf("%f",&class[i].marks);
		printf("\n\n");
	}
	printf("Displaying information of students :\n\n");
	for(i=0;i<10;i++)
	{
		class[i].roll=i+1;
		printf("Information of roll number  %d\nName: %s\nMarks: %f\n ",class[i].roll,class[i].name,class[i].marks);
	}

}

