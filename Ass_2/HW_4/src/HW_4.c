/*
 ============================================================================
 Name        : HW_4.c
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
	int num,i;

	for(i=0;i<3;i++)
	{
		printf("please enter number \n ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&num);
		if(num>0)
		{
			printf("the number %d is positive \n",num);
		}
		else if(num<0)
		{
			printf("the number %d is negative \n",num);
		}
		else
		{
			printf("the number %d is zero \n",num);
		}
	}
}


