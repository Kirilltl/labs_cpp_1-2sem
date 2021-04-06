#include<stdio.h>
#include<stdlib.h>
#include "func.h"
int main()
{
	int	MAX_I = 0;//STR
	int	MAX_J = 0;//STL
	printf("Enter the number of rows and columns:\n");
	int r = scanf("%d", &MAX_I);
	r = scanf("%d", &MAX_J);
	
	
	double** mass = NULL;
	mass = (double**)malloc(MAX_I * sizeof(double*));
	for (int i = 0; i < MAX_I; i++)
		mass[i] = (double*)malloc(MAX_J * sizeof(double));
	for (int i = 0; i < MAX_I; i++)
		for (int j = 0; j < MAX_J; j++)
		{
			printf("mass[%d][%d]=", i, j);
			int r = scanf("%lf", &mass[i][j]);
		}
	
	
	double res = find_deviation(MAX_I, MAX_J, mass);
	printf("res = %lf \n", res);
}