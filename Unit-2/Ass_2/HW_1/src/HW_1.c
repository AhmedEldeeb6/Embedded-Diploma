/*
 ============================================================================
 Name        : HW_1.c
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
	int num;
	printf("please enter the number ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	if(num%2==0)
	{
		printf("the number %d is even ",num);
	}
	else
	{
		printf("the number %d is odd ",num);
	}
}
