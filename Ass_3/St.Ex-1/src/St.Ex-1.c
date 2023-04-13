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
	char string[1000],character;
	int i,counter=0;
	printf("please enter the string ");
	fflush(stdin);
	fflush(stdout);
	gets(string);
	fflush(stdin);
	fflush(stdout);
	printf("please enter the character you want to count  ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&character);
	for(i=0;string[i]!='\0';i++)
	{
		if(character==string[i])
		{
			counter++;
		}
	}
	fflush(stdin);
	fflush(stdout);
	printf("Frequency of %c = %d",character,counter);

}
