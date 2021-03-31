#include<stdio.h>
#include<stdlib.h>
#include "func.h"
int main()
{
	int	MAX_I = 0;//STR
	int	MAX_J = 0;//STL
	printf("Enter the number of rows and columns\n");
	int r = scanf("%d", &MAX_I);
	r = scanf("%d", &MAX_J);
	double res = find_deviation( MAX_I,MAX_J);
	printf("res = %lf \n", res);
}