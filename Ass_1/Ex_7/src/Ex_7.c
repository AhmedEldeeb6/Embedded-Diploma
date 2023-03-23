/*
 ============================================================================
 Name        : Ex_7.c
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
	float num_1,num_2;
	printf("Enter value of num_1 :" );
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&num_1);
	printf("Enter value of num_2 :");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&num_2);
	// Swapping
	num_1=num_1+num_2;
	num_2=num_1-num_2;
	num_1=num_1-num_2;
	printf("After swapping value of num_1= %f \nAfter swapping value of num_2= %f",num_1,num_2 );
	}
