/*
 ============================================================================
 Name        : EX1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int prime(int number);
void main(void)
{
	int first,last,i,flag;
	printf("Enter two numbers(intervals) :");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&first);
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&last);
	fflush(stdin);
	fflush(stdout);
	if (first>last)
	{
		first=first+last;
		last=first-last;
		first=first-last;
	}
	for (i = first + 1; i < last; i++)
	{

		flag = prime(i);
		if (flag == 1)
		{
			fflush(stdin);
			fflush(stdout);
			printf("%d ", i);
		}
	}
}

	int prime(int number)
	{
		int j , flag=1;
		for (j = 2; j <= number / 2; ++j)
		{
			if (number % j == 0)
			{
				flag = 0;
				break;
			}
		}
		return flag;
	}
