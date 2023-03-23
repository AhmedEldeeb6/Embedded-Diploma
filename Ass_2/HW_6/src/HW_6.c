/*
 ============================================================================
 Name        : HW_6.c
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
    int n,i,sum=0;
    printf("Enter number: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%d", &n);
    for (i=0;i<=n;i++)
    {
    	sum+=i;
    }
    printf("sum = %d",sum);
}
