/*
 ============================================================================
 Name        : Q3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("Input string: ");
	char str[20],rev[20];
	fflush(stdin);
	fflush(stdout);
	char *ptr=str;
	char *revptr=rev;
	scanf("%s",&str);
	int i =0;
	while(*ptr)
	{
		ptr++;
		i++;
	}
	while (i>0)
	{
		ptr--;
		*revptr=*ptr;
		revptr++;
		i--;
	}
	*revptr='\0';
	printf("\nReverse string : %s",rev);
	return 0;
}
