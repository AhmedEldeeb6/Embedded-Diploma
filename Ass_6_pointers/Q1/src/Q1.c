/*
 ============================================================================
 Name        : Q1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int m=29;
	printf("Address of m :%p\nValue of m : %d",&m,m);
	printf("\n\nNow ab is assigned with the adress of m.");
	int *ab;
	ab=&m;
	printf("\nAddress of pointer ab : %p\nContent of pointer ab : %d",ab,*ab);
	printf("\n\nThe value of m is now assigned to 34 ");
	m=34;
	printf("\nAddress of pointer ab : %p\nContent of pointer ab : %d",ab,*ab);
	printf("\n\nThe pointer variable ab is assigned with the value 7 now ");
	*ab=7;
	printf("\nAddress of pointer ab : %p\nContent of pointer ab : %d",ab,*ab);
	return 0;
}
