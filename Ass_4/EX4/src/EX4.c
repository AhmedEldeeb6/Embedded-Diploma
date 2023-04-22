/*
 ============================================================================
 Name        : EX4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int calcpower(int n1, int n2);

void main (void)
{
	int base, power, result;
	printf("Enter base number: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &base);
	fflush(stdin);
	fflush(stdout);
	printf("Enter power number(positive integer): ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &power);
	fflush(stdin);
	fflush(stdout);
	result = calcpower(base, power);
	printf("%d^%d = %d", base, power, result);
}
int calcpower(int base, int power)
{
	if (power != 0)
		return (base * calcpower(base, power - 1));
	else
		return 1;
}
