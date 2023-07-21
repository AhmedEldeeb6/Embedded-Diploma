/*
 ============================================================================
 Name        : Ex-2.c
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
	char string[1000];
	int i,counter=0;
	printf("Enter A string: ");
	fflush(stdin);
	fflush(stdout);
	gets(string);
	for(i=0;string[i]!='\0';i++)
	{
		counter++;
	}
	fflush(stdin);
	fflush(stdout);
	printf("the length of string is %d",counter);
}
