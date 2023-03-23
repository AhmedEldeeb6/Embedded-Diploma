/*
 ============================================================================
 Name        : HW_7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int n,i,j,fac=1;
	for (j=0;j<2;j++)
	{
		printf("Enter number: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d", &n);
		if (n>0)
		{
			for (i=1;i<=n;i++)
			{
				fac*=i;
			}
			printf("factorial %d = %d \n",n,fac);
		}
		else
		{
			printf("ERROR!!!!");
		}
	}
}
