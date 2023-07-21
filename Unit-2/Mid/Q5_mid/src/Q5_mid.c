/*
 ============================================================================
 Name        : Q5_mid.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int no_of_ones(int num);
int main(void)
{
	int i;
	for(i=0;i<=1;i++)
	{
	int no,num;
	printf("please enter a number :");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	no=no_of_ones(num);
	printf("number of ones equal %d\n",no);
	}
	return 0;
}

int no_of_ones(int num)
{
	int no=0;
	while(num!=0)
	{
		if ((num & 1)==1)
		{
			no+=1;
		}
		num=num>>1;
	}
	return no;
}
