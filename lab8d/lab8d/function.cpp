#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double find_deviation(double MAX_I, double MAX_J, double** mass)
{
	
	/*
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
	*/
	
	double res = 0;
	for (int i = 0; i < MAX_I; i++)
	{
		double sum = 0;
		for (int j = 0; j < MAX_J; j++)
		{
			sum = sum + mass[i][j];
		}
		double xsr = sum / MAX_J;
		double sumkvad = 0;
		for (int j = 0; j < MAX_J; j++) 
			sumkvad = sumkvad + pow(mass[i][j] - xsr, 2);
		double sigma = sqrt(sumkvad / MAX_J);
		if (sigma > res) 
			res = sigma;
		printf("sigma = %lf \n", sigma);
	}
	for (int i = 0; i < MAX_I; i++)
		free(mass[i]);
	free(mass);
	return res;
}