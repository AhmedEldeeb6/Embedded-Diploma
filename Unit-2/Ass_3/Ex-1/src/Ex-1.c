/*
 ============================================================================
 Name        : Ex-1.c
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
	int a[2][2],b[2][2],c[2][2];
	int i,j;
	printf("Enter the element of the 1st matrix\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
	{
		printf("Enter a%d%d :",i+1,j+1);
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&a[i][j]);
	}
	}

	printf("Enter the element of the 2nd matrix\n");
		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
		{
			printf("Enter b%d%d :",i+1,j+1);
			fflush(stdin);
			fflush(stdout);
			scanf("%d",&b[i][j]);
		}
		}

		for(i=0;i<2;i++)
			{
				for(j=0;j<2;j++)
			{
					c[i][j]=a[i][j]+b[i][j];
			}
			}
		printf("Sum Matrix\n");
		for(i=0;i<2;i++)
			{
				for(j=0;j<2;j++)
			{
				printf("%d\t",c[i][j]);
				if(j==1)
				{
					printf("\n");
				}
			}
			}




}
