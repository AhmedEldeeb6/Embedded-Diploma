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
	char string[1000],temp;
	int i=0,j;
	printf("Enter The string you want to be inversed ");
	fflush(stdin);
	fflush(stdout);
	gets(string);
	j=strlen(string)-1;
	while(i<j)
	{
		string[i]=string[i]+string[j];
		string[j]=string[i]-string[j];
		string[i]=string[i]-string[j];
		i++;
		j--;

	}

	printf("the inverse string is %s",string);
}
