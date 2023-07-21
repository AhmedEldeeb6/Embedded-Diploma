/*
 ============================================================================
 Name        : Struct_EX2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
struct distance
{
	int feet;
	float inch;
};

void main(void)
{
	struct distance D1,D2,sum;
	printf("Enter information of 1st distance\n");
	printf("Enter Feet : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&D1.feet);
	printf("Enter inch : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&D1.inch);
	printf("Enter information of 2nd distance\n");
	printf("Enter Feet : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&D2.feet);
	printf("Enter inch : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&D2.inch);
	sum.feet=D1.feet+D2.feet;
	sum.inch=D1.inch+D2.inch;

	if(sum.inch>12.0)
	{
		sum.inch-=12.0;
		++sum.feet;
	}
	printf("\nSum of distances=%d\'-%.1f\"",sum.feet,sum.inch);
}
