/*
 ============================================================================
 Name        : Q2_mid.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

float sqr_root(int num);

int main(void)
{
	int i;
	for(i=0;i<=1;i++)
	{
	int num;
	float square_r;
	printf("Please enter number : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	square_r=sqr_root(num);
	printf("%f\n",square_r);
	}
	return 0;
}

float sqr_root(int num)
{
	float s_r = sqrt(num);
	return s_r;
}
