/*
 ============================================================================
 Name        : Q8_mid.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void reverse (int arr[],int size);
int main(void)
{
	int n,i,arr[100];
	printf("please enter size of array : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	reverse(arr,n);
return 0;

}

void reverse (int arr[],int size)
{
	int i,temp;
	for(i = 0; i<size/2; i++){
		temp = arr[i];
		arr[i] = arr[size-i-1];
		arr[size-i-1] = temp;
	}
	for(int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}
