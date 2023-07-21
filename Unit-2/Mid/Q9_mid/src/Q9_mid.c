/*
 ============================================================================
 Name        : Q9_mid.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void reverse(char str[]);

int main()
{
	char str[100];
	int len;

	printf("Please Enter String : ");
	fflush(stdin);
	fflush(stdout);
	gets(str);
	reverse(str);
	return 0;
}

void reverse(char str[])
{

	int i,j,start,end,len;
	len = strlen(str);
	end = len - 1;
	for(i = len - 1; i >= 0; i--)
	{
		if(str[i] == ' ' || i == 0)
		{
			if(i == 0)
			{
				start = 0;
			}
			else
			{
				start = i + 1;
			}
			for(j = start; j <= end; j++)
			{
				printf("%c", str[j]);
			}
			end = i - 1;
			printf(" ");
		}
	}
}
