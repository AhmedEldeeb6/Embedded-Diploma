/*
 ============================================================================
 Name        : Q4_mid.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int reverse(int num);
int main(void)
{	int i;
	for(i=0;i<2;i++)
	{
	int num,reversed;
	printf("please enter the number : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	reversed=reverse(num);
	printf("the reversed number is %d\n",reversed);
	}
	return 0;
}

int reverse(int num)
{
	int reversed=0,rem;
	while(num>0)
	{
		rem=num%10;
		reversed = reversed *10+rem;
		num/=10;
	}
	return reversed;
}
