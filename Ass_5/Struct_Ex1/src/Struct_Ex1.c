/*
 ============================================================================
 Name        : Struct_Ex1.c
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
	char name[30];
	int roll;
	float marks;
};

void main(void)
{
	struct student class1;
	printf("Enter information of students\n");
	printf("Enter name : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%s",&class1.name);
	printf("Enter roll number : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&class1.roll);
	printf("Enter marks : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&class1.marks);
	printf("Displaying Information\n");
	printf("Name is : %s\n",class1.name);
	printf("Roll number :%d\n",class1.roll);
	printf("Marks: %0.2f\n",class1.marks);
}
