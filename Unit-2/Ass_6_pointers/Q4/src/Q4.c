/*
 ============================================================================
 Name        : Q4.c
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
	int arr[16],n,i;
	printf("Input the number of elements to store in the array (max15) : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&n);
	if(n<15)
	{
	for(i=0;i<n;i++)
	{
		printf("element- %d : ",i+1);
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&arr[i]);
	}
	int *ptr=arr;
	ptr=ptr+n-1;

	for(i=n-1;i>=0;i--)
	{
		printf("element- %d : %d\n",i+1,*ptr);
		fflush(stdin);
		fflush(stdout);
		ptr--;
	}
	}
	else
	{
		printf("Failed");
	}
	return 0;
}


