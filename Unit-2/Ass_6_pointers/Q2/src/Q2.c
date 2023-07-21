/*
 ============================================================================
 Name        : Q2.c
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
	int i;
	char *ab;
	*ab='A';
	for (i=0;i<26;i++)
	{
		printf("%c ",*ab);
		*ab=*ab+1;
	}
	return 0;
}
