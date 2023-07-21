/*
 ============================================================================
 Name        : Q6_mid.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int unique (int arr[],int size);
int main(void)
{	int j;
	for (j=0;j<=1;j++)
	{
	int i,arr[100],size;
	printf("please enter size :");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&size);
	fflush(stdin);
	fflush(stdout);

	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}

	printf("the unique number is %d \n",unique(arr,size));

	}
	return 0;
}

int unique (int arr[],int size)
{
	int num=0,i;
	for (i =0;i<size;i++)
	{
		num^=arr[i];
	}
	return num;
}
