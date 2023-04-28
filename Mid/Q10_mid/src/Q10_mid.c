/*
 ============================================================================
 Name        : Q10_mid.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int max_ones (int num);

int main(void)
{
	int i;
	for(i=0;i<=1;i++)
	{
	int num;
	printf("please enter the num : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);

	printf("the max num of ones = %d\n",max_ones(num));
	}
	return 0;
}

int max_ones (int num)
{
	int count=0,max_num=0;

	while (num!=0)
	{
		if (num&1)
		{
			count++;
			if (count>max_num)
			{
				max_num=count;
			}
			else
				{

				}
		}
		else
		{
			count=0;
		}

		num>>=1;
	}
	return max_num;
}

