/*
 ============================================================================
 Name        : Struct_Ex3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct complex
{
	float real;
	float imag;
}comp;

comp add(comp num1,comp num2);
void main(void)
{
	comp n1,n2,sum;
	printf("For 1st complex number\nEnter the real and imaginary respectively :\n");
	fflush(stdin);
	fflush(stdout);
	scanf("%f%f",&n1.real,&n1.imag);
	printf("For 2st complex number\nEnter the real and imaginary respectively :\n");
	fflush(stdin);
	fflush(stdout);
	scanf("%f%f",&n2.real,&n2.imag);
	sum=add(n1,n2);
	printf("Sum=%.1f+%.1fi",sum.real,sum.imag);
}

comp add(comp num1,comp num2)
{
	comp temp;
	temp.real=num1.real+num2.real;
	temp.imag=num1.imag+num2.imag;
	return temp;
}
