/*
 ============================================================================
 Name        : Ex-3.c
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
	int arr[100][100],trans[100][100];
	int cl,rw,i,j;
	printf("please enter number of rows and coloumns :");
	fflush(stdin);
	fflush(stdout);
	scanf("%d%d",&cl,&rw);
	fflush(stdin);
	fflush(stdout);
	printf("Enter elements of Matrix\n");
	//Get Elements
	for(i=0;i<rw;i++)
	{
		for (j=0;j<cl;j++)
		{
			printf("Enter element %d%d  ",i+1,j+1);
			fflush(stdin);
			fflush(stdout);
			scanf(" %d",&arr[i][j]);

		}
	}
	//Display matrix
	printf("\n The matrix is \n");
	for(i=0;i<rw;i++)
	{
		for (j=0;j<cl;j++)
		{
			printf("%d ",arr[i][j]);
			if(j==cl-1)
			{
				printf("\n");
			}


		}
	}

	//Transpose of matrix
	for(i=0;i<rw;i++)
	{
		for (j=0;j<cl;j++)
		{
			trans[j][i]=arr[i][j];
		}

	}

	//Display transpose matrix
	printf("\n The transpose matrix is \n");
	for(i=0;i<cl;i++)
	{
		for (j=0;j<rw;j++)
		{
			printf("%d ",trans[i][j]);
			if(j==rw-1)
			{
				printf("\n");
			}

		}
	}
}
