/*
 ============================================================================
 Name        : Ex-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main(void) {
	int n,i;
	float arr[100],sum=0,average;
	printf("Enter number of elements:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&n);
	while(n<=0)
	{
	printf("Error enter number more than zero ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&n);
	}
	for (i=0;i<n;i++)
	{
		printf("%d . Enter number:",i+1);
		fflush(stdin);
		fflush(stdout);
		scanf("%f",&arr[i]);
		sum+=arr[i];
	}
		average=sum/n;
		printf("Average = %f",average);

}
