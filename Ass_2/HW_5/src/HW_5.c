/*
 ============================================================================
 Name        : HW_5.c
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
	int i;
	char character;
	for(i=0;i<2;i++)
	{
		printf("Enter a character: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%c", &character);

		if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))
			printf("%c is an alphabet. \n", character);
		else
			printf("%c is not an alphabet. \n", character);
	}
}
