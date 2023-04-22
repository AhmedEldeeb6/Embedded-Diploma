/*
 ============================================================================
 Name        : EX3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void reverseSentence(void);

void main (void)
{
	printf("Enter a sentence: ");
	fflush(stdin);
	fflush(stdout);
	reverseSentence();
}

void reverseSentence(void)
{
	char character;
	scanf("%c", &character);
	if (character != '\n')
	{
		reverseSentence();
		fflush(stdin);
		fflush(stdout);
		printf("%c", character);
	}
}


