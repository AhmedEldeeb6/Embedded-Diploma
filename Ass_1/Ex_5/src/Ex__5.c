/*
 ============================================================================
 Name        : Ex__5.c
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
		char Character;
		printf("Enter a character :" );
		fflush(stdin);
		fflush(stdout);
		scanf("%c",&Character);
		printf("ASCII code of %c is %d",Character,Character);
	}
