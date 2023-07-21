/*
 ============================================================================
 Name        : HW_8.c
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
	int i ;
	char operator;
	float num_1,num_2,result;
	printf("Enter 2 operands ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f",&num_1,&num_2);
	for (i=0;i<4;i++)
	{
	printf("Enter operator ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&operator);

	switch (operator)
	{
	case '*':
		result=num_1*num_2;
		break;

	case '/':
		result=num_1/num_2;
		break;
	case '+':
	result=num_1+num_2;
	break;

	case '-':
	result=num_1-num_2;
	break;
	}
	printf("%f %c %f = %f\n",num_1,operator,num_2,result);
	}
}
