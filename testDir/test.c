#include <stdio.h>
/*
 * This file is an example program to show how scanf and EOF works.
 *
 */

/*
int main()
{
	char t[100];
	while(t != EOF)     //THIS IS AN INCORRECT INPUT PROGRAM
	{
		scanf("%s", t);
	}
	printf("cvbnm,");
}
*/
int main()
{
	char t[100];
	while(scanf("%s", t) != EOF) //THIS IS A CORRECT INPUT PROGRAM
	{
		//do some code
		;
	}
	printf("cvbnm,");
}