#include <stdio.h>
#include <setjmp.h>

jmp_buf begin;

char curlex;

void getlex(void);
int expr(void);
int add(void);
int mult(void);
void error();

main()
{
	int result;
	setjmp(begin);
	printf("==>");
	getlex();
	result=expr();
	if (curlex != '\n') error();
	printf("\n%d\n",result);
	return 0;
}


void getlex()
{
	while ((curlex=getchar()) == ' ');
}


void error(void)
{
	printf("\nERROR!\n");
	while(getchar()!='\n');
	longjmp(begin,1);
}


int expr()
{
	int e=add();
	while (curlex == '+')
	{ getlex(); e+=add();}
	return e;
}


int add()
{
	int a=mult();
	while (curlex == '*')
	{ getlex(); a*=mult();}
	return a;
}


int mult()
{
	int m;
	switch(curlex)
	{
		case '0': case '1': case '2': case '3': case '4': case '5':
		case '6': case '7': case '8': case '9': m=curlex-'0'; break;
		case '(': getlex(); m=expr(); if (curlex == ')') break;
		default : error();
	}
	getlex();
	return m;
}