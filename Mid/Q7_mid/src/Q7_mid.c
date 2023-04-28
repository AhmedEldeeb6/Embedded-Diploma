/*
 ============================================================================
 Name        : Q7_mid.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sum (int min,int max);

int main(void)
{
	int min=1,max=100;

	printf("sum = %d\n", sum(min,max));

	return 0;


}

int sum (int min,int max)
{
	if (min<=max)
	{
		return min+=sum(min+1,max);
	}
	else return 0;
}
