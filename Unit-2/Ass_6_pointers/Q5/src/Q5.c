/*
 ============================================================================
 Name        : Q5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdlib.h>
#include <stdio.h>
struct employee
{
char *name;
int Id;
};

int main()
{
	struct employee emp1={"Ahmed",1001},emp2={"Alex",1002},emp3={"Eldeeb",1003};
	struct employee(*arr[])={&emp1,&emp2,&emp3};
	struct employee(*(*pt)[3])=&arr;

	printf("Employee Name :%s \n",(*(*pt+1))->name);
	printf("Employee ID :%d\n",(*(*pt+1))->Id);

	return 0;
}

