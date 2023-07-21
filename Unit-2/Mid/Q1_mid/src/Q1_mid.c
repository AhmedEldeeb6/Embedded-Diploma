/*
 ============================================================================
 Name        : Q1_mid.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int sum_dig(int num);

int main()
{
	int num,i;
	for (i=0;i<=1;i++)
	{
	printf("please enter the number : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	fflush(stdin);
	fflush(stdout);
	printf("%d\n",sum_dig(num));
	}
	return 0;

}
int sum_dig(int num)
{
	int sum=0;
	while (num!=0)
	{
		sum+=num%10;
		num/=10;
	}
	return sum;
}
