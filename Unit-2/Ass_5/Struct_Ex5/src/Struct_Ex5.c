/*
 ============================================================================
 Name        : Struct_Ex5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define pi 3.14
#define Area(r)  (pi*r*r)

void main(void)
{
	int radius;
	float area;
	printf("Enter the radius :");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&radius);
	area=Area(radius);
	printf("Area = %.2f",area);
}
