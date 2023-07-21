/*
 ============================================================================
 Name        : Q3_mid.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void primes_num(int start,int end);
int isPrime (int num);
int main(void)
{
	int start,end;
	printf("please enter the intervals : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d",&start,&end);
	primes_num(start,end);
}

void primes_num(int start,int end)
{
	int i;
	for(i=start+1;i<end;i++)
	{
		if (isPrime(i)==1)
		{
			printf("%d ",i);
		}
	}
}

int isPrime (int num)
{
	int i;
	if (num<2)
	{
		return 0;
	}

	for(i=2;i<=sqrt(num);i++)
	{
		if (num%i==0)
		{
			return 0;
		}
	}
	return 1;
}
