/*
 ============================================================================
 Name        : Ex_6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


void main(void)
{
	float num_1,num_2,temp;
	printf("Enter value of num_1 :" );
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&num_1);
	printf("Enter value of num_2 :");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&num_2);
	temp=num_1;
	num_1=num_2;
	num_2=temp;
	printf("After swapping value of num_1= %f \rAfter swapping value of num_2= %f",num_1,num_2 );
	}
