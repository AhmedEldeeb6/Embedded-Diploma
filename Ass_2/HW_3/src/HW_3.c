/*
 ============================================================================
 Name        : HW_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main (void)
{
	float num_1,num_2,num_3,large;
	printf("please enter 3 numbers \n");
	fflush(stdin);
	fflush(stdout);
	scanf("%f%f%f",&num_1,&num_2,&num_3);
	large=num_1;
	if (num_2>large)
	{
		if(num_3>num_2)
		{
			large=num_3;
		}
		else
		{
			large=num_2;
		}
	}
	printf("the largest number is %f",large);
}
