/*
 ============================================================================
 Name        : HW_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main (void)
{
	char alphapet;
	char vowels[5]={'a','i','o','u','w'};
	int i,k=0;
	printf("enter an alphapet ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&alphapet);
	for(i=0;i<5;i++)
	{
		if (vowels[i]==alphapet)
		{
			k++;
			printf("the \"%c\" is vowel",alphapet);
			break;
		}
	}
	if(k==0)
	{
		printf("the %c is a constant",alphapet);
	}
}
