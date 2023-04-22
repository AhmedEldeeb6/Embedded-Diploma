/*
 ============================================================================
 Name        : EX2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

long int fact(int num);

void main (void)
{
	int num;
	printf("Enter a positive integer :");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	fflush(stdin);
	fflush(stdout);
	printf("factorial of %d = %ld",num,fact(num));
}

long int fact(int num)
{
	if (num>=1)
	{
	return num*fact(num-1);
	}
	else
		return 1;
}
