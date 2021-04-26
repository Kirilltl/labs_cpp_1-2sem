#include <stdio.h>
#include <stdlib.h>
#include "func.h"
int main()
{
	int	MAX_I = 0;//STR
	int	MAX_J = 0;//STL
	int	window = 0;
	printf("Enter the number of rows and columns accordingly:\n");
	int r = scanf("%d", &MAX_I);
	r = scanf("%d", &MAX_J);
	r = scanf("window: %d", &window);
	if (window >= MAX_J)
	{
		exit(1);
	}
	double* mass = (double*)malloc(MAX_I * MAX_J * sizeof(double));
	for (int i = 0; i < MAX_I; i++)
		for (int j = 0; j < MAX_J; j++)
		{
			printf("mass[%d][%d]=", i, j);
			int r = scanf("%lf", mass + i*MAX_I + j);
		}
	double res = find_disp(MAX_I, MAX_J, mass, window);
	printf("res = %lf \n", res);
	free(mass);
}