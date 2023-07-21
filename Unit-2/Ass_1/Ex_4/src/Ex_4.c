/*
 ============================================================================
 Name        : Ex_4.c
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
	float num_1,num_2,mul;
	printf("Please Enter 2 Numbers :" );
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f",&num_1,&num_2);
	mul=num_1*num_2;
	printf("Sum = %f",mul);
}
