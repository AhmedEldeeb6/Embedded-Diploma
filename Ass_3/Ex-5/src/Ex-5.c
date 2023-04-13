/*
 ============================================================================
 Name        : Ex-5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main(void) {
	int arr[100],num,i,element;
	printf("Enter number of elements ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	//Enter matrix
	printf("Enter elements ");
	fflush(stdin);
	fflush(stdout);
	for(i=0;i<num;i++)
	{
		scanf("%d",&arr[i]);
	}
	//The search number
	fflush(stdin);
	fflush(stdout);
	printf("Enter Element to be searched ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&element);
	//start search
	i=0;
	while(element!=arr[i]&&i<num)
	{
		i++;
	}

	if (i<num)
	{
		printf("The Number is in %d",i+1);
	}
	else
	{
		printf("Number not found");
	}
}
