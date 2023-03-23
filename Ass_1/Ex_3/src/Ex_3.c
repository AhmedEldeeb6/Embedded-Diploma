/*
 ============================================================================
 Name        : Ex_3.c
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
	int num_1,num_2,sum;
	printf("Please Enter 2 Numbers : \n" );
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d",&num_1,&num_2);
	sum=num_1+num_2;
	printf("Sum = %d",sum);
}
