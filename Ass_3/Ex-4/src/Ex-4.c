/*
 ============================================================================
 Name        : Ex-4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main(void) {
		int arr[100],num,elem,loc,i;
		printf("Enter number of elements ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&num);

		printf("Enter elements");
		for(i=0;i<num;i++)
		{
			fflush(stdin);
			fflush(stdout);
			scanf("%d",&arr[i]);
		}
		fflush(stdin);
		fflush(stdout);

		printf("Enter element to be inserted ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&elem);
		printf("Enter location ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&loc);

	for(i=num;i>=loc;i--)
	{
		arr[i]=arr[i-1];
	}

	num++;
	arr[loc-1]=elem;

	for(i=0;i<num;i++)
	{
		fflush(stdin);
		fflush(stdout);
		printf("%d",arr[i]);
	}



}
